def can_construct_basic(target, word_bank):
    if not target:
        return True

    return any(
        len(target) >= len(word)
        and target[: len(word)] == word
        and can_construct_basic(target[len(word) :], word_bank)
        for word in word_bank
    )


def can_construct_memo(target, word_bank, memo=None):
    if memo is None:
        memo = {}

    if not target:
        return True

    if target in memo:
        return memo[target]

    can_construct = any(
        len(target) >= len(word)
        and target[: len(word)] == word
        and can_construct_memo(target[len(word) :], word_bank, memo)
        for word in word_bank
    )
    memo[target] = can_construct

    return can_construct


def can_construct_table(target, word_bank):
    table = [False] * (len(target) + 1)
    table[0] = True

    for i in range(len(target)):
        if table[i]:
            for word in word_bank:
                if target[i : i + len(word)] == word:
                    table[i + len(word)] = True

    return table[-1]
