def can_sum_basic(target, numbers):
    if target == 0:
        return True

    if target < 0:
        return False

    return any(can_sum_basic(target - i, numbers) for i in numbers)


def can_sum_memo(target, numbers, memo=None):
    if memo is None:
        memo = {}

    if target == 0:
        return True

    if target < 0:
        return False

    if target in memo:
        return memo[target]

    can_sum = any(can_sum_memo(target - i, numbers, memo) for i in numbers)
    memo[target] = can_sum

    return can_sum


def can_sum_table(target, numbers):
    table = [False] * (target + 1)
    table[0] = True

    for i in range(target):
        if table[i]:
            for number in [n for n in numbers if i + n <= target]:
                if i + number > 0 and i + number <= target:
                    table[i + number] = True

    return table[-1]
