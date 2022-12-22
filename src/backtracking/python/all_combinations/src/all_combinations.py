def all_combinations(n, k):
    def _all_combinations(combination):
        if len(combination) == k:
            result.append(combination)
            return

        for i in range(combination[-1] + 1 if combination else 0, n + 1):
            _all_combinations(combination + [i])

    result = []
    _all_combinations([])
    return result
