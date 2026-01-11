#include "palindrome.h"

// Helper function to check if substring is palindrome
static bool isPalindrome(const std::string& s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

bool isPalindromeAfterDeletion(const std::string& s) {
    int left = 0;
    int right = static_cast<int>(s.length()) - 1;
    
    while (left < right) {
        if (s[left] != s[right]) {
            // Try deleting either the left or right character
            return isPalindrome(s, left + 1, right) || 
                   isPalindrome(s, left, right - 1);
        }
        left++;
        right--;
    }
    
    // Already a palindrome
    return true;
}
