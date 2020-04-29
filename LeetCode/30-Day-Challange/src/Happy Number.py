'''
Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.
'''
class Solution:
    def isHappy(self, n: int) -> bool:
        s = { 1 }

        while n not in s:
            s.add(n)
            n = sum(i * i for i in map(int, str(n)))

        return n == 1
