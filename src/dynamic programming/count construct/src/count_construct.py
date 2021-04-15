def count_construct_basic(target, word_bank):

    if target == "":
        return 1

    totalCount = 0

    for word in word_bank:
        if len(target) >= len(word) and target[: len(word)] == word:
            remainder = target[len(word) :]
            totalCount += count_construct_basic(remainder, word_bank)

    return totalCount


def count_construct_memo(target, word_bank, memo=dict()):

    if target == "":
        return 1

    if target in memo:
        return memo[target]

    totalCount = 0

    for word in word_bank:
        if len(target) >= len(word) and target[: len(word)] == word:
            remainder = target[len(word) :]
            totalCount += count_construct_memo(remainder, word_bank, memo)
    
    memo[target] = totalCount
    return totalCount


def count_construct_table(target, word_bank):

    table = [0] * (len(target) + 1)
    table[0] = 1

    for i in range(len(target)):
        if table[i]:
            for word in word_bank:
                if target[i : i + len(word)] == word:
                    table[i + len(word)] += table[i]

    return table[-1]
