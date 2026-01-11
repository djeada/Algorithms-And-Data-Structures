from typing import Dict


def string_pattern(string: str, pattern: str) -> bool:
    """
    Check if a string matches a pattern using backtracking.

    Each character in the pattern represents a variable that can match
    one or more characters in the string. The same pattern character
    must match the same substring throughout.

    Args:
        string: The string to match against.
        pattern: The pattern to match (each character is a variable).

    Returns:
        True if the string matches the pattern, False otherwise.
    """

    def dfs(
        string: str, i: int, pattern: str, j: int, mapping: Dict[str, str]
    ) -> bool:
        if i == len(string) and j == len(pattern):
            return True
        if i == len(string) or j == len(pattern):
            return False

        curr = pattern[j]
        if curr in mapping:
            s = mapping[curr]
            if string[i : i + len(s)] != s:
                return False
            return dfs(string, i + len(s), pattern, j + 1, mapping)

        for k in range(len(string) - i):
            mapping[curr] = string[i : i + k + 1]
            if dfs(string, i + k + 1, pattern, j + 1, mapping):
                return True
            del mapping[curr]

        return False

    return dfs(string, 0, pattern, 0, {})
