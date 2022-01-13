def generate_words(board, word_dict):

    if len(board) < 1:
        return tuple()

    n, m = len(board), len(board[0])
    generated_words = list()

    def _neighbors(x, y):

        result = []

        if y + 1 < n and 0 <= x - 1:
            result.append((x - 1, y + 1))

        if 0 <= y - 1 and 0 <= x - 1:
            result.append((x - 1, y - 1))

        if 0 <= x - 1:
            result.append((x - 1, y))

        if y + 1 < n:
            result.append((x, y + 1))

        if 0 <= y - 1:
            result.append((x, y - 1))

        if y + 1 < n and x + 1 < m:
            result.append((x + 1, y + 1))

        if 0 <= y - 1 and x + 1 < m:
            result.append((x + 1, y - 1))

        if x + 1 < m:
            result.append((x + 1, y))

        return result

    # DFS implementation
    def _generate_words(i, j, word="", used=dict()):

        used[f"{i}, {j}"] = True
        word += board[i][j]

        if word in word_dict and word not in generated_words:
            generated_words.append(word)

        for x, y in _neighbors(i, j):
            key = f"{x}, {y}"
            if key not in used or not used[key]:
                _generate_words(x, y, word, used)

        used[f"{i}, {j}"] = False

    for i in range(n):
        for j in range(m):
            _generate_words(i, j)

    return tuple(generated_words)
