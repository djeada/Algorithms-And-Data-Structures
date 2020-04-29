'''
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
'''
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        result = nums[0];
        sum = nums[0];
        
        for i in range(1, len(nums)):
            sum = max(nums[i], sum + nums[i]);
            result = max(result, sum);
        
        return result;
