from typing import List


def all_construct_basic(target: str, word_bank: List[str]) -> List[List[str]]:
    """
    Find all ways to construct target from words in word_bank.

    Uses basic recursion without memoization.

    Args:
        target: The target string to construct.
        word_bank: List of words that can be used (can be reused).

    Returns:
        List of all possible combinations of words that construct target.
    """

    def recurse(target: str) -> List[List[str]]:
        if not target:
            return [[]]

        result: List[List[str]] = []
        for word in word_bank:
            if target.startswith(word):
                suffix_ways = recurse(target[len(word) :])
                result.extend([way + [word] for way in suffix_ways])

        return result

    return recurse(target)


def all_construct_memo(target: str, word_bank: List[str]) -> List[List[str]]:
    """
    Find all ways to construct target from words in word_bank.

    Uses memoization for efficient computation.

    Args:
        target: The target string to construct.
        word_bank: List of words that can be used (can be reused).

    Returns:
        List of all possible combinations of words that construct target.
    """

    def recurse(target: str, memo: dict) -> List[List[str]]:
        if not target:
            return [[]]

        if target in memo:
            return memo[target]

        result: List[List[str]] = []
        for word in word_bank:
            if target.startswith(word):
                suffix_ways = recurse(target[len(word) :], memo)
                result.extend([way + [word] for way in suffix_ways])

        memo[target] = result
        return result

    return recurse(target, {})


def all_construct_table(target: str, word_bank: List[str]) -> List[List[str]]:
    """
    Find all ways to construct target from words in word_bank.

    Uses tabulation (bottom-up DP) for efficient computation.

    Args:
        target: The target string to construct.
        word_bank: List of words that can be used (can be reused).

    Returns:
        List of all possible combinations of words that construct target.
    """
    table: List[List[List[str]]] = [[] for _ in range(len(target) + 1)]
    table[0] = [[]]

    for i in range(len(target)):
        for word in word_bank:
            if target[i : i + len(word)] == word:
                new_combinations = [combination + [word] for combination in table[i]]
                table[i + len(word)].extend(new_combinations)

    return table[-1]
