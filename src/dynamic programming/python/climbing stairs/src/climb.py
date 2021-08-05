def climb_basic(n):

    if n < 0:
        return 0

    if n == 0:
        return 1

    return climb_basic(n - 3) + climb_basic(n - 2) + climb_basic(n - 1)


def climb_memo(n, memo=dict()):

    if n < 0:
        return 0

    if n == 0:
        return 1

    if n in memo:
        return memo[n]

    memo[n] = (
        climb_memo(n - 1, memo) + climb_memo(n - 2, memo) + climb_memo(n - 3, memo)
    )
    return memo[n]
