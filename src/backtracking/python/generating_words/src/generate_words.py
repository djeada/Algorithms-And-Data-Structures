def generate_words(board, word_dict):
    if not board:
        return tuple()

    def neighbors(x, y):
        for dx in (-1, 0, 1):
            for dy in (-1, 0, 1):
                if dx == dy == 0:
                    continue
                if 0 <= x + dx < n and 0 <= y + dy < m:
                    yield x + dx, y + dy

    def pair_to_key(pair):
        return f"{pair[0]}, {pair[1]}"

    # DFS implementation
    def generate_words(i, j, word="", used=dict()):
        used[pair_to_key((i, j))] = True
        word += board[i][j]

        if word in word_dict and word not in generated_words:
            generated_words.add(word)

        for x, y in neighbors(i, j):
            key = pair_to_key((x, y))
            if key not in used or not used[key]:
                generate_words(x, y, word, used)

        used[pair_to_key((i, j))] = False

    generated_words = set()
    n, m = len(board), len(board[0])

    for i in range(n):
        for j in range(m):
            generate_words(i, j)

    return tuple(generated_words)
