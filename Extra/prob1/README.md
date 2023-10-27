# Sum of multiples

Given are two positive integers $a$ and $b$. The output of your program should be the sum of all the multiples of $a$ and $b$ below a given positive integer $n \leq 10^{11}$.

For example, if $a = 12$, $b = 9$ and $n = 50$, then the output should be $386$, because the sum of all the multiples of $5$ and $7$ below $50$ is $5 + 7 + 10 + 14 + 15 + 20 + 21 + 25 + 28 + 30 + 35 + 40 + 42 + 45 + 49 = 386$.

The input consists of three positive integers $a$, $b$ and $n$ separated by a space.
The output should be a single positive integer representing the sum of all the multiples of $a$ and $b$ below $n$.

Note that the numbers can become very large. You should use a data type that can handle numbers as large as $10^{20}$.
