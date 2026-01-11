from typing import List, Optional


def coin_change_basic(amount: int, coins: List[int]) -> float:
    """
    Find the minimum number of coins needed to make up the given amount using basic recursion.

    Args:
        amount: The target amount.
        coins: List of coin denominations.

    Returns:
        Minimum number of coins needed, or float('inf') if impossible.
    """
    if amount < 0:
        return float("inf")
    if amount == 0:
        return 0
    min_coins = float("inf")
    for coin in coins:
        num_coins = coin_change_basic(amount - coin, coins) + 1
        min_coins = min(min_coins, num_coins)
    return min_coins


def coin_change_memo(
    amount: int, coins: List[int], memo: Optional[dict] = None
) -> float:
    """
    Find the minimum number of coins needed to make up the given amount using memoization.

    Args:
        amount: The target amount.
        coins: List of coin denominations.
        memo: Optional dictionary for memoization cache.

    Returns:
        Minimum number of coins needed, or float('inf') if impossible.
    """
    if memo is None:
        memo = {}

    if amount < 0:
        return float("inf")
    if amount == 0:
        return 0
    if amount in memo:
        return memo[amount]

    min_coins = float("inf")
    for coin in coins:
        num_coins = coin_change_memo(amount - coin, coins, memo) + 1
        min_coins = min(min_coins, num_coins)

    memo[amount] = min_coins
    return memo[amount]


def coin_change_tab(amount: int, coins: List[int]) -> float:
    """
    Find the minimum number of coins needed to make up the given amount using tabulation.

    Args:
        amount: The target amount.
        coins: List of coin denominations.

    Returns:
        Minimum number of coins needed, or float('inf') if impossible.
    """
    table = [float("inf")] * (amount + 1)
    table[0] = 0
    for i in range(amount + 1):
        for coin in coins:
            if i >= coin:
                table[i] = min(table[i], table[i - coin] + 1)
    return table[amount]
