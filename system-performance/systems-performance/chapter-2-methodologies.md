# Chapter 2: Methodologies

## Concepts

### Metrics

- Performance metrics can be used to measure system statistics, but they are not free in that they introduce overhead (observer effect) and metrics may be unreliable and inaccurate.
- Types of metrics
    - Latency: Time spent waiting before an operation is serviced. This does not include the time the operation itself took, this is the operation time. The response time is the sum of the latency and operation time. In some contexts, latency might be referring to the response time.
    - Utilization
        - Time-based Utilization: The amount of time the component was busy doing some task.
        - Capacity-based Utilization: How much of a component’s resource is working relative to its full capacity.
    - IOPS: I/O operations per second.
    - Throughput: Amount of operations per second.
- Time Scales
    
    
    | Event | Latency |
    | --- | --- |
    | 1 CPU Cycle | 0.1 nanoseconds |
    | L1 Cache Access | 1 nanosecond |
    | L3 Cache Access | 10 nanoseconds |
    | Main Memory Access | 100 nanoseconds |
    | Solid State Drive I/O | 10 microseconds |
    | Hard Disk Drive I/O | 1 milliseconds |
    | Internet Connection | 100 milliseconds |

### Performance Trade-Offs

- Trade-offs exist between performance, release time, and cost.
- How much is appropriate to invest for performance analysis depends on the return on investment (ROI), expected users of the product, release schedule and so on.
- Indications of when to stop performance analysis
    - When the issues found solve the bulk of a given performance problem.
    - When the ROI is less than the cost of analysis.
    - When there are other places to invest on that have bigger ROIs.

### Other Terminology

- Scalability: How the performance of a system changes under increasing load.
- Saturation: How much more work is requested than for what a fully utilized system can process.
- Profiling: Building a picture of the target system, typically done by sampling the state of the system at timed intervals.