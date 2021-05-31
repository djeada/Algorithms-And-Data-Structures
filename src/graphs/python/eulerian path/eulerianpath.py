"""
Eulerian path is a trail in a finite graph that visits every edge exactly once. Vertices can be revisited.

There are two algorithms used to construct eulerain paths in graphs:
1. Fleury's algorithm
2. Hierholzer's algorithm
"""

from copy import copy

# BFS
def isConnected(G):
    start_node = list(G)[0]
    color = {v: "white" for v in G}
    color[start_node] = "gray"
    S = [start_node]
    while len(S) != 0:
        u = S.pop()
        for v in G[u]:
            if color[v] == "white":
                color[v] = "gray"
                S.append(v)
            color[u] = "black"

    return list(color.values()).count("black") == len(G)


def from_dict(G):
    return [(u, v) for u in G for v in G[u]]


def fleury(G):
    oddDegreeNodes = [u for u in G if len(G[u]) % 2 != 0]

    if len(oddDegreeNodes) > 2 or len(oddDegreeNodes) == 1:
        return False

    g = copy(G)
    trail = []
    u = oddDegreeNodes[0] if len(oddDegreeNodes) == 2 else list(g)[0]

    while len(from_dict(g)) > 0:
        current_vertex = u
        for u in g[current_vertex]:
            g[current_vertex].remove(u)
            g[u].remove(current_vertex)
            bridge = not isConnected(g)

            if bridge:
                g[current_vertex].append(u)
                g[u].append(current_vertex)

            else:
                break

        if bridge:
            g[current_vertex].remove(u)
            g[u].remove(current_vertex)
            g.pop(current_vertex)

        trail.append((current_vertex, u))

    return trail


G = {0: [2, 2, 3], 1: [2, 2, 3], 2: [0, 0, 1, 1, 3], 3: [0, 1, 2]}
assert not fleury(G)

G = {
    0: [1, 4, 6, 8],
    1: [0, 2, 3, 8],
    2: [1, 3],
    3: [1, 2, 4, 5],
    4: [0, 3],
    5: [3, 6],
    6: [0, 5, 7, 8],
    7: [6, 8],
    8: [0, 1, 6, 7],
}
result = [
    (0, 1),
    (1, 2),
    (2, 3),
    (3, 1),
    (1, 8),
    (8, 0),
    (0, 4),
    (4, 3),
    (3, 5),
    (5, 6),
    (6, 8),
    (8, 7),
    (7, 6),
    (6, 0),
]

assert fleury(G) == result

G = {1: [2, 3, 4, 4], 2: [1, 3, 3, 4], 3: [1, 2, 2, 4], 4: [1, 1, 2, 3]}
result = [(1, 2), (2, 3), (3, 1), (1, 4), (4, 3), (3, 2), (2, 4), (4, 1)]

assert fleury(G) == result

G = {1: [2, 3], 2: [1, 3, 4], 3: [1, 2, 4], 4: [2, 3]}
result = [(2, 1), (1, 3), (3, 2), (2, 4), (4, 3)]

assert fleury(G) == result
