def string_pattern(string, pattern):
    def dfs(string, i, pattern, j, mapping):
        if i == len(string) and j == len(pattern):
            return True
        if i == len(string) or j == len(pattern):
            return False

        curr = pattern[j]
        if curr in mapping:
            s = mapping[curr]
            if string[i : i + len(s)] != s:
                return False
            return dfs(string, i + len(s), pattern, j + 1, mapping)

        for k in range(len(string) - i):
            mapping[curr] = string[i : i + k + 1]
            if dfs(string, i + k + 1, pattern, j + 1, mapping):
                return True
            del mapping[curr]

        return False

    return dfs(string, 0, pattern, 0, {})
