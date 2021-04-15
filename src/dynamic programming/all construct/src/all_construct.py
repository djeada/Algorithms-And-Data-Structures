def all_construct_basic(target, word_bank):

    if target == "":
        return [[]]

    result = list()

    for word in word_bank:
        if len(target) >= len(word) and target[: len(word)] == word:
            suffix = target[len(word) :]
            suffix_ways = all_construct_basic(suffix, word_bank)
            target_ways = [way + [word] for way in suffix_ways]

            if target_ways:
                result.extend(target_ways)

    return result


def all_construct_memo(target, word_bank, memo=dict()):

    if target == "":
        return [[]]

    if target in memo:
        return memo[target]

    result = list()

    for word in word_bank:
        if len(target) >= len(word) and target[: len(word)] == word:
            suffix = target[len(word) :]
            suffix_ways = all_construct_memo(suffix, word_bank, memo)
            target_ways = [way + [word] for way in suffix_ways]

            if target_ways:
                result.extend(target_ways)

    memo[target] = result
    return result


def all_construct_table(target, word_bank):

    table = [[] for _ in range(len(target) + 1)]
    table[0] = [[]]

    for i in range(len(target)):
        for word in word_bank:
            if target[i : i + len(word)] == word:
                new_combinations = [combination + [word] for combination in table[i]]
                table[i + len(word)].extend(new_combinations)

    return table[-1]
