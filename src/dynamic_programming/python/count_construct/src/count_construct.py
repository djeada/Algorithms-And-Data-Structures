def count_construct_basic(target, word_bank):
    if not target:
        return 1

    count = 0
    for word in word_bank:
        if target.startswith(word):
            count += count_construct_basic(target[len(word) :], word_bank)
    return count


def count_construct_memo(target, word_bank, memo=None):
    if memo is None:
        memo = {}
    if not target:
        return 1

    if target in memo:
        return memo[target]

    count = 0
    for word in word_bank:
        if target.startswith(word):
            count += count_construct_memo(target[len(word) :], word_bank, memo)
    memo[target] = count
    return count


def count_construct_table(target, word_bank):
    if not target:
        return 1

    n = len(target)
    counts = [0] * (n + 1)
    counts[0] = 1

    for i in range(n):
        if counts[i] == 0:
            continue
        for word in word_bank:
            if target[i : i + len(word)] == word:
                counts[i + len(word)] += counts[i]
    return counts[n]
