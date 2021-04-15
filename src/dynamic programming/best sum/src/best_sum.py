def best_sum_basic(target, numbers):

    if target == 0:
        return []

    shortest_combination = None

    for number in numbers:
        remainder = target - number

        if remainder >= 0:
            combination = best_sum_basic(remainder, numbers)

            if combination is not None:
                combination.append(number)

                if shortest_combination is None or len(combination) < len(
                    shortest_combination
                ):
                    shortest_combination = combination

    return shortest_combination


def best_sum_memo(target, numbers, memo=dict()):

    if target == 0:
        return []

    if target in memo:
        return memo[target]

    shortest_combination = None

    for number in numbers:
        remainder = target - number

        if remainder >= 0:
            combination = best_sum_memo(remainder, numbers, memo)

            if combination is not None:
                combination.append(number)

                if shortest_combination is None or len(combination) < len(
                    shortest_combination
                ):
                    shortest_combination = combination

    return shortest_combination


def best_sum_table(target, numbers):

    table = [None] * (target + 1)
    table[0] = []

    for i in range(target):

        if table[i] is not None:
            numbers = [number for number in numbers if i + number <= target]

            for number in numbers:
                if table[i + number] is None or len(table[i]) < len(table[i + number]):
                    table[i + number] = table[i] + [number]

    return table[-1]
