from data import graph


def iterative_depth_first_search(graph, source):
    stack = [source]
    while stack:
        current =  stack.pop()
        print(current)
        for neighbor in graph[current]:
            stack.append(neighbor)

def recursive_depth_first_search(graph, source):
    print(source)
    # notice that this recursive function has no explicit base case. 
    # When there are no neighbors for a node we simply have nothing to iterate over so that is essentially our base case

    for neighbor in graph[source]:
        recursive_depth_first_search(graph, neighbor)

recursive_depth_first_search(graph, 'a')