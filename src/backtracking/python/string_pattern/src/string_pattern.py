def string_pattern(string, pattern):
    def _string_pattern(string, i, pattern, j, mapping=dict()):

        n = len(string)
        m = len(pattern)

        if n < m:
            return False

        if i == n and j == m:
            return True

        if i == n or j == m:
            return False

        curr = pattern[j]

        if curr in mapping:

            s = mapping[curr]
            k = len(s)

            substring = string[i:]

            if i + k < n:
                substring = string[i : i + k]

            if substring != s:
                return False

            return _string_pattern(string, i + k, pattern, j + 1, mapping)

        for k in range(n - i):

            mapping[curr] = string[i : i + k + 1]

            if _string_pattern(string, i + k + 1, pattern, j + 1, mapping):
                return True

            del mapping[curr]

        return False

    return _string_pattern(string, 0, pattern, 0)
