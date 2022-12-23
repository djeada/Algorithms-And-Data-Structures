def lis_basic(a, i=None, prev=None):
    i = i or 0
    prev = prev or float("inf")
    prev = -prev if prev == float("inf") else prev
    if i == len(a):
        return 0
    excl = lis_basic(a, i + 1, prev)
    incl = 0
    if a[i] > prev:
        incl = 1 + lis_basic(a, i + 1, a[i])
    return max(incl, excl)


def lis_memo(a, i=None, prev=None, memo=dict()):
    i = i or 0
    prev = prev or float("inf")
    prev = -prev if prev == float("inf") else prev
    if i == len(a):
        return 0
    key = f"{i},{prev}"
    if key in memo:
        return memo[key]
    excl = lis_memo(a, i + 1, prev, memo)
    incl = 0
    if a[i] > prev:
        incl = 1 + lis_memo(a, i + 1, a[i], memo)
    memo[key] = max(incl, excl)
    return memo[key]


def lis_tab(a):
    if not a:
        return 0

    table = [1] * len(a)
    for i in range(1, len(a)):
        for j in range(i):
            if a[i] > a[j] and table[i] < table[j] + 1:
                table[i] = table[j] + 1
    return max(table)
