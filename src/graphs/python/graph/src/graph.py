class Vertex:
    def __init__(self, value):
        self.value = value

    def __eq__(self, other):

        if isinstance(other, Vertex):
            return self.value == other.value

        return False

    def __lt__(self, other):

        if not isinstance(other, Vertex):
            raise NotImplementedError

        return self.value < other.value

    def __repr__(self):
        return str(self.value)

    def __hash__(self):
        return hash(self.value)


class Edge:
    def __init__(self, source, destination, distance):
        self.source = source
        self.destination = destination
        self.distance = distance

    def __eq__(self, other):

        if isinstance(other, Edge):
            return (
                self.source == other.source
                and self.destination == other.destination
                and self.distance == other.distance
            )

        return False

    def __lt__(self, other):

        if not isinstance(other, Edge):
            raise NotImplementedError

        return self.distance < other.distance

    def __repr__(self):
        return f"({self.source}, {self.destination}, {self.distance})"


class Graph:
    def __init__(self):
        self._adj_dict = dict()

    def add_edge(self, edge):

        if edge.source in self._adj_dict:
            self._adj_dict[edge.source].append(edge)

        else:
            self._adj_dict[edge.source] = [edge]

        if edge.destination not in self._adj_dict:
            self._adj_dict[edge.destination] = list()

    def add_vertex(self, vertex):
        if vertex not in self._adj_dict:
            self._adj_dict[vertex] = list()

    def vertices(self):
        return list(self._adj_dict.keys())

    def edges(self):
        return [elem for array in self._adj_dict.values() for elem in array if array]

    def edges_from_vertex(self, vertex):
        self._assert_graph_contains_vertex(vertex)
        return self._adj_dict[vertex]

    def contains(self, vertex):
        return vertex in self._adj_dict

    def connected(self, vertex_a, vertex_b):
        self._assert_graph_contains_vertex(vertex_a)
        self._assert_graph_contains_vertex(vertex_b)

        for edge in self._adj_dict[vertex_a]:
            if edge.destination == vertex_b:
                return True

        for edge in self._adj_dict[vertex_b]:
            if edge.destination == vertex_a:
                return True

        return False

    def empty(self):
        return len(self._adj_dict) == 0

    def size(self):
        return len(self._adj_dict)

    def __repr__(self):

        result = ""
        for vertex, edges in self._adj_dict.items():
            result += f"{vertex} —> "
            for edge in edges:
                result += edge
            result += "\n"

        return result

    def _assert_graph_contains_vertex(self, vertex):
        if vertex not in self._adj_dict:
            raise KeyError(f"Graph doesn't containt the {vertex} vertex!")
