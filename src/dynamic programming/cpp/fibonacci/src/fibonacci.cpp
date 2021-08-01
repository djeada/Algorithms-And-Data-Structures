#include "fibonacci.h"
#include <vector>

int fibonacciBasic(int n) {

  if (n <= 0)
    return 0;

  if (n == 1)
    return 1;

  return fibonacciBasic(n - 2) + fibonacciBasic(n - 1);
}

int fibonacciMemo(int n, std::unordered_map<int, int> memo) {

  if (n <= 0)
    return 0;

  if (n == 1)
    return 1;

  if (memo.count(n))
    return memo[n];

  memo[n] = fibonacciMemo(n - 1, memo) + fibonacciMemo(n - 2, memo);

  return memo[n];
}

int fibonacciTable(int n) {

  if (n <= 0)
    return 0;

  if (n == 1)
    return 1;

  std::vector<int> table(n + 1);
  table[1] = 1;

  for (int i = 2; i <= n; i++)
    table[i] = table[i - 1] + table[i - 2];

  return table[n];
}
