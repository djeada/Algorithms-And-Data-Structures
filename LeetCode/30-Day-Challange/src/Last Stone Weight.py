'''
We have a collection of stones, each stone has a positive integer weight.

Each turn, we choose the two heaviest stones and smash them together.  Suppose the stones have weights x and y with x <= y.  The result of this smash is:

If x == y, both stones are totally destroyed;
If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)
'''

def lastStoneWeight(stones) -> int:
	i = len(stones) - 1
	while len(stones) > 2:
		stones.sort()
		#print(stones)
		if stones[i] == stones[i - 1]:
			del stones[i - 1]
			del stones[i - 1]
			i -= 2
		
		if stones[i - 1] != stones[i]:
			stones[i] -= stones[i - 1] 
			del stones[i - 1]
			i -= 1
	
	if len(stones) == 2:
		return max(stones[0], stones[1]) - min(stones[0], stones[1])
	
	return stones[0]
	

print(lastStoneWeight([1,3]))
