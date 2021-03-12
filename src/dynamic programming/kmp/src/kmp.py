def longest_prefix_suffix(word):
	result = [0]*len(word)
	i = 1
	longest_prefix_suffix = 0 
	while i < len(word): 
		if word[i]== word[longest_prefix_suffix]: 
			longest_prefix_suffix += 1
			result[i] = longest_prefix_suffix
			i += 1
		else: 
			if longest_prefix_suffix != 0: 
				longest_prefix_suffix = result[longest_prefix_suffix-1] 

			else: 
				result[i] = 0
				i += 1

	return result

def search(text, pattern):
	N = len(text)
	M = len(pattern)
	helper = longest_prefix_suffix(pattern)

	i = 0
	j = 0
	
	result = []
		
	while i < N-M+1:
		if text[i] == pattern[j]:
			i += 1
			j += 1
		else:
			if j != 0:
				j = helper[j-1]
			else:
				i +=  1
		if j == M:
			result.append(i-j)
			j = helper[j-1]

	return result

