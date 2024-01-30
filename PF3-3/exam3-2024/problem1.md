# $\color{cadetblue}{\text{Problem 1}}$

## Ex1: $\color{rosybrown}{{\mathcal{O}(\sqrt{N})}}$  

```c
int i = 0, s = 0;
while (s < N) {
  i++;
  s += 2*i + 1;
}
```

At the end of each iteration, we have $s = i^2 + 2i$. The fragment is based on Gauss' formula for the sum of the first $n$ integers. The loop will terminate when:

$$
\begin{align*}
& s \geq N \\
\Leftrightarrow \quad  &i^2 + 2i \geq N \\
\Leftrightarrow \quad &i^2 + 2i + 1 \geq N + 1 \\
\Leftrightarrow \quad &(i + 1)^2 \geq N + 1 \\
\Leftrightarrow \quad &i + 1 \geq \sqrt{N + 1} \\
\Leftrightarrow \quad &i \geq \sqrt{N + 1} - 1
\end{align*}
$$

Thus, the number of iterations is $\sqrt{N + 1} - 1$, and the fragment's complexity is in $\mathcal{O}(\sqrt{N})$.

## Ex2: $\color{rosybrown}{{\mathcal{O}(N^2)}}$  

```c
int s = 0;
for (int i = 0; i < N; i++) {
  for (int j = N - i; j > 0; j--) {
    s += j;
  }
}
```

The inner loop is executed $N - i$ times for each value of $i$. So, the total number of iterations is:

$$\begin{align*}
\sum_{i=0}^{N-1} (N-i) &= \sum_{i=0}^{N-1} N - \sum_{i=0}^{N-1} i \\
&= N^2 - \sum_{i=0}^{N-1} i\\
&= N^2 - \frac{N(N-1)}{2}\\
&= \frac{N(N+1)}{2}
\end{align*}
$$

Hence, the fragment's complexity is in $\mathcal{O}(N^2)$.

Another, more intuitive way to reach the same conclusion is to note that the outer loop is executed $N$ times, whereas the inner loop is executed $\color{orchid}{\text{at most}}$ $N$ times, so that the nested loop's complexity becomes quadratic in $N$. However, these types of arguments do not always yield the tightest bound, and so it is better to stick to the more formal approach whenever the upper bound of the inner loop depends on the outer loop's index. A case in point is ex5 from 2013, where you would expect from an intuitive argument that the complexity is in $\mathcal{O}(N \log(N))$, which is not wrong, but not tight either, as the tight bound is actually $\mathcal{O}(N)$.

## Ex3: $\color{rosybrown}{{\mathcal{O}(N)}}$

```c
int s = 1, t = 0;
while (s*s < N) {
  s = 2*s;
}
for (int i = 0; i < s; i++) {
  for (int j = 0; j < s; j++) {
    t += i + j;
  }
}
```

The first loop computes $s \approx \sqrt{N}$ in $\log(\sqrt{N}) = \frac{1}{2} \log(N)$ steps. The second loop, on the other hand, runs a total number of $s^2 \approx N$ times. Thus, the nested loop dominates the fragment's total complexity, which is in $\mathcal{O}(N)$.

## Ex4: $\color{rosybrown}{{\mathcal{O}(N \log(N))}}$

```c
int s = 0;
for (int j = N*N; j > 0; j /= 3) {
  for (int i = 0; i < N; i += 3) {
    s += i + j;
  }
}
```

The inner loop runs $\frac{N}{3}$ times. The number of iterations of the outer loop is given by the number of times $N^2$ can be divided by $3$ before reaching $0$, which is $\log_3(N^2)$. We can rewrite this as:

$$
\begin{align*}
\log_3(N^2) &= \frac{\log(N^2)}{\log(3)} \\
&= \frac{2}{\log(3)}\log(N) \\
&= \mathcal{O}(\log(N))
\end{align*}
$$

The loops are nested, and so the fragment's total time complexity is in $\mathcal{O}(N \log(N))$.

## Ex5: $\color{rosybrown}{{\mathcal{O}(N)}}$  

```c
int s = 0, i = N*N, j = 0;
while (i > 0) {
  s += i + j;
  j++;
  i -= j;
}
```

The variable $i$ starts at $N^2$ and is decremented by $j$ at each iteration. The variable $j$ starts at $0$ and is updated to the next integer at each iteration. The loop terminates when $i \leq 0$, which is equivalent to $N^2 - \frac{k(k+1)}{2} \leq 0$, where $k$ is the number of iterations, i.e. the value of $j$ at termination. So we have:

$$
\begin{align*}
& i \leq 0 \\
\Leftrightarrow \quad &N^2 - \frac{k(k+1)}{2} \leq 0 \\
\Leftrightarrow \quad &2N^2 \leq k^2 +k \\
\Leftrightarrow \quad &2N^2 + \frac{1}{4}\leq k^2 + k + \frac{1}{4}\\
\Leftrightarrow \quad &2N^2 + \frac{1}{4} \leq (k + \frac{1}{2})^2 \\
\Leftrightarrow \quad &\sqrt{2N^2 + \frac{1}{4}} \leq k + \frac{1}{2} \\
\Leftrightarrow \quad &k \geq \sqrt{2N^2 + \frac{1}{4}} - \frac{1}{2} \approx \sqrt{2} N
\end{align*}
$$

The fragment's time complexity is therefore in $\mathcal{O}(N)$.

## Ex6: $\color{rosybrown}{{\mathcal{O}(\log(N))}}$

```c
int s = 0;
for (int i = N*N; i > 0; i /= 2) {
  s = s + i;
}
```

The loop index $i$ is divided by $2$ at each iteration, so that the loop runs $\log(N^2) = 2 \log(N)$ times. The fragment's complexity is therefore in $\mathcal{O}(\log(N))$.

## Ex7: $\color{rosybrown}{{\mathcal{O}(N^2)}}$

```c
int s = 0, j = 0;
for (int i = 0; i < N; i++) {
  j += i;
}
while (j > 0) {
  s += j;
  j -= 2;
}
```

The first loop runs $N$ times, computing the sum of the integers from $0$ to $N-1$, so that at termination $j = \frac{N(N-1)}{2}$. The second loop subtracts $2$ from $j$ at each iteration, so that the loop runs $\frac{N(N-1)}{4}$ times. The loops are not nested, and so the fragment's complexity is in $\mathcal{O}(N^2)$.

## Ex8: $\color{rosybrown}{{\mathcal{O}(N)}}$

```c
int s = 0, j = 0;
for (int i = 0; i < N; i++) {
  j += i;
}
while (j > 0) {
  s += j;
  j /= 2;
}
```

The first loop runs $N$ times, computing the sum of the integers from $0$ to $N-1$, so that at termination $j = \frac{N(N-1)}{2}$. The second loop divides $j$ by $2$ at each iteration, so that the loop runs $\log(\frac{N(N-1)}{2}) = \log(N(N-1)) - \log(2)$ $= \log(N) + \log(N-1) - 1$ times.  
The loops are not nested, and so the most expensive one, the for loop in this case, determines the fragment's complexity, which is thus in $\mathcal{O}(N)$.

## Ex9: $\color{rosybrown}{{\mathcal{O}(\sqrt{N})}}$

```c
int s = 0, i = 1;
while (i <= N/i) {
  s++;  
  i++;
}
```

The variable $i$ is incremented by $1$ at each iteration, and the termination condition can be rewritten as $i^2 \leq N$, which is equivalent to $i \leq \sqrt{N}$. Therefore, the fragment's complexity is in $\mathcal{O}(\sqrt{N})$.

## Ex10: $\color{rosybrown}{{\mathcal{O}(\log(N))}}$

```c
int s = 0, i = N;
while (i > 0) {
  s++;
  i = (i % 2 ? i - 1 : i/2);
}
```

The variable $i$ starts at $N$. In the worst case, we are then halving it half of the time and decrementing it by $1$ the other half of the time. In this case, the loop needs less than $2\log(N)$ iterations to terminate.
The fragment's complexity is therefore in $\mathcal{O}(\log(N))$.

## Ex11: $\color{rosybrown}{{\mathcal{O}(N \log(N))}}$

```c
int s = 0, i = N;
while (i > 0) {
  i = (i % 2 == 0 ? i/2 : i - 1);
  for (int j = 0; j < 2*N; j += 2) {
    s += i + j;
  }
}
```

The first loop will behave just like the previous exercise, taking less than $2 \log(N)$ iterations to reach $0$. The second loop runs $N$ times, and is nested inside the first loop, so that the fragment's total complexity is in $\mathcal{O}(N \log(N))$.

## Ex12: $\color{rosybrown}{{\mathcal{O}(N^2)}}$

```c
int s = 0;
for (int i = 1; i < 10; i++) {
  for (int j = i; j < N; j++) {
    for (int k = j; k < N; k++) {
      s += i + j + k;
    }
  }
}
```

The innermost loop runs $N-j$ times, the middle loop runs $N-i$ times, and the outer loop runs $9$ times. In the worst case, $i = 1$ and $j = 1$, so that both the middle and innermost loops run $N-1$ times. The outer loop runs $9$ times, and only adds a constant factor to the complexity. The loops are nested, so that the fragment's total complexity is in $\mathcal{O}(N^2)$.
