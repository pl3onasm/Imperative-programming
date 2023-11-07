# Next smaller number

Given is a positive integer $n \leq 10^{18}$. You are asked to find the largest integer $m$ such that $m < n$ and $m$ has the same digits as $n$. If there is no such $m$, then the output should be $-1$. Also return $-1$ if the next smaller number with the same digits has a leading zero. You are not allowed to use a sorting algorithm.

## Examples

Input 1:

```text
632
```

Output 1:

```text
623
```

Input 2:

```text
123656789
```

Output 2:

```text
123598766
```

Input 3:

```text
100
```

Output 3:

```text
-1
```
