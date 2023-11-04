# Binary palindromes

A palindrome is a symmetrical string, that is, a string read identically from left to right as well as from right to left. Thus, "abcba" is a palindrome, but "abab" is not. In this problem we consider binary palindromes, which are binary strings (sequences of characters '0' and '1') that are palindromes. For instance, the following strings are binary palindromes: 101, 11011, 100001.

Given are two non-negative decimal integers $a$ and $b$ ($0 \leq a \leq b < 2147483647$). You have to find all binary palindromes $p$ such that $a \leq p \leq b$. Your program should output these palindromes in ascending order, one per line, with no leading zeros, except for zero itself. Each palindrome should be preceded by its decimal value, a colon and a space.

## Example

Input:

```text
0 10
```

Output:

```text
0: 0
1: 1
3: 11
5: 101
7: 111
9: 1001
```
