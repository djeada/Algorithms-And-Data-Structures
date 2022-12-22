from collections import defaultdict


class Graph:
    def __init__(self, num_vertices=0):
        self.adjacency_dict = defaultdict(list)
        self.num_vertices = num_vertices

    def add_edge(self, u, v):
        self.adjacency_dict[u].append(v)
        self.num_vertices = max(self.num_vertices, u + 1, v + 1)


def topological_sort(G):
    def dfs(G, v, discovered, departure, time):
        # mark the current node as discovered
        discovered[v] = True

        # set the arrival time of vertex `v`
        time = time + 1

        # do for every edge (v, u)
        for u in G.adjacency_dict[v]:
            # if `u` is not yet discovered
            if not discovered[u]:
                time = dfs(G, u, discovered, departure, time)

        # ready to backtrack
        # set departure time of vertex `v`
        departure[time] = v
        time = time + 1

        return time

    # departure[] stores the vertex number using departure time as an index
    departure = [-1] * 2 * G.num_vertices

    # to keep track of whether a vertex is discovered or not
    discovered = [False] * G.num_vertices
    time = 0

    # perform dfs on all undiscovered vertices
    for v in G.adjacency_dict.copy():
        if not discovered[v]:
            time = dfs(G, v, discovered, departure, time)

    # Iterate over the vertices in order of their decreasing
    # departure time in dfs, i.e., in topological order
    topological_order = []
    for i in reversed(range(2 * G.num_vertices)):
        if departure[i] != -1:
            topological_order.append(departure[i])

    return topological_order
