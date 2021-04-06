def can_sum(target_sum, numbers):
    if target_sum == 0:
        return True
    for num in numbers:
        remainder = target_sum - num
        if remainder >= 0:
            if can_sum(remainder, numbers):
                return True
    return False

def can_sum(target_sum, numbers):
    memo = {}

    def helper(target_sum, numbers):
        if target_sum == 0:
            return True
        if target_sum in memo:
            return memo[target_sum]
        for num in numbers:
            remainder = target_sum - num
            if remainder >= 0:
                if helper(remainder, numbers):
                    memo[target_sum] = True
                    return True
        memo[target_sum] = False
        return memo[target_sum]

    return helper(target_sum, numbers)

def can_sum(targert_sum, numbers):
    table = [False] * (targert_sum + 1)
    table[0] = True
    for i in range(targert_sum):
        if table[i]:
            numbers = [num for num in numbers if i + num <= targert_sum]
            for num in numbers:
                table[i + num] = True
    return table[-1]
