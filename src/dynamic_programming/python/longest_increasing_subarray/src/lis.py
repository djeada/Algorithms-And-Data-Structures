def lis_basic(a, i=None, prev=None):

    if i is None:
        i = 0

    if prev is None:
        prev = float("-inf")

    if i == len(a):
        return 0

    excl = lis_basic(a, i + 1, prev)

    incl = 0
    if a[i] > prev:
        incl = 1 + lis_basic(a, i + 1, a[i])

    return max(incl, excl)


def lis_memo(a, i=None, prev=None, memo=dict()):

    if i is None:
        i = 0

    if prev is None:
        prev = float("-inf")

    if i == len(a):
        return 0

    key = (i, prev, len(a))

    if key in memo:
        return memo[key]

    excl = lis_memo(a, i + 1, prev, memo)

    incl = 0
    if a[i] > prev:
        incl = 1 + lis_memo(a, i + 1, a[i], memo)

    memo[key] = max(incl, excl)
    return max(incl, excl)


def lis_tab(a):

    table = [[] for _ in range(len(a))]

    table[0].append(a[0])

    for i in range(1, len(a)):
        for j in range(i):

            if a[j] < a[i] and len(table[j]) > len(table[i]):
                table[i] = table[j].copy()

        table[i].append(a[i])

    j = 0
    for i in range(len(a)):
        if len(table[j]) < len(table[i]):
            j = i

    return len(table[j])
