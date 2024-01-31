# $\color{cadetblue}{\text{Problem 2}}$

## Ex1: $\color{rosybrown}{{\mathcal{O}(\log(N))}}$

```c
int i = N, s = 0;
while (i > 1) {
  i = i/2;
  s += i;
}
```

The variable $i$ is halved in each loop iteration, so that after $k$ iterations $i = \frac{N}{2^k}$. The loop terminates when $i \leq 1$, which happens when $k \geq \log(N)$. The loop therefore runs in $\mathcal{O}(\log(N))$ time.

## Ex2: $\color{rosybrown}{{\mathcal{O}(N)}}$

```c
int s = 0;
for (int i = 0; i < N; i += 10) {
  s += i;
}
```

Since the loop variable $i$ is incremented by 10 in each iteration, the loop runs $\frac{N}{10}$ times. The fragment's time complexity is therefore in $\mathcal{O}(N)$.

## Ex3: $\color{rosybrown}{{\mathcal{O}(\sqrt{N})}}$

```c
int i = 0, s = 0;
while (s < N) {
  i++;
  s = s + i;
}
```

The variable $s$ is incremented by $i$ in each iteration, while $i$ just counts the number of iterations. After $i$ iterations, $s = \frac{i(i+1)}{2}$ by Gauss' formula. The loop terminates when:

$$
\begin{align*}
& s \geq N \\
\Leftrightarrow \quad & \frac{i(i+1)}{2} \geq N \\
\Leftrightarrow \quad &  i^2 + i \geq 2N \\
\Leftrightarrow \quad & i^2 + i + \frac{1}{4} \geq 2N + \frac{1}{4} \\
\Leftrightarrow \quad & \left(i + \frac{1}{2}\right)^2 \geq 2N + \frac{1}{4} \\
\Leftrightarrow \quad & i + \frac{1}{2} \geq \sqrt{2N + \frac{1}{4}} \\
\Leftrightarrow \quad & i \geq \sqrt{2N + \frac{1}{4}} - \frac{1}{2} \approx \sqrt{2N}
\end{align*}
$$

The overall number of iterations is therefore in $\mathcal{O}(\sqrt{N})$.

## Ex4: $\color{rosybrown}{{\mathcal{O}(N^2)}}$

```c
int s = 0, k = N;
while (k > 0) {
  for (int i = k; i > 0; i--) {
    s += i;
  }
  k--;
}
```

The outer loop runs $N$ times: $k$ is initialized to $N$, decremented by $1$ in each iteration, and the loop terminates when $k = 0$. The inner loop runs $k$ times for each updated value of $k$, so that the fragment's total number of iterations is given by:

$$
\begin{align*}
\sum_{k=N}^1 k &= \sum_{k=1}^N k \\
&= \frac{N(N+1)}{2}
\end{align*}
$$

The fragment's time complexity is therefore in $\mathcal{O}(N^2)$.

## Ex5: $\color{rosybrown}{{\mathcal{O}(N)}}$

```c
int j = 0, s = 1;
while (s < N) {
  s = 2*s;
  for (int i = s; i > 0; i--) {
    j = j + i;
  }
}
```

The outer loop runs $\lceil\log(N)\rceil$ times: $s$ is initialized to $1$, updated to the next power of $2$ in each iteration, and the loop terminates when $s \geq N$, that is, when $s = 2^k$ with $k \geq \log(N)$, where $k \in \mathbb{N}$ is the number of iterations.
The inner loop runs $s$ times for each updated value of $s$, so that the total number of iterations is given by:

$$
\begin{align*}
\sum_{k=1}^{{\lceil\log(N)\rceil}} 2^k &= \sum_{k=0}^{{\lceil\log(N)\rceil}} 2^k - 1 &\color{peru}{(1)}\\
&= 2^{{\lceil\log(N)\rceil} + 1} - 1 - 1 &\color{darkkhaki}{(2)}\\
& \leq 2^{{\log(N)} + 2} - 1 - 1 \\
&= 4N - 2
\end{align*}
$$

In $\color{peru}{(1)}$ we rewrite the sum, so that the index starts at $0$ instead of $1$. This allows us to use the formula for the sum of a geometric series in $\color{darkkhaki}{(2)}$, which is:

$$
\sum_{k=0}^n a^k = \frac{a^{n+1} - 1}{a - 1}
$$

From the above, we therefore have that the fragment's time complexity is in $\mathcal{O}(N)$.

Note that we could have run an argument for a complexity in $\mathcal{O}(N \log(N))$ by stating that the inner loop runs $\color{orchid}{\text{at most}}$ a total of approximately $N$ times. This is not wrong, but an overestimate, as the tight bound is in $\mathcal{O}(N)$. It is testomony to the fact that rough reasoning does not always yield the tightest bound. The same situation arises in [Ex5 of the 2013 exam](https://github.com/pl3onasm/Imperative-programming/blob/main/IP-Finals/2013/problem3.md#ex5-colorrosybrownmathcalon).

## Ex6: $\color{rosybrown}{{\mathcal{O}(N \log(N))}}$

```c
int j = 0, s = 1;
while (s < N) {
  s = 2*s;
  for (int i = s; i < N; i++) {
    j = j + i;
  }
}
```

Just like in the previous example, the outer loop runs $\lceil\log(N)\rceil$ times. The inner loop runs $N - s$ times for each updated value of $s$, so that the total number of iterations is given by:

$$
\begin{align*}
\sum_{k=1}^{{\lceil\log(N)\rceil}} (N - 2^k) &= N{\lceil\log(N)\rceil} - \sum_{k=0}^{{\lceil\log(N)\rceil}} (2^k) -1\\
&= N{\lceil\log(N)\rceil} - (2^{{\lceil\log(N)\rceil} + 1} - 1) - 1 \\
&= N{\lceil\log(N)\rceil} - 2^{{\lceil\log(N)\rceil} + 1} \\
& \leq N(\log(N) + 1) - 2^{{\log(N)} + 2} \\
&= N\log(N) - 3N \\
&= \mathcal{O}(N\log(N))
\end{align*}
$$

The fragment's time complexity is therefore in $\mathcal{O}(N \log(N))$.
