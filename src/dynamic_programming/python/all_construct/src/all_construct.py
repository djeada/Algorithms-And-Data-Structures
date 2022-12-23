def all_construct_basic(target, word_bank):
    def recurse(target):
        if not target:
            return [[]]

        result = []
        for word in word_bank:
            if target.startswith(word):
                suffix_ways = recurse(target[len(word) :])
                result.extend([way + [word] for way in suffix_ways])

        return result

    return recurse(target)


def all_construct_memo(target, word_bank):
    def recurse(target, memo):
        if not target:
            return [[]]

        if target in memo:
            return memo[target]

        result = []
        for word in word_bank:
            if target.startswith(word):
                suffix_ways = recurse(target[len(word) :], memo)
                result.extend([way + [word] for way in suffix_ways])

        memo[target] = result
        return result

    return recurse(target, {})


def all_construct_table(target, word_bank):
    table = [[] for _ in range(len(target) + 1)]
    table[0] = [[]]

    for i in range(len(target)):
        for word in word_bank:
            if target[i : i + len(word)] == word:
                new_combinations = [combination + [word] for combination in table[i]]
                table[i + len(word)].extend(new_combinations)

    return table[-1]
