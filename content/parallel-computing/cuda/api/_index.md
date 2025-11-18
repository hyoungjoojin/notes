+++
title = "api"
+++

# CUDA API

## Synchronization Methods

- `__syncthreads()`: Synchronize all threads in a block
- Atomic Operations: `atomicAdd`, `atomicSub`

### `cudaDeviceSynchronize()`

`cudaDeviceSynchronize()` ensures that all previous device operations are completed before the host continues execution.
This is useful since in CUDA programs, operations are asynchronous by default.
This function can be used for providing synchronization, debugging, or timing features.
