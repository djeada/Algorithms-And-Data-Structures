#include <unordered_map>

int fibonacciBasic(int n);

int fibonacciMemo(int n, std::unordered_map<int, int> memo = {});

int fibonacciTable(int n);
