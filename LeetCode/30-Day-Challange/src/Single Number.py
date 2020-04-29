'''
Given a non-empty array of integers, every element appears twice except for one. Find that single one.
'''
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        x = 0
        for i in nums:
            x ^= i
        return x
