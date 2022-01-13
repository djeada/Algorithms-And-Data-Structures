#include "graph.h"

template <class T>
int aStar(const Graph<T> &graph, Vertex<T> source, Vertex<T> destination,
          double (*heuristic)(T a, T b));
