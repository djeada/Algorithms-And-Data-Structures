def lcs_basic(a: str, b: str) -> int:
    """
    Find the length of the longest common subsequence using basic recursion.

    Args:
        a: First string.
        b: Second string.

    Returns:
        Length of the longest common subsequence.
    """

    def recursion(a: str, b: str, m: int, n: int) -> int:
        if not m or not n:
            return 0

        if a[m - 1] == b[n - 1]:
            return recursion(a, b, m - 1, n - 1) + 1

        return max(recursion(a, b, m, n - 1), recursion(a, b, m - 1, n))

    return recursion(a, b, len(a), len(b))


def lcs_memo(a: str, b: str) -> int:
    """
    Find the length of the longest common subsequence using memoization.

    Args:
        a: First string.
        b: Second string.

    Returns:
        Length of the longest common subsequence.
    """

    def recursion(a: str, b: str, m: int, n: int, memo: dict) -> int:
        if m == 0 or n == 0:
            return 0

        key = (m, n)

        if key in memo:
            return memo[key]

        if a[m - 1] == b[n - 1]:
            memo[key] = recursion(a, b, m - 1, n - 1, memo) + 1
        else:
            memo[key] = max(
                recursion(a, b, m, n - 1, memo), recursion(a, b, m - 1, n, memo)
            )

        return memo[key]

    return recursion(a, b, len(a), len(b), {})


def lcs_tab(a: str, b: str) -> int:
    """
    Find the length of the longest common subsequence using tabulation.

    Args:
        a: First string.
        b: Second string.

    Returns:
        Length of the longest common subsequence.
    """
    m = len(a)
    n = len(b)

    table = [[0 for _ in range(n + 1)] for _ in range(m + 1)]

    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if a[i - 1] == b[j - 1]:
                table[i][j] = table[i - 1][j - 1] + 1
            else:
                table[i][j] = max(table[i - 1][j], table[i][j - 1])

    return table[m][n]
