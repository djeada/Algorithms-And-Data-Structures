class Graph:
    def __init__(self):
        self.num_vertices = 0
        self.adjacency_dict = {}

    def add_edge(self, u, v):
        if u not in self.adjacency_dict:
            self.adjacency_dict[u] = []

        if v not in self.adjacency_dict:
            self.adjacency_dict[v] = []

        self.adjacency_dict[u].append(v)
        self.adjacency_dict[v].append(u)
        if len(self.adjacency_dict) > self.num_vertices:
            self.num_vertices = len(self.adjacency_dict)


def find_hamiltonian_paths(G):
    def dfs(G, v, visited, path):
        # if all the vertices are visited, then the Hamiltonian path exists
        if len(path) == len(G.adjacency_dict):
            # add the Hamiltonian path to the list of paths
            paths.append(path.copy())
            return

        # Check if vertex `v` has any outgoing edges
        if v not in G.adjacency_dict:
            return

        # Check if every edge starting from vertex `v` leads to a solution or not
        for w in G.adjacency_dict[v]:
            # process only unvisited vertices as the Hamiltonian
            # path visit each vertex exactly once
            if not visited[w]:
                visited[w] = True
                path.append(w)

                # check if adding vertex `w` to the path leads to the solution or not
                dfs(G, w, visited, path)

                # backtrack
                visited[w] = False
                path.pop()

    # start with every node
    paths = []
    for start in range(len(G.adjacency_dict)):
        # add starting node to the path
        path = [start]
        # mark the start node as visited
        visited = [False] * len(G.adjacency_dict)
        visited[start] = True
        dfs(G, start, visited, path)
    return paths
