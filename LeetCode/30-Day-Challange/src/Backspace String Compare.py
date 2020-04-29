'''
Given two strings S and T, return if they are equal when both 
are typed into empty text editors. # means a backspace character.
'''
class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        return cleanString(S) == cleanString(T)

def cleanString(s):
    delCounter = 0
    result = ''
    for i in range(len(s)-1,-1,-1):
        if s[i] == '#':
            delCounter += 1
        else:
            if delCounter:
                delCounter -= 1
            else:
                result += s[i]
    return result
