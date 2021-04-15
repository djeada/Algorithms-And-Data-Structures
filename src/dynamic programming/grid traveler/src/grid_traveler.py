def grid_traveller_basic(n, m):

    if n == 0 or m == 0:
        return 0

    if n < 2 and m < 2:
        return min(n, m)

    return grid_traveller_basic(n - 1, m) + grid_traveller_basic(n, m - 1)


def grid_traveller_memo(n, m, memo=dict()):

    if n == 0 or m == 0:
        return 0

    if n < 2 and m < 2:
        return min(n, m)

    key = f"{n}{m}"

    if key in memo:
        return memo[key]

    memo[key] = grid_traveller_memo(n - 1, m, memo) + grid_traveller_memo(
        n, m - 1, memo
    )

    return memo[key]


def grid_traveller_table(n, m):

    table = [[0 for x in range(n + 1)] for x in range(m + 1)]

    table[1][1] = 1

    for i in range(1, m + 1):
        for j in range(1, n + 1):
            cur = table[i][j]

            if i < m:
                table[i + 1][j] += cur

            if j < n:
                table[i][j + 1] += cur

    return table[m][n]
