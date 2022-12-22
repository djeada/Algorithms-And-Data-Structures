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


def find_k_colorable_configurations(G, k):
    def dfs(G, v, colors, configuration):
        if v == G.num_vertices:
            configurations.append(configuration.copy())
            return

        for color in range(k):
            if is_colorable(G, v, color, colors):
                colors[v] = color
                configuration.append(color)
                dfs(G, v + 1, colors, configuration)
                configuration.pop()
                colors[v] = -1

    def is_colorable(G, v, color, colors):
        for u in G.adjacency_dict[v]:
            if colors[u] == color:
                return False
        return True

    configurations = []
    dfs(G, 0, [-1] * G.num_vertices, [])
    return configurations
