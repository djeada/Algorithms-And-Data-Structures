'''
Given a binary numsay, find the maximum length of a contiguous subnumsay with equal number of 0 and 1.
'''
class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        n = len(nums)
        histogram = dict()  
        sum = 0 
        maxsize = 0 
        ending_index = -1 
        
        for i in range(n):  
            if(nums[i] == 0):  
                nums[i] = -1
            else:  
                nums[i] = 1
        
        for i in range(n):
            sum += nums[i]  
            
            if (sum == 0):  
                maxsize = i + 1 
                ending_index = i  
            
            if sum in histogram: 
                if maxsize < i - histogram[sum]: 
                    maxsize = i - histogram[sum] 
                    ending_index = i 
            else:  
                histogram[sum] = i   
            
        return maxsize 
