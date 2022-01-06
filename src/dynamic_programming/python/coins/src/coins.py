def coin_change_basic(amount, coins):

    if amount <= 0:
        return 0

    min_coins = float("inf")

    for coin in coins:
        if coin <= amount:
            min_coins = min(min_coins, coin_change_basic(amount - coin, coins) + 1)

    return min_coins


def coin_change_memo(amount, coins, memo=dict()):

    if amount <= 0:
        return 0

    if amount in memo:
        return memo[amount]

    min_coins = float("inf")

    for coin in coins:
        if coin <= amount:
            min_coins = min(min_coins, coin_change_memo(amount - coin, coins, memo) + 1)

    memo[amount] = min_coins
    return memo[amount]


def coin_change_tab(amount, coins):
    table = [[0 for i in range(amount + 1)] for coin in coins]

    for i in range(amount + 1):
        table[0][i] = i

    for i in range(1, len(coins)):
        for j in range(1, amount + 1):

            if j < coins[i]:
                table[i][j] = table[i - 1][j]

            else:
                table[i][j] = min(table[i - 1][j], table[i][j - coins[i]] + 1)

    return table[len(coins) - 1][amount]
