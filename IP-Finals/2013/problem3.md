# $\color{cadetblue}{\text{Problem 2}}$

## Ex1: $\color{rosybrown}{{\mathcal{O}(\log(N))}}$

```c
int i = 0, j = N;
while (i < j) {
  i++;
  j /= 2;
}
```

The variable $i$ is incremented by $1$ and the variable $j$ is divided by $2$ in each iteration. The loop terminates when $i \geq j$. The total number of iterations is given by $2 \log(N)$. The fragment's time complexity is therefore in $\mathcal{O}(\log(N))$.

## Ex2: $\color{rosybrown}{{\mathcal{O}(N^2)}}$

```c
int i, j, s = 0;
for (i = 0; i < N; i++) {
  for (j = i; j < N - i; j++) {
    s += i + j;
  }
}
```

The outer loop runs $N$ times, whereas the inner loop runs $N - i$ times, where $i$ ranges from $0$ to $N - 1$. The total number of iterations is therefore given by:

$$
\begin{align*}
\sum_{i=0}^{N-1} (N - i) &= \sum_{i=0}^{N-1} N - \sum_{i=0}^{N-1} i \\
&= N^2 - \frac{N(N-1)}{2} \\
&= \frac{N(N+1)}{2} \\
&= \mathcal{O}(N^2)
\end{align*}
$$

Thus, the fragment's time complexity is in $\mathcal{O}(N^2)$.

## Ex3: $\color{rosybrown}{{\mathcal{O}(\sqrt{N})}}$

```c
int i = 0, j = 0;
while (i < N) {
  i += 2*j + 1;
  j++;
}
```

The variable $j$ keeps track of the number of iterations. Use is made of Gauss' formula for the sum of the first $j$ integers, but modified such that $i$ is the exact square of $j$: so we have $i = j^2$, and not $i = j(j+1)/2$, at the end of each loop iteration. The loop terminates when $i \geq N$, so we have $j \geq \sqrt{N}$. The fragment's time complexity is therefore in $\mathcal{O}(\sqrt{N})$.  

Compare this with ex1 from 2014. It is identical, except that the body statements are swapped, reason why $i$ is incremented by $2j - 1$ instead of $2j + 1$ to still obtain $i = j^2$ at the end of each iteration.  

## Ex4: $\color{rosybrown}{{\mathcal{O}(\log(N))}}$

```c
int i = 1, j = N;
while (i < j) {
  i += i;
  j--;
}
```

The variable $i$ is doubled and the variable $j$ is decremented by $1$ in each iteration. The loop terminates when $i \geq j$. The total number of iterations is therefore less than $\log(N)$, and so the fragment's time complexity is in $\mathcal{O}(\log(N))$.

## Ex5: $\color{rosybrown}{{\mathcal{O}(N)}}$

```c
int i, j, s = 0;
for (i = 1; i < N; i *= 3) {
  for (j = 1; j < i; j++) {
    s += j;
  }
}
```

The outer loop runs $\log_3(N)$ times, since $i$ is multiplied by 3 at the end of each iteration. The inner loop runs $i - 1$ times, where $i$ ranges from $1$ to $N - 1$ in steps of factor 3. The total number of iterations is therefore given by:

$$
\begin{align*}
\sum_{i=1}^{\log_3(N)} (3^i - 1) &= \sum_{i=1}^{\log_3(N)} 3^i - \sum_{i=1}^{\log_3(N)} 1 \\
&= 3\left(\frac{1 - 3^{\log_3(N)}}{1 - 3}\right) - \log_3(N) \\
&= \frac{3N - 3}{2} - \log_3(N) \\
&\approx \frac{3N}{2} \\
\end{align*}
$$

Thus, the fragment's time complexity is in $\mathcal{O}(N)$.

Note that we could have run an argument for a complexity in $\mathcal{O}(N \log(N))$ by stating that the inner loop runs $\color{orchid}{\text{at most}}$ $N$ times. This is not wrong, but an overestimate, as the tight bound is in $\mathcal{O}(N)$. It is testomony to the fact that rough reasoning does not always yield the tightest bound.

## Ex6: $\color{rosybrown}{{\mathcal{O}(N \log(N))}}$

```c
int i, j, s = 0, t = 0;
for (i = 1; i < N; i++) {
  s += i;
  for (j = 1; j < s; j *= 2) {
    t += j;
  }
}
```

The outer loop runs $N - 1$ times. The variable $s$ takes the running sum of the first $i$ integers, so $s = i(i+1)/2$ $\approx \frac{i^2}{2}$ before the inner loop starts. The inner loop runs $\log(s) \approx \log(i^2/2) = 2\log(i) -1$  times. The total number of iterations is therefore given by:

$$
\begin{align*}
\sum_{i=1}^{N-1} (2\log(i) - 1) &= 2\sum_{i=1}^{N-1} \log(i) - \sum_{i=1}^{N-1} 1 \\
&= 2\log\left(\prod_{i=1}^{N-1} i\right) - (N-1) \\
&= 2\log((N-1)!) - (N-1) \\
&\approx 2N\log(N) - 2N - N \\
&= \mathcal{O}(N \log(N)) \\
\end{align*}
$$

The fragment's time complexity is therefore in $\mathcal{O}(N \log(N))$.
