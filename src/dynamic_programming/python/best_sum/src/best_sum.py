def find_shortest_combination_sum_basic(target, numbers):
    def recurse(target):
        if target < 0:
            return float("inf")

        if target == 0:
            return 0

        min_length = float("inf")
        for number in numbers:
            combination_length = recurse(target - number) + 1
            min_length = min(min_length, combination_length)

        return min_length

    min_length = recurse(target)
    if min_length == float("inf"):
        return None

    combination = []
    while target > 0:
        for number in numbers:
            if recurse(target - number) == min_length - 1:
                combination.append(number)
                target -= number
                min_length -= 1
                break

    return combination


def find_shortest_combination_sum_memo(target, numbers):
    def recurse(target, memo):
        if target in memo:
            return memo[target]

        if target < 0:
            return float("inf")

        if target == 0:
            return 0

        min_length = float("inf")
        for number in numbers:
            combination_length = recurse(target - number, memo) + 1
            min_length = min(min_length, combination_length)

        memo[target] = min_length
        return min_length

    min_length = recurse(target, {})
    if min_length == float("inf"):
        return None

    combination = []
    while target > 0:
        for number in numbers:
            if recurse(target - number, {}) == min_length - 1:
                combination.append(number)
                target -= number
                min_length -= 1
                break

    return combination


def find_shortest_combination_sum_table(target, numbers):

    if target < 0:
        return None

    table = [None] * (target + 1)
    table[0] = []

    for i in range(target + 1):
        if table[i] is not None:
            for number in numbers:
                if i + number <= target:
                    if table[i + number] is None or len(table[i]) < len(
                        table[i + number]
                    ):
                        table[i + number] = table[i] + [number]

    return table[-1]
