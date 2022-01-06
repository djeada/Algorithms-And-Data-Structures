def how_sum_basic(target, numbers):

    if target == 0:
        return []

    for number in numbers:
        remainder = target - number

        if remainder >= 0:
            combination = how_sum_basic(remainder, numbers)

            if combination is not None:
                return combination + [number]

    return None


def how_sum_memo(target, numbers, memo=dict()):

    if target == 0:
        return []

    if target in memo:
        return memo[target]

    for number in numbers:

        if number > target:
            return None

        remainder = target - number

        if remainder >= 0:

            combination = how_sum_memo(remainder, numbers, memo)

            if combination is not None:
                memo[target] = combination + [number]
                return memo[target]

    memo[target] = None
    return memo[target]


def how_sum_table(target, numbers):

    table = [None] * (target + 1)
    table[0] = []

    for i in range(target):

        if table[i] is not None:
            numbers = [number for number in numbers if i + number <= target]

            for number in numbers:
                table[i + number] = table[i] + [number]

    return table[-1]
