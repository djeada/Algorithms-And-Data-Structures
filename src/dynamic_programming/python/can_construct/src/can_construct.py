def can_construct_basic(target, word_bank):
    if target == "":
        return True

    for word in word_bank:
        if len(target) >= len(word) and target[: len(word)] == word:
            remainder = target[len(word) :]
            if can_construct_basic(remainder, word_bank):
                return True

    return False


def can_construct_memo(target, word_bank, memo=dict()):
    if target == "":
        return True

    if target in memo:
        return memo[target]

    for word in word_bank:
        if len(target) >= len(word) and target[: len(word)] == word:
            remainder = target[len(word) :]
            if can_construct_memo(remainder, word_bank, memo):
                memo[target] = True
                return memo[target]

    memo[target] = False

    return False


def can_construct_table(target, word_bank):

    table = [False] * (len(target) + 1)
    table[0] = True

    for i in range(len(target)):
        if table[i]:
            for word in word_bank:
                if target[i : i + len(word)] == word:
                    table[i + len(word)] = True

    return table[-1]
