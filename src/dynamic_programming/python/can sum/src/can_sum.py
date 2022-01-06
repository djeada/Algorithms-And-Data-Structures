def can_sum_basic(target, numbers):

    if target == 0:
        return True

    if target < 0:
        return False

    for i in numbers:
        reminder = target - i
        if can_sum_basic(reminder, numbers):
            return True

    return False


def can_sum_memo(target, numbers, memo=dict()):

    if target == 0:
        return True

    if target < 0:
        return False

    if target in memo:
        return memo[target]

    for i in numbers:
        reminder = target - i
        memo[target] = can_sum_memo(reminder, numbers, memo)
        if memo[target]:
            return True

    return False


def can_sum_table(target, numbers):

    table = [False] * (target + 1)
    table[0] = True

    for i in range(target):
        if table[i]:
            numbers = [number for number in numbers if i + number <= target]
            for number in numbers:
                if i + number > 0 and i + number <= target:
                    table[i + number] = True

    return table[-1]
