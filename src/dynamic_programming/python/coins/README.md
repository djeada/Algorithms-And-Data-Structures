## Coin Change 
Given an amount of money and a list of coins, the task is to find the minimum number of coins needed to make the given amount of money using the available coins.

## Examples

```
Input:

    amount: 5
    coins: [1, 2, 5]

Output:

    1

Explanation:

    The minimum number of coins needed to make 5 using the given coins is 1. One possible way to do this is by using a coin of value 5.
```

```
Input:

    amount: 11
    coins: [1, 2, 5, 10]

Output:

    2

Explanation:

    The minimum number of coins needed to make 11 using the given coins is 2. One possible way to do this is by using a coin of value 10 and a coin of value 1.
```

## Approach

There are three different approaches to solve this problem:

* `coin_change_basic()`: This function uses a recursive approach to solve the problem. It considers each coin in the given list of coins and makes a recursive call with the remaining amount after using the coin. It then returns the minimum number of coins needed to make the given amount of money.

* `coin_change_memo()`: This function uses a recursive approach with memoization to solve the problem. It stores the results of subproblems in a dictionary to avoid recalculating the same subproblems.

* `coin_change_tab()`: This function uses a dynamic programming approach to solve the problem. It stores the results of subproblems in a table and uses them to calculate the result for the given amount of money.

## Complexity

The complexity of the three different approaches are as follows:

* `coin_change_basic`: The worst case complexity of this solution is $O(2^n)$ where n is the amount that needs to be changed. This is because, in the worst case, we may have to try all possible combinations of coins for every possible value of the amount.

* `coin_change_memo`: The worst case complexity of this solution is $O(n)$ where n is the amount that needs to be changed. This is because, in the worst case, we may have to compute the minimum number of coins for every possible value of the amount once and store it in the memoization table.

* `coin_change_tab`: The worst case complexity of this solution is $O(n * m)$ where n is the amount that needs to be changed and m is the number of coins. This is because, in the worst case, we may have to try all possible combinations of coins for every possible value of the amount and update the table accordingly.
