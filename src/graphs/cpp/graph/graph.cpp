#include "graph.h"

Graph::Graph()
{
}

void Graph::addEdge(Vertex source, Vertex destination, int distance) {

	if (adjcDict.contains(source))
		adjcDict[source].emplace_back(Edge(source, destination, distance));
	
	else
		adjcDict[source] = std::vector<Edge>{Edge(source, destination, distance)};
}
