from typing import List, Set, Tuple, Dict, Optional


def generate_words(
    board: List[List[str]], word_dict: Set[str]
) -> Tuple[str, ...]:
    """
    Find all valid words from a board using DFS traversal.

    Starting from each cell, explores all paths through adjacent cells
    (including diagonals) to find words that exist in the word dictionary.

    Args:
        board: 2D grid of characters.
        word_dict: Set of valid words to search for.

    Returns:
        Tuple of all found words that exist in the word dictionary.
    """
    if not board:
        return tuple()

    n, m = len(board), len(board[0])

    def neighbors(x: int, y: int) -> List[Tuple[int, int]]:
        """Generate all valid neighboring positions."""
        result = []
        for dx in (-1, 0, 1):
            for dy in (-1, 0, 1):
                if dx == dy == 0:
                    continue
                if 0 <= x + dx < n and 0 <= y + dy < m:
                    result.append((x + dx, y + dy))
        return result

    def pair_to_key(pair: Tuple[int, int]) -> str:
        """Convert a coordinate pair to a string key."""
        return f"{pair[0]}, {pair[1]}"

    def _generate_words(
        i: int, j: int, word: str, used: Optional[Dict[str, bool]] = None
    ) -> None:
        """DFS implementation to find words."""
        if used is None:
            used = {}

        used[pair_to_key((i, j))] = True
        word += board[i][j]

        if word in word_dict and word not in generated_words:
            generated_words.add(word)

        for x, y in neighbors(i, j):
            key = pair_to_key((x, y))
            if key not in used or not used[key]:
                _generate_words(x, y, word, used)

        used[pair_to_key((i, j))] = False

    generated_words: Set[str] = set()

    for i in range(n):
        for j in range(m):
            _generate_words(i, j, "")

    return tuple(generated_words)
