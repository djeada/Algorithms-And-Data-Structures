"""Check if a string can become a palindrome after deleting at most one character."""

from __future__ import annotations


def is_palindrome_after_char_deletion(s: str) -> bool:
    """
    Check if a string is a palindrome or can become one by deleting one character.

    Uses two pointers to find mismatches and checks if removing either
    character results in a palindrome.

    Args:
        s: The input string to check.

    Returns:
        True if the string is already a palindrome or can become one
        by deleting at most one character.
    """

    def is_palindrome(left: int, right: int) -> bool:
        while left < right:
            if s[left] != s[right]:
                return False
            left += 1
            right -= 1
        return True

    left = 0
    right = len(s) - 1

    while left < right:
        if s[left] != s[right]:
            # Try deleting either mismatching character
            return is_palindrome(left + 1, right) or is_palindrome(left, right - 1)
        left += 1
        right -= 1

    return True
