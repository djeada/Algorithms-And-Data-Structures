#include <functional>
#include <unordered_map>
#include <utility>

struct hash {
  template <class T1, class T2>
  std::size_t operator()(const std::pair<T1, T2> &p) const {
    auto h1 = std::hash<T1>{}(p.first);
    auto h2 = std::hash<T2>{}(p.second);

    return h1 ^ h2;
  }
};

int gridTravelersBasic(int n, int m);

int gridTravelersMemo(
    int n, int m, std::unordered_map<std::pair<int, int>, int, hash> memo = {});

int gridTravelersTable(int n, int m);
