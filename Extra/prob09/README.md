# Well-formed strings of parentheses

This problem involves strings consisting solely of parentheses. A well-formed string of parentheses is defined by the following (recursive) rules:

• The empty string is well-formed.
• If $s$ is a well formed string, then $(s)$ is a well-formed string.
• If $s$ and $t$ are well formed strings, then their concatenation $st$ is a well-formed string

For example, "((()))" and "()()()" are well-formed strings, while "(()", ")(()" and "(" are not well-formed strings.  
There are exactly 5 well-formed strings that have length 6: "((()))", "(()())", "(())()", "()(())", and "()()()".  

The input of this problem consists of an integer $n$, where $1 \leq n \leq 30$. Your program should output the number of well-formed strings of parentheses that have length $n$.

## Examples

```text
Input: 6
Output: 5

Input: 10
Output: 42
```
