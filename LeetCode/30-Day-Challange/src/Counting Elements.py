'''
Given an integer array arr, count element x such that x + 1 is also in arr.

If there're duplicates in arr, count them seperately.
'''
class Solution:
    def countElements(self, arr: List[int]) -> int:
        h = histogram(arr)
        result = 0
        arr.sort()
        n = len(arr)
        i = 0
        while(i < n):
            if arr[i] + 1 in h:
                result += h[arr[i]]
                i += h[arr[i]]
            else:
                i += 1
        return result
        

def histogram(arr):
    h = {}
    for x in arr:
        if x in h:
            h[x] += 1
        else:
            h[x] = 1
    return h

        
