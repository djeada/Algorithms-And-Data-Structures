def search(text, pattern):
    def find_longest_prefix_suffix(word):
        result = [0] * len(word)
        i = 1
        j = 0
        while i < len(word):
            if word[i] == word[j]:
                j += 1
                result[i] = j
                i += 1
            else:
                if j != 0:
                    j = result[j - 1]
                else:
                    result[i] = 0
                    i += 1
        return result

    longest_prefix_suffix = find_longest_prefix_suffix(pattern)
    result = []
    j = 0
    for i, c in enumerate(text):
        if c == pattern[j]:
            j += 1
        else:
            if j != 0:
                j = longest_prefix_suffix[j - 1]
        if j == len(pattern):
            result.append(i - j + 1)
            j = longest_prefix_suffix[j - 1]
    return result
