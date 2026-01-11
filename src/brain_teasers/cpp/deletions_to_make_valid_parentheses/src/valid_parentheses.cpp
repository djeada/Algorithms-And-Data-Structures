#include "valid_parentheses.h"

int minDeletionsToMakeValid(const std::string& s) {
    int openCount = 0;   // Unmatched opening parentheses
    int deletions = 0;   // Required deletions
    
    for (char c : s) {
        if (c == '(') {
            openCount++;
        } else if (c == ')') {
            if (openCount > 0) {
                // Matched with an opening parenthesis
                openCount--;
            } else {
                // No matching opening parenthesis, must delete this
                deletions++;
            }
        }
    }
    
    // Any remaining unmatched opening parentheses must be deleted
    return deletions + openCount;
}
