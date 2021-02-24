#include "bfs.h"

void breadthFirstSearch(Graph graph, Vertex source) {

	source.color = GRAY;

	std::unordered_map<Vertex, int> distances;
	distances[source] = 0;
	
	std::queue<Vertex> visited;
	visited.push(source);

	while (!visited.empty()) {
		auto vertex = visited.front();
		visited.pop();
		
		for (auto& edge : adjDict[u]) {		

			auto& neighbour = edge.destination;

			if (neighbour.color == Color::WHITE) {
				neighbour.color = Color::GRAY;
				distances[neighbour] = distances[vertex] + 1;
				visited.push(neighbour);
			}
		}

		vertex.color = Color::BLACK;
	}
}
