def is_connected(graph):

    if not graph:
        return True #null graph is considered connected

    def dfs(vertex, visited):
        visited.add(vertex)
        for neighbor in graph[vertex]:
            if neighbor not in visited:
                dfs(neighbor, visited)

    start_vertex = next(iter(graph))
    visited = set()
    dfs(start_vertex, visited)

    return len(visited) == len(graph)

graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D'],
    'C': ['A', 'D'],
    'D': ['B', 'C'],
    'E': []  # This node is isolated
}

print(is_connected(graph))
