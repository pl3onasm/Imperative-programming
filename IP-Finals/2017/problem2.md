# $\color{cadetblue}{\text{Problem 2}}$

## Ex1: $\color{rosybrown}{{\mathcal{O}(N\log(N))}}$

```c
int s = 0;
for (int i = 0; i < N; i += 3) {
  for (int j = 3*N; j > 0; j /= 2) {
    s += i*j;
  }
}
```

The outer loop runs $N/3$ times, and the inner loop runs $\log(3N) = \log(3) + \log(N)$ times. Since the loops are nested, we obtain the total number of iterations by multiplying the number of iterations of the outer loop by the number of iterations of the inner loop, and come to an overall time complexity of $\mathcal{O}(N\log(N))$.

## Ex2: $\color{rosybrown}{{\mathcal{O}(\log(N))}}$

```c
int s = 0;
for (int i = 1; i < N*N; i *= 3) {
  s += i*i;
}
```

The number of iterations of the loop is given by the number of times $i$ can be multiplied by 3 before it exceeds $N^2$. This is equivalent to solving the equation $3^k = N^2$ for $k$, which yields $k = \log_3(N^2)$. We can rewrite this as:

$$
\begin{align*}
\log_3(N^2) &= \frac{\log(N^2)}{\log(3)} \\[2ex]
&= \frac{2}{\log(3)}\log(N) \\[2ex]
&= \mathcal{O}(\log(N))
\end{align*}
$$

Thus, the overall time complexity is in $\mathcal{O}(\log(N))$.

## Ex3: $\color{rosybrown}{{\mathcal{O}(\sqrt{N})}}$

```c
int i = 0, s = 0;
while (s < N) {
  s += i;
  i++;
}
while (i > 0) {
  s += i;
  i--;
}
```

The first loop runs until $s = \frac{i(i-1)}{2} \geq N$, which is equivalent to solving the quadratic equation $i^2 - i - 2N = 0$ for $i$. This yields $i = \sqrt{2N + \frac{1}{4}} + \frac{1}{2}$ $\approx \sqrt{2N}$.  
The second loop decrements $i$ until it reaches 0 in a total of $\sqrt{2N}$ steps. The loops are not nested, so we obtain an overall time complexity of $\mathcal{O}(\sqrt{N})$.

## Ex4: $\color{rosybrown}{{\mathcal{O}(N^2)}}$

```c
int i, j = 0, s = 0;
for (i = 0; i < N; i++) {
  for (j = 0; j < 5*i; j += 2) {
    s += i + j;
  }
}
```

The outer loop runs $N$ times, and the inner loop runs at most $\frac{5(N-1)}{2}$ times when $i$ reaches its maximum value of $N-1$.  
Since the loops are nested, the fragment runs in $\mathcal{O}(N^2)$ time.

## Ex5: $\color{rosybrown}{{\mathcal{O}(N\log(N))}}$

```c
int s = 0;
for (int i = N; i > 0; i--) {
  int d = 2 + i % 5;
  for (int j = 1; j < N; j *= d) {
    s += j*s;
  }
}
```

The outer loop runs $N$ times. The inner loop runs $\log_d(N) = \frac{\log(N)}{\log(d)}$ times, where $d \in \left[2, 7\right)$, which is in $\mathcal{O}(\log(N))$ time. Since the loops are nested, we obtain an overall time complexity of $\mathcal{O}(N\log(N))$.

## Ex6: $\color{rosybrown}{{\mathcal{O}(N)}}$

```c
int i = 0, s = 0;
while (s < N*N) {
  s += i;
  i++;
}
```

The loop runs until $s = \frac{i(i-1)}{2} \geq N^2$, which is equivalent to solving the quadratic equation $i^2 - i - 2N^2 = 0$ for $i$. This yields $i = \frac{1}{2} + \sqrt{2N^2 + \frac{1}{4}}$ $\approx \sqrt{2}N$.
Thus, the total number of iterations is in $\mathcal{O}(N)$.
