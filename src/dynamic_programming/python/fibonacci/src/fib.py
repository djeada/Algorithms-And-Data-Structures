def fib_basic(n):
    if n <= 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fib_basic(n - 2) + fib_basic(n - 1)


def fib_memo(n, memo=dict()):
    if n < 1:
        return 0
    if n <= 2:
        return 1
    return memo.get(n, fib_memo(n - 1, memo) + fib_memo(n - 2, memo))


def fib_tab(n):
    if n < 1:
        return 0

    if n == 1:
        return 1

    table = [0] * (n + 1)
    table[1] = 1

    for i in range(2, n + 1):
        table[i] = table[i - 1] + table[i - 2]

    return table[n]
