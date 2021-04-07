#include "graph.h"
#include <iterator>
#include <sstream>

Vertex::Vertex(int _value)
    : value(_value)
    , color(Color::WHITE)
{
}

bool Vertex::operator==(const Vertex& other) const
{
    return value == other.value && color == other.color;
}

size_t Vertex::HashFunction::operator()(const Vertex& vertex) const
{
    return std::hash<int>()(vertex.value) ^ (std::hash<int>()(static_cast<int>(vertex.color)) << 1);
}

Edge::Edge(Vertex _source, Vertex _destination, int _distance)
    : source(_source)
    , destination(_destination)
    , distance(_distance)
{
}

bool Edge::operator==(const Edge& other) const
{
    return source == other.source && destination == other.destination && distance == other.distance;
}

Graph::Graph()
{
}

void Graph::addEdge(Vertex source, Vertex destination, int distance)
{
    if (contains(source))
        adjcDict[source].emplace_back(Edge(source, destination, distance));

    else
        adjcDict[source] = std::vector<Edge>{ Edge(source, destination, distance) };
}

std::vector<Vertex> Graph::vertices()
{
    std::vector<Vertex> keys;

    for (const auto& [key, _] : adjcDict)
        keys.emplace_back(key);

    return keys;
}

std::vector<Edge> Graph::edges(const Vertex vertex)
{
    if (!contains(vertex))
        throw std::invalid_argument("Graph doesn't contain given vertex.");

    return adjcDict[vertex];
}

bool Graph::contains(const Vertex vertex)
{
    return adjcDict.find(vertex) != adjcDict.end();
}

unsigned int Graph::size()
{
    return adjcDict.size();
}
bool Graph::empty()
{
    return adjcDict.empty();
}

std::string Graph::toString()
{
    std::string result;

    for (auto const& [vertex, edges] : adjcDict) {

        std::ostringstream oss;
        for (const auto& edge : edges) {
            oss << std::to_string(edge.destination.value) + ", ";
        }

        auto edgesStr = oss.str();

        if (edgesStr.size() > 1)
            edgesStr.erase(edgesStr.size() - 2);

        result += std::to_string(vertex.value) + " : " + edgesStr + "\n";
    }

    if (result.size() > 1)
        result.erase(result.size() - 1);

    return result;
}
