#include <string>
#include <unordered_map>
#include <vector>

enum class Color { WHITE,
    GRAY,
    BLACK };

struct Vertex {
    Vertex();
    Vertex(int value);
    Vertex(const Vertex& vertex);

    int value;
    Color color;

    bool operator==(const Vertex& other) const;
    bool operator!=(const Vertex& other) const;

    struct HashFunction {
        size_t operator()(const Vertex& vertex) const;
    };
};

struct Edge {
    Edge(Vertex source, Vertex destination, int distance);

    Vertex source;
    Vertex destination;
    int distance;

    bool operator==(const Edge& other) const;
    bool operator<(const Edge& other) const;
};

class Graph {
    std::unordered_map<Vertex, std::vector<Edge>, Vertex::HashFunction> adjcDict;

public:
    Graph();
    void addEdge(Vertex source, Vertex destination, int distance);
    std::vector<Vertex> vertices() const;
    std::vector<Edge> edges(const Vertex vertex) const;
    std::vector<Edge> edges() const;
    bool contains(const Vertex vertex) const;
    std::string toString() const;
    unsigned int size() const;
    bool empty() const;
};
