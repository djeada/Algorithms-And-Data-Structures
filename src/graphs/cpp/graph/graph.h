#include <vector>
#include <unordered_map>

enum class Color {WHITE, GRAY, BLACK};

struct Vertex {
	int id;
	Color color;

	Vertex(int _id) : 
		id(_id),
		color(Color::WHITE) {
	}
};

struct Edge {
	Vertex source;
	Vertex destination;
	int distance;

	Edge(Vertex _source, Vertex _destination, int _distance) : 
		source(_source),
		destination(_destination),
		distance(_distance) {
	}
};

class Graph {
	std::unordered_map<Vertex, std::vector<Edge>> adjcDict;
	
public:
	Graph();
	void addEdge(Vertex source, Vertex destination, int distance);
};

