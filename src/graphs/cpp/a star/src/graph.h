#include <string>
#include <unordered_map>
#include <vector>

struct Point {
  int x;
  int y;

  Point(int _x, int _y);

  bool operator==(const Point &other) const;
  bool operator!=(const Point &other) const;
  bool operator<(const Point &other) const;
};

template <class T> struct Vertex {
  Vertex(T value);
  Vertex(const Vertex<T> &vertex);

  T value;

  bool operator==(const Vertex<T> &other) const;
  bool operator!=(const Vertex<T> &other) const;
  bool operator<(const Vertex<T> &other) const;
};

template <class T> struct HashFunction {
  size_t operator()(const Vertex<T> &vertex) const;
};

template <class T> struct Edge {
  Edge(Vertex<T> source, Vertex<T> destination, int distance);

  Vertex<T> source;
  Vertex<T> destination;
  int distance;

  bool operator==(const Edge<T> &other) const;
  bool operator!=(const Edge<T> &other) const;
  bool operator<(const Edge<T> &other) const;
};

template <class T> class Graph {
  std::unordered_map<Vertex<T>, std::vector<Edge<T>>, HashFunction<T>> adjcDict;

public:
  Graph();
  Graph(std::unordered_map<Vertex<T>, std::vector<Edge<T>>, HashFunction<T>>
            adjcDict);
  void addEdge(Edge<T> edge);
  void addEdge(Vertex<T> source, Vertex<T> destination, int distance);
  void addVertex(Vertex<T> vertex);
  std::vector<Vertex<T>> vertices() const;
  std::vector<Edge<T>> edgesFromVertex(const Vertex<T> vertex) const;
  std::vector<Edge<T>> edges() const;
  bool contains(const Vertex<T> vertex) const;
  bool connected(const Vertex<T> source, const Vertex<T> destination) const;
  bool empty() const;
  unsigned int size() const;
};
