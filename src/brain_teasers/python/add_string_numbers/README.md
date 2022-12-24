## Add Numbers in String Form

This project provides a function for adding two string numbers together and returning the result as a string. This can be useful in cases where the numbers being added are too large to be represented as integers or floats in a programming language.

## Examples
```
Input:
s1 = "12345"
s2 = "67890"

Output:
"80235"
```

```
Input:
s1 = "123.45"
s2 = "678.90"

Output:
"802.35"
```

## Approach

The function first checks if either of the input strings is a float by checking if it contains a decimal point. If either string is a float, it determines the number of decimal places in each and adds zeros to the end of the other string to ensure that they have the same number of decimal places.

Then, it iterates through the digits of the strings from the end, adding them together and keeping track of any carryover. Finally, it inserts a decimal point in the result string if necessary.

## Complexity

The function has a time complexity of $O(n)$, where n is the length of the longer input string. The space complexity is also $O(n)$, as the result string is created by adding digits to it one at a time.