from typing import List, Optional


def count_construct_basic(target: str, word_bank: List[str]) -> int:
    """
    Count the number of ways to construct target from words in word_bank.

    Uses basic recursion without memoization.

    Args:
        target: The target string to construct.
        word_bank: List of words that can be used (can be reused).

    Returns:
        Number of ways to construct target.
    """
    if not target:
        return 1

    count = 0
    for word in word_bank:
        if target.startswith(word):
            count += count_construct_basic(target[len(word) :], word_bank)
    return count


def count_construct_memo(
    target: str, word_bank: List[str], memo: Optional[dict] = None
) -> int:
    """
    Count the number of ways to construct target from words in word_bank.

    Uses memoization for efficient computation.

    Args:
        target: The target string to construct.
        word_bank: List of words that can be used (can be reused).
        memo: Optional dictionary for memoization cache.

    Returns:
        Number of ways to construct target.
    """
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


def count_construct_table(target: str, word_bank: List[str]) -> int:
    """
    Count the number of ways to construct target from words in word_bank.

    Uses tabulation (bottom-up DP) for efficient computation.

    Args:
        target: The target string to construct.
        word_bank: List of words that can be used (can be reused).

    Returns:
        Number of ways to construct target.
    """
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
