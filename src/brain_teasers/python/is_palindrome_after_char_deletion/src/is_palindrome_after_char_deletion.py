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
    left = 0
    right = len(s) - 1
    deleted = False

    while left < right:
        if s[left] == s[right]:
            left += 1
            right -= 1
        else:
            if deleted:
                return False
            deleted = True
            # Try deleting one of the characters
            if s[left + 1] == s[right]:
                left += 1
            elif s[left] == s[right - 1]:
                right -= 1
            else:
                return False

    return True
