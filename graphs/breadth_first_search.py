from data import graph

graph = {
    'a': ['b', 'c'],
    'b': ['d'],
    'c': ['e'],
    'd': ['f'],
    'e': [],
    'f': []
}
def breadth_first_search(graph,source):
    queue = [source]
    while queue:
        current = queue.pop(0)
        print(current)
        for neighbor in graph[current]:
            queue.append(neighbor)

breadth_first_search(graph, 'a')