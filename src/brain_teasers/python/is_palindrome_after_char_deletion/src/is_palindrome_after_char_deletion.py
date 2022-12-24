def is_palindrome_after_char_deletion(s: str) -> bool:
    # Initialize two pointers, one at the beginning and one at the end of the string
    left = 0
    right = len(s) - 1
    # Flag to track whether a deletion has been made
    deleted = False
    # Loop through the string until the pointers meet in the middle
    while left < right:
        # If the characters at the current pointers are the same, move both pointers inward
        if s[left] == s[right]:
            left += 1
            right -= 1
        # If the characters are different, we may need to delete one of them
        else:
            # If we have already made a deletion, return False since we can't make the string a palindrome
            if deleted:
                return False
            # Otherwise, set the deleted flag to True and try deleting one of the characters
            deleted = True
            # If deleting the character at the left pointer creates a palindrome, move the left pointer inward
            if s[left + 1] == s[right]:
                left += 1
            # If deleting the character at the right pointer creates a palindrome, move the right pointer inward
            elif s[left] == s[right - 1]:
                right -= 1
            # If deleting either character does not create a palindrome, return False
            else:
                return False
    # If we've made it through the loop, the string is a palindrome after at most one deletion
    return True
