+++
title = "cuda"
+++

# CUDA

## CUDA Programming Abstraction

A CUDA kernel is a function that is executed on the GPU in parallel by multiple threads in a SPMD-style method.

A CUDA thread is a logical thread of control that runs a kernel, but the implementation of a CUDA thread is defined by Nvidia.

A CUDA program consists of a hierarchy of threads.
A grid is composed of multiple thread blocks, and each thread block is composed of multiple threads.
Each thread block and thread has its own ID that can be used within an executing kernel.

A kernel can be launched with a grid of thread blocks, which can be 1D, 2D, or 3D.
2D or 3D thread blocks are used for cases like image processing or matrix operations since the block ID can be used to
index into the data structure.

The CUDA program has a clear separation of host and device code, where the host code runs serially on the CPU and
the device code does SPMD execution on the GPU.
The host and device have separate memory spaces, therefore dereferencing a host code pointer in device code is illegal
and we need special API calls to copy data between host and device memory.
Here, the memory copy operations is essentially a message passing operation between the CPU and GPU and since its a slow
operations, we want to use optimizations with asynchronous memory copies.

```c++
const int x = 12;
const int y = 6;

dim3 threadsPerBlock(4, 3);
dim3 numBlocks((x + threadsPerBlock.x - 1) / threadsPerBlock.x,
               (y + threadsPerBlock.y - 1) / threadsPerBlock.y);
);

matrixAdd<<<numBlocks, threadsPerBlock>>>(A, B, C);
```

```c
__device__ float doubleValue(float val) { return 2 * val; }

__global__ void matrixAdd(float A[x][y], float B[x][y], float C[x][y]) {
  int i = blockIdx.x * blockDim.x + threadIdx.x;
  int j = blockIdx.y * blockDim.y + threadIdx.y;

  if (i < x && j < y) {
    C[j][i] = doubleValue(A[j][i]) + doubleValue(B[j][i]);
  }
}
```

The device memory is also hierarchical.
All thread blocks have access to device global memory.
Each thread block has shared memory that is shared among all threads in the block.
Each thread has its own private local memory.
The more local the memory is, the faster it is to access.

```c++
float *A = new float[N];
for (int i = 0; i < N; i++)
  A[i] = (float)i;

int bytes = sizeof(float) * N;

float *deviceA;
cudaMalloc(&deviceA, bytes);
cudaMemcpy(deviceA, A, bytes, cudaMemcpyHostToDevice);
```

```c
__global__ void convolve(int N, float *input, float *output) {
  int index = blockIdx.x * blockDim.x + threadIdx.x;
  float result = 0.0f;
  for (int i = 0; i < 3; i++) {
    result += input[index + i];
  }
  output[index] = result / 3.0f;
}

__global__void convolveWithSharedMemory(int N, float *input, float *output) {
  __shared__ float sharedInput[BLOCK_SIZE + 2];
  int index = blockIdx.x * blockDim.x + threadIdx.x;

  sharedInput[threadIdx.x] = input[index];
  if (threadId.x < 2) {
    sharedInput[BLOCK_SIZE + threadIdx.x] = input[index + BLOCK_SIZE];
  }

  __syncthreads();
  float result = 0.0f;
  for (int i = 0; i < 3; i++) {
    result += sharedInput[threadIdx.x + i];
  }
  output[index] = result / 3.0f;
```

### Synchronization Constructs

- `__syncthreads()`: Synchronize all threads in a block
- Atomic Operations: `atomicAdd`, `atomicSub`
- Host/Device Synchronization: `cudaDeviceSynchronize()`

## CUDA Implementation Details

The thread blocks will be created no matter how many are requested, and actually running the threads are scheduled to
cores by the thread block scheduler, which is a hardware component in the GPU.
The thread block scheduler will respect the resource requirements of each block.

A CUDA-capable GPU consists of multiple streaming multiprocessors (SMs), which are the cores that execute CUDA threads.
Each SM has multiple sub-cores (or CUDA cores), which are the execution units that execute individual CUDA threads.
A sub-core has one fetch/decode unit and multiple execution units like ALUs or load/store units.
A sub-core will also have a warp selector tied to the fetch/decode unit, which selects which warp to give instructions to.
The sub-core also contains multiple thread execution contexts.
Each thread execution context contains the program counter (PC) and register state of a thread.
The registers are scalar registers, but a group of execution contexts can be grouped together to form a warp.

Each warp acts as a single SIMD unit, where all threads process an instruction only if they are in the same PC.
This is how SIMD execution is different on GPUs compared to CPUs.
CPU SIMD execution is done with vector registers and compiler-generated vector instructions.
GPU SIMD execution is implicit, where the hardware groups multiple scalar threads into warps.
Nvidia calls this SIMT (single instruction multiple threads).
The warp will suffer from divergent execution if the threads do not share the same instruction (like in an if-else branch).

CUDA will not allow allocating more threads in a block than each core (SM) can handle.
For example, if the SM has 4 sub-cores with each sub-core having 32 thread contexts, then the maximum number of threads per
block is 128.
