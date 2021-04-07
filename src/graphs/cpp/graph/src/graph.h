#include <string>
#include <unordered_map>
#include <vector>

enum class Color { WHITE,
    GRAY,
    BLACK };

struct Vertex {
    Vertex(int value);

    int value;
    Color color;

    bool operator==(const Vertex& other) const;

    struct HashFunction {
        size_t operator()(const Vertex& vertex) const;
    };
};

struct Edge {
    Edge(Vertex _source, Vertex destination, int distance);

    Vertex source;
    Vertex destination;
    int distance;

    bool operator==(const Edge& other) const;
};

class Graph {
    std::unordered_map<Vertex, std::vector<Edge>, Vertex::HashFunction> adjcDict;

public:
    Graph();
    void addEdge(Vertex source, Vertex destination, int distance);
    std::vector<Vertex> vertices();
    std::vector<Edge> edges(const Vertex vertex);
    bool contains(const Vertex vertex);
    std::string toString();
    unsigned int size();
    bool empty();
};
