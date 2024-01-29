# $\color{cadetblue}{\text{Problem 2}}$

## Ex1: $\color{rosybrown}{{\mathcal{O}(N\log{N})}}$

```c
int s = 0;
for (int i = 0; i < N; i++) {
  int k = 2 + i % 5;
  for (int j = 1; j < N; j *= k) {
    s += i + j;
  }
}
```

The outer loop runs $N$ times. The inner loop runs $\log_k{N}$ times, where $k$ is a constant in the range $[2,6]$, meaning that it runs $\log_2{N}$ times in the worst case and $\log_6{N}$ times in the best case. Since the loops are nested, the fragment's overall time complexity is in $\mathcal{O}(N\log{N})$.

## Ex2: $\color{rosybrown}{{\mathcal{O}(\sqrt{N})}}$

```c
int i = 0, j = 0, s = 0;
while (i*j < 2*N) {
  i = i + 1;
  j = j + 2;
  s = s + i + j;
}
```

In each iteration the variable $i$ is incremented by 1 and the variable $j$ is incremented by 2. The loop terminates when $i \cdot j \geq 2 \cdot N$ $\iff \frac{i \cdot j}{2} \geq N$. Since we have $j  = 2 i$ at the end of each iteration, the loop condition becomes $i^2 \geq N \iff i \geq \sqrt{N}$. Hence, the fragment's overall time complexity is in $\mathcal{O}(\sqrt{N})$.

## Ex3: $\color{rosybrown}{{\mathcal{O}(N)}}$

```c
int s = 0, i = 0;
while (s < N*N) {
  s = s + i;
  i++;
}
```

The loop terminates when $s \geq N^2$. Since $s$ is incremented by $i$ in each iteration, we have $s = \frac{i \cdot (i-1)}{2}$ by Gauss' formula. Hence, the loop terminates when

$$
\begin{align*}
&\frac{i (i-1)}{2} \geq N^2 \\
\iff &i (i-1) \geq 2 N^2 \\
\iff &i^2 - i \geq 2 N^2 \\
\iff &i^2 - i + \frac{1}{4} \geq 2 N^2 + \frac{1}{4} \\
\iff &(i - \frac{1}{2})^2 \geq 2 N^2 + \frac{1}{4} \\
\iff &i - \frac{1}{2} \geq \sqrt{2 N^2 + \frac{1}{4}} \\
\iff &i \geq \sqrt{2 N^2 + \frac{1}{4}} + \frac{1}{2} \approx \sqrt{2} N
\end{align*}
$$

Therefore, the fragment's overall time complexity is in $\mathcal{O}(N)$.

## Ex4: $\color{rosybrown}{{\mathcal{O}(\log{N})}}$

```c
int i = 1, s = 0;
while (s < N) {
  s = s + i;
  i += i + i % 2;
}
```

The loop terminates when $s \geq N$. The variable $s$ keeps the running sum of all consecutive values of $i$, which in turn is doubled and incremented by $1$ in each iteration, because $i$ remains odd at all times. This means that $s$ reaches $N$ in a little less than $\log{N}$ iterations. Hence, the fragment's overall time complexity is in $\mathcal{O}(\log{N})$.

## Ex5: $\color{rosybrown}{{\mathcal{O}(N^2)}}$

```c
int i = 1, s = 0;
while (i < N*N) {
  i = 2*i;
}
while (i > 0) {
  s += i;
  i--;
}
```

By the end of the first loop, $i$ is the smallest power of $2$ that is greater than or equal to $N^2$. Since $i$ is doubled in each iteration, the first loop runs $\log{N^2} = 2\log{N}$ times. The second loop, on the other hand, runs $i$ times, which is in $\mathcal{O}(N^2)$. Therefore, the fragment's overall time complexity is in $\mathcal{O}(N^2)$.

## Ex6: $\color{rosybrown}{{\mathcal{O}(N)}}$

```c
int i = 1, s = 0;
while (i*i < N) {
  i = 2*i;
}
while (i > 0) {
  for (int j = 0; j < i; j++) {
    s += i + j;
  }
  i--;
}
```

The first loop computes $i \geq \sqrt{N}$ in $\log{(\sqrt{N})} = \frac{1}{2}\log{(N)}$ steps. The second part of the fragment is linear in $N$, because both the outer and the inner loop run about $\sqrt{N}$ times. Therefore, the fragment's overall time complexity is in $\mathcal{O}(N)$.
