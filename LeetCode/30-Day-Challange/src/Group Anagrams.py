'''
Given an array of strings, group anagrams together.
'''
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        m  = {}
        for s in strs:
            sorted = [c for c in s]
            sorted.sort()
            sorted = tuple(sorted)
            l = [s]
            if sorted in m:
                if m[sorted]:
                    m[sorted] = m[sorted] + l
                else:
                    m[sorted] = l;
            else:
                m[sorted] = l;   

        return [x for x in m.values()]

        
