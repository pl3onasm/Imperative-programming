# $\color{cadetblue}{\text{Problem 2}}$

## Ex1: $\color{rosybrown}{{\mathcal{O}(N^2)}}$

```c
int j = 0, s = 0;
for (int i = N; i > 0; i--) {
  j = j + i;
}
while (j > 5) {
  s = s + j % 7;
  j--;
}
```

The first loop runs $N$ times, computing the sum of the first $N$ integers, so that after the loop has terminated, we have $j = \frac{N(N+1)}{2}$ by Gauss' formula. The second loop iterates a total number of $j - 5$ times. It is quadratic in $N$, since $j$ is decremented by $1$ at each iteration.  
The loops are not nested, so the most expensive one determines the fragment's time complexity, which is therefore in $\mathcal{O}(N^2)$.

## Ex2: $\color{rosybrown}{{\mathcal{O}(\log N)}}$

```c
int i = 1, s = 0;
while (i < N*N) {
  s = s + 3*i;
  i = 2*i;
}
```

The variable $i$ is doubled at each iteration, so that the loop runs $\log(N^2) = 2\log(N)$ times. The fragment's time complexity is therefore in $\mathcal{O}(\log N)$.

## Ex3: $\color{rosybrown}{{\mathcal{O}(N)}}$

```c
int s = 0;
for (int i = 42; i < 7*N; i += 3) {
  s += i;
}
```

The variable $s$ does not affect the complexity of the fragment. The loop runs $\frac{7N - 42}{3} = \frac{7}{3}N - 14$ times. The fragment's time complexity is therefore in $\mathcal{O}(N)$.

## Ex4: $\color{rosybrown}{{\mathcal{O}(\sqrt{N})}}$

```c
int i = 0, s = 0;
while (s < N) {
  s = i*i;
  i++;
}
while (i > 0) {
  s += i;
  i--;
}
```

The first loop ends when $s = i^2 \geq N$, so that $i \geq \sqrt{N}$. In the second loop, $i$ is decremented until it reaches $0$, so that the loop runs $\sqrt{N}$ times. The loops are not nested, so the fragment's time complexity is therefore in $\mathcal{O}(\sqrt{N})$.

## Ex5: $\color{rosybrown}{{\mathcal{O}(N\log N)}}$

```c
int s = 0;
for (int i = N; i > 0; i = i/2) {
  for (int j = i; j < N; j++) {
    s += i + j;
  }
}
```

The index $i$ is initialized to $N$ and is halved at the end of each iteration of the outer loop, which therefore runs a total number of $\log(N)$ times. The inner loop runs $N - i$ times for each value of $i$, which is $\frac{N}{2^k}$ for the $k$-th iteration of the outer loop, where $k \in \{1, \dots, \lfloor \log(N) \rfloor\}$.[^1]
The total number of iterations of the inner loop is therefore given by:

$$
\begin{align*}
& \quad \sum_{k=1}^{\lfloor \log(N) \rfloor} \left( N - \frac{N}{2^k} \right) \\
= &\quad \sum_{k=1}^{\lfloor\log(N)\rfloor} N - N\sum_{k=1}^{\lfloor\log(N)\rfloor} \frac{1}{2^k} \\
= &\quad N\lfloor\log(N)\rfloor - N\left( 1 - \frac{1}{2^{\lfloor\log(N)\rfloor}} \right) \\
= &\quad N\lfloor\log(N)\rfloor - N + \frac{N}{2^{\lfloor\log(N)\rfloor}} \\
\leq &\quad N(\log(N)+1) - N + \frac{N}{2^{\log(N)}} \\
= &\quad N\log(N) + \frac{N}{2^{\log(N)}} \\
= &\quad \mathcal{O}(N\log(N))
\end{align*}
$$

From the above, we conclude that the fragment's time complexity is in $\mathcal{O}(N\log(N))$.

[^1]: Note that we let the index k start from 1, since the first iteration of the outer loop does not run the inner loop. This is because the inner loop's condition is $j < N$, which is not satisfied when i = N. The counting of the total number of iterations starts for i = N/2 which corresponds to k = 1. The expression still holds for k = 0, since the summand is 0, but the calculation is a little easier if we start from k = 1.

## Ex6: $\color{rosybrown}{{\mathcal{O}(N)}}$

```c
int i, j = 0, s = 0;
for (i = 0; i < N; i++ ) {
  j = j + i;
}
for (i = 0; i*i < j; i++) {
  s = i + j;
}
```

The first loop runs $N$ times, computing the sum of the first $N - 1$ integers, so that in the end $j = \frac{N(N-1)}{2}$ by Gauss' formula. The second loop runs about $\sqrt{j}$ times, which is also linear in $N$. The loops are not nested, so the fragment's time complexity is therefore in $\mathcal{O}(N)$.
