+++
title = "dijkstra"
+++

# Dijkstra's Algorithm

Dijkstra's algorithm is an algorithm for solving the single-source shortest paths problem on a
weighted graph with non-negative weights.

## Algorithm

Given a weighted graph $G = (V, E)$ and a starting vertex $v_s$, we do the following steps.

1. Initialize an array $d$ of size $\|V\|$ with $\infty$, where $d$ represents the shortest path
   from the starting vertex $v_s$. Also set $d_s$ to be 0.
2. Initialize a boolean array $u$ of size $\|V\|$ with $\text{false}$, where $u_v$ represents if the
   vertex $v$ is visited or not.
3. For $\|V\|$ iterations, do the following.
   1. A vertex $v$ is selected, where $u_v = \text{false}$ and $d_v$ is the minimum value of $d$.
   2. Set $u_v$ to be true.
   3. For all adjacent vertices of $v$, do the following.
      a. Let $t$ be the adjacent vertex of $v$ and $w$ be the weight of the edge $(v, t)$.
      b. $d_t = \min{d_t, d_v + w}$.

If we need to restore the shortest path to each vertex, we can maintain an additional array $p$ where
the predecessor of an element is stored. This value will be updated as $p_t = v$ at step 3-3-b if
$d_t$ gets updated. Restoring the path means following the predecessors until reaching $v_s$.

## Implementation

Dijkstra's algorithm requires finding the minimum value of $d$ for $\|V\|$ iterations. If we simply
traverse the array to find the minimum, the time complexity will be $O(\|V\|^2 + \|E\|)$. Using
different data structures can lead to more a efficient time complexity.

### Dijkstra's Algorithm with Priority Queues

Since $d$ is initialized to be $\infty$, $d_x$ can be selected only if they are visited at least once.
Using this property, we can use a priority queue to select the minimum value from $d$ by pushing
elements in the priority queue if their value gets updated.

In this case, duplicate vertices can show up and therefore additional logic has to be included
to skip these values. Since selecting a vertex $v$ means $d_v$ will no longer be updated, we
can compare $d_v$ to the value in the priority queue and ignore values that are different.

```c++
using Graph = std::vector<std::vector<std::pair<int, int>>>;

void dijkstra(Graph& graph, int start) {
    std::vector<int> d(graph.size(), INF);

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    d[start] = 0;
    pq.push({s, 0});

    while(!pq.empty()) {
        auto [v, d_v] = pq.top();
        pq.pop();

        if(d_v != d[v]) {
            continue;
        }

        for(auto& [t, w] : graph[v]) {
            if(d_v + w < d[t]) {
                d[t] = d[v] + w;
                pq.push({t, d[t]});
            }
        }
    }
}
```
