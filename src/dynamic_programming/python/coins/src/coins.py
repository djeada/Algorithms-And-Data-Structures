def coin_change_basic(amount, coins):
    if amount < 0:
        return float("inf")
    if amount == 0:
        return 0
    min_coins = float("inf")
    for coin in coins:
        num_coins = coin_change_basic(amount - coin, coins) + 1
        min_coins = min(min_coins, num_coins)
    return min_coins


def coin_change_memo(amount, coins, memo=dict()):
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


def coin_change_tab(amount, coins):
    table = [float("inf")] * (amount + 1)
    table[0] = 0
    for i in range(amount + 1):
        for coin in coins:
            if i >= coin:
                table[i] = min(table[i], table[i - coin] + 1)
    return table[amount]
