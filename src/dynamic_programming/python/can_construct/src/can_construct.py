from typing import List, Optional


def can_construct_basic(target: str, word_bank: List[str]) -> bool:
    """
    Determine if target string can be constructed from words in word_bank.

    Uses basic recursion without memoization.

    Args:
        target: The target string to construct.
        word_bank: List of words that can be used (can be reused).

    Returns:
        True if target can be constructed, False otherwise.
    """
    if not target:
        return True

    return any(
        len(target) >= len(word)
        and target[: len(word)] == word
        and can_construct_basic(target[len(word) :], word_bank)
        for word in word_bank
    )


def can_construct_memo(
    target: str, word_bank: List[str], memo: Optional[dict] = None
) -> bool:
    """
    Determine if target string can be constructed from words in word_bank.

    Uses memoization for efficient computation.

    Args:
        target: The target string to construct.
        word_bank: List of words that can be used (can be reused).
        memo: Optional dictionary for memoization cache.

    Returns:
        True if target can be constructed, False otherwise.
    """
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


def can_construct_table(target: str, word_bank: List[str]) -> bool:
    """
    Determine if target string can be constructed from words in word_bank.

    Uses tabulation (bottom-up DP) for efficient computation.

    Args:
        target: The target string to construct.
        word_bank: List of words that can be used (can be reused).

    Returns:
        True if target can be constructed, False otherwise.
    """
    table = [False] * (len(target) + 1)
    table[0] = True

    for i in range(len(target)):
        if table[i]:
            for word in word_bank:
                if target[i : i + len(word)] == word:
                    table[i + len(word)] = True

    return table[-1]
