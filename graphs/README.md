# Graphs
1. A graph consists of nodes (vertices) and edges
2. A graph may be directed or undirected
3. We can represent a graph using an adjacency list:
```python
graph = {
    a: ['b','c'],
    b: ['d'],
    c: ['e'],
    d: ['f'],
    e: [],
    f: []
}
```
The code above represents the following
a - c
|   |
b   e
|
d -> f

## Depth First Search
1. With depth first search, we pick a source node and a direction.
2. Follow that direction until we can't go that direction anymore
3. Pick another direction
4. Repeat from step 2

- Implemented using a stack


## Breadth First Search
1. With breadth first search, we pick a source node.
2. We then follow every edge that source node has and target it's neighbors
3. Repeat from step 1 with a neighbor node

- Implemented using a queue
