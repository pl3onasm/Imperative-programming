# $\color{cadetblue}{\text{Problem 2}}$

## Ex1: $\color{rosybrown}{{\mathcal{O}(N)}}$

```c
int i, s = 0;
for (i = N; 2*i > 0; i--) {
  s += i;
}
```

The loop runs $N$ times, since the loop condition can be rewritten as $i > 0$. Hence, the fragment's time complexity is in $\mathcal{O}(N)$.

## Ex2: $\color{rosybrown}{{\mathcal{O}(N\log N)}}$

```c
int i, j, s=0;
for (i = 1; i < N; i *= 2) {
  for (j = i+1; j < N; j += 2) {
    s += j;
  }
}
```

The outer loop runs $\log(N)$ times, since $i$ is doubled at each iteration. The inner loop runs at most $\frac{N - 2}{2} = \frac{N}{2} - 1$ times, which is linear in $N$. The loops are nested, so the total time complexity is in $\mathcal{O}(N\log N)$.

## Ex3: $\color{rosybrown}{{\mathcal{O}(\sqrt{N})}}$

```c
int i = 0, s = 0, p = 1;
while (s < N) {
  i++;
  p = p*i;
  s += i;
}
```

At each iteration, $p$ equals the product of the first $i$ integers, so that $p = i!$, whereas $s$ equals the sum of the first $i$ integers, so that $s = \frac{i(i+1)}{2}$. The loop terminates when $s \geq N$, that is, when:

$$
\begin{align*}
&\frac{i (i+1)}{2} \geq N \\
\Leftrightarrow \quad &i^2 + i \geq 2 N \\
\Leftrightarrow \quad &i^2 + i + \frac{1}{4} \geq 2 N + \frac{1}{4} \\
\Leftrightarrow \quad &(i + \frac{1}{2})^2 \geq 2 N + \frac{1}{4} \\
\Leftrightarrow \quad &i + \frac{1}{2} \geq \sqrt{2 N + \frac{1}{4}} \\
\Leftrightarrow \quad &i \geq \sqrt{2 N + \frac{1}{4}} - \frac{1}{2} \approx \sqrt{2 N} \\
\end{align*}
$$

Hence, the fragment's time complexity is in $\mathcal{O}(\sqrt{N})$.

## Ex4: $\color{rosybrown}{{\mathcal{O}(\log N)}}$

```c
int i = N, s = 0;
while (i > 0) {
  s++;
  if (i % 2 == 1) {
    i = i - 1;
  }
  i = i/2;
}
```

The loop runs $\log(N)$ times, since $i$ is halved at each iteration. The if statement ensures that $i$ is even at each iteration, after which it is halved. Therefore, the fragment's time complexity is in $\mathcal{O}(\log N)$.

## Ex5: $\color{rosybrown}{{\mathcal{O}(N^2)}}$

```c
int i = 0, s = 0;
while (2*i <= N*N) {
  s += i;
  i++;
}
```

At each iteration, $i$ is incremented by $1$. When the loop terminates, $i = \frac{N^2}{2} + 1$. Therefore, the fragment's time complexity is in $\mathcal{O}(N^2)$.

## Ex6: $\color{rosybrown}{{\mathcal{O}(N)}}$

```c
int i = 0, s = 0;
while (s <= N*N) {
  s += i;
  i++;
}
```

The loop terminates when $s > N^2$, that is, when:

$$
\begin{align*}
&(i-1) + (i-2) + \cdots + 1 > N^2 \\
\Leftrightarrow \quad &\frac{i(i-1)}{2} > N^2 \\
\Leftrightarrow \quad &i^2 - i > 2 N^2 \\
\Leftrightarrow \quad &i^2 - i + \frac{1}{4} > 2 N^2 + \frac{1}{4} \\
\Leftrightarrow \quad &(i - \frac{1}{2})^2 > 2 N^2 + \frac{1}{4} \\
\Leftrightarrow \quad &i - \frac{1}{2} > \sqrt{2 N^2 + \frac{1}{4}} \\
\Leftrightarrow \quad &i > \sqrt{2 N^2 + \frac{1}{4}} + \frac{1}{2} \approx \sqrt{2} N \\
\end{align*}
$$

Note that $i$ is incremented after $s$ is updated, so that when the loop condition is checked, the value of $s$ is the sum of the first $i - 1$ integers. From the calculation above, we conclude that the fragment's time complexity is in $\mathcal{O}(N)$.
