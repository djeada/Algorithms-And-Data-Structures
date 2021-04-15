def lcs_basic(a, b, m=None, n=None):

    if m == None:
        m = len(a)

    if n == None:
        n = len(b)

    if m == 0 or n == 0:
        return 0

    if a[m - 1] == b[n - 1]:
        return lcs_basic(a, b, m - 1, n - 1) + 1

    return max(lcs_basic(a, b, m, n - 1), lcs_basic(a, b, m - 1, n))


def lcs_memo(a, b, m=None, n=None, memo=dict()):

    if m == None:
        m = len(a)

    if n == None:
        n = len(b)

    if m == 0 or n == 0:
        return 0

    key = (m, n)

    if key in memo:
        return memo[key]

    if a[m - 1] == b[n - 1]:
        memo[key] = lcs_memo(a, b, m - 1, n - 1, memo) + 1

    else:
        memo[key] = max(lcs_memo(a, b, m, n - 1, memo), lcs_memo(a, b, m - 1, n, memo))

    return memo[key]


def lcs_tab(a, b):
    m = len(a)
    n = len(b)

    table = [[0 for x in range(n + 1)] for y in range(m + 1)]

    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if a[i - 1] == b[j - 1]:
                table[i][j] = table[i - 1][j - 1] + 1
            else:
                table[i][j] = max(table[i - 1][j], table[i][j - 1])

    return table[m][n]
