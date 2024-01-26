# $\color{cadetblue}{\text{Problem 1}}$

## Ex1: $\color{rosybrown}{{\mathcal{O}(\sqrt{N})}}$  

```c
int i = 0, s = 0;
while (s < N) {
  i++;
  s += 2*i + 1;
}
```

At the end of each iteration, we have $s = i^2 - 1$. The fragment is based on Gauss' formula for the sum of the first $n$ integers, but modified to render the exact square of $i$ at the end of each iteration. The minus $1$ is because $s$ starts at $0$ and not at $1$. So, the loop will terminate when $i^2 - 1 \geq N$, which is equivalent to $i \geq \sqrt{N+1}$. The loop runs a total of $i$ times, meaning that the fragment's complexity is in $\mathcal{O}(\sqrt{N})$.

## Ex2: $\color{rosybrown}{{\mathcal{O}(N^2)}}$  

```c
int s = 0;
for (int i = 0; i < N; i++) {
  for (int j = N - i; j > 0; j--) {
    s += j;
  }
}
```

The inner loop runs $N-i$ times, and the outer loop runs $N$ times. So, the total number of iterations is:

$$\begin{align*}
\sum_{i=0}^{N-1} (N-i) &= \sum_{i=0}^{N-1} N - \sum_{i=0}^{N-1} i \\
&= N^2 - \sum_{i=0}^{N-1} i\\
&= N^2 - \frac{N(N-1)}{2}\\
&= \frac{N(N+1)}{2}
\end{align*}
$$

Hence, the fragment's complexity is in $\mathcal{O}(N^2)$.

## Ex3: $\color{rosybrown}{{\mathcal{O}(\sqrt{N})}}$  

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

The first loop runs approximately $s = \log(\sqrt{N})$ times, and the second loop runs $s^2$ times. Since the loops are not nested, the total number of iterations is dominated by the second loop, which runs $s^2$ times and is in $\mathcal{O}(\log^2(\sqrt{N})) = \mathcal{O}(\log^2(N)) = \mathcal{O}(\sqrt{N})$.

## Ex4: $\color{rosybrown}{{\mathcal{O}(N \log(N))}}$

```c
int s = 0;
for (int j = N*N; j > 0; j /= 3) {
  for (int i = 0; i < N; i += 3) {
    s += i + j;
  }
}
```

The inner loop runs $N/3$ times, and the outer loop runs $\log_3(N^2) = 2 \log_3(N)$ times. The loops are nested, so that the fragment's complexity is in $\mathcal{O}(N \log(N))$.

## Ex5: $\color{rosybrown}{{\mathcal{O}(N)}}$  

```c
int s = 0, i = N*N, j = 0;
while (i > 0) {
  s += i + j;
  j++;
  i -= j;
}
```

The variable i starts at $N^2$ and is decremented by $j$ at each iteration. The variable $j$ starts at $0$ and is incremented by $1$ in each loop, so that $j$ is computing the running sum of the integers from $1$ up to the point where $i$ reaches $0$. After $N$ iterations, $i = N^2 - \frac{N(N+1)}{2} = \frac{N(N-1)}{2}$. Ignoring the constant factors, the fragment's complexity is therefore in $\mathcal{O}(N)$.

## Ex6: $\color{rosybrown}{{\mathcal{O}(\log(N))}}$

```c
int s = 0;
for (int i = N*N; i > 0; i /= 2) {
  s = s + i;
}
```

The index variable $i$ is divided by $2$ at each iteration, so that the loop runs $\log(N^2) = 2 \log(N)$ times. The fragment's complexity is therefore in $\mathcal{O}(\log(N))$.

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

The first loop runs $N$ times, computing the sum of the integers from $0$ to $N-1$, so that at termination $j = \frac{N(N-1)}{2}$. The second loop divides $j$ by $2$ at each iteration, so that the loop runs $\log(\frac{N(N-1)}{2}) = \log(N(N-1)) - \log(2)$ $= \log(N) + \log(N-1) - 1$ times. The loops are not nested, and so the most dominant one, the first floop in this case, determines the fragment's complexity, which is thus in $\mathcal{O}(N)$.

## Ex9: $\color{rosybrown}{{\mathcal{O}(\sqrt{N})}}$

```c
int s = 0, i = 1;
while (i <= N/i) {
  s++;  
  i++;
}
```

In the worst case, $N$ is a perfect square, so that the loop only terminates at $i = \sqrt{N}$. Therefore, the fragment's complexity is in $\mathcal{O}(\sqrt{N})$.

## Ex10: $\color{rosybrown}{{\mathcal{O}(\log(N))}}$

```c
int s = 0, i = N;
while (i > 0) {
  s++;
  i = (i % 2 ? i - 1 : i/2);
}
```

The variable $i$ starts at $N$. Halving it half of the time while decrementing by $1$ the other half of the time, means that it will take less than $2 \log(N)$ iterations to reach $0$. The fragment's complexity is therefore in $\mathcal{O}(\log(N))$.

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

The first loop depends on the parity of $i$, and will behave just like the previous exercise, taking less than $2 \log(N)$ iterations to reach $0$. The second loop runs $N$ times, and is nested inside the first loop, so that the fragment's total complexity is in $\mathcal{O}(N \log(N))$.

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
