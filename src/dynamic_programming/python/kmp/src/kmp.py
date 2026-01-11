from typing import List


def search(text: str, pattern: str) -> List[int]:
    """
    Search for all occurrences of pattern in text using KMP algorithm.

    The Knuth-Morris-Pratt algorithm uses a failure function to avoid
    redundant comparisons when searching for a pattern in text.

    Args:
        text: The text to search in.
        pattern: The pattern to search for.

    Returns:
        List of starting indices where pattern is found in text.
    """

    def find_longest_prefix_suffix(word: str) -> List[int]:
        """Compute the longest proper prefix which is also a suffix."""
        result = [0] * len(word)
        i = 1
        j = 0
        while i < len(word):
            if word[i] == word[j]:
                j += 1
                result[i] = j
                i += 1
            else:
                if j != 0:
                    j = result[j - 1]
                else:
                    result[i] = 0
                    i += 1
        return result

    longest_prefix_suffix = find_longest_prefix_suffix(pattern)
    result: List[int] = []
    j = 0
    for i, c in enumerate(text):
        if c == pattern[j]:
            j += 1
        else:
            if j != 0:
                j = longest_prefix_suffix[j - 1]
        if j == len(pattern):
            result.append(i - j + 1)
            j = longest_prefix_suffix[j - 1]
    return result
