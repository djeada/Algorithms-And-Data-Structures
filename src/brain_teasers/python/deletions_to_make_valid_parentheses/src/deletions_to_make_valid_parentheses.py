"""Count minimum deletions to make parentheses valid."""

from __future__ import annotations


def deletions_to_make_valid_parentheses(s: str) -> int:
    """
    Return the minimum number of parentheses to delete to make the string valid.

    A string is valid if every opening parenthesis has a matching closing one.

    Args:
        s: A string containing parentheses and potentially other characters.

    Returns:
        The minimum number of deletions needed.
    """
    stack: list[str] = []
    deletions = 0

    for c in s:
        if c == "(":
            stack.append(c)
        elif c == ")":
            if not stack:
                deletions += 1
            else:
                stack.pop()

    # Any remaining opening parentheses must be deleted
    deletions += len(stack)
    return deletions
