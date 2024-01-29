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

The variable $s$ is incremented by $i$ in each iteration, while $i$ just counts the number of iterations. After $i$ iterations, $s = \frac{i(i+1)}{2}$ by Gauss' formula. The loop terminates when $s \geq N$, which happens when $i \geq \sqrt{2N + \frac{1}{4}} - \frac{1}{2}$ $\approx \sqrt{2N}$. The loop therefore runs in $\mathcal{O}(\sqrt{N})$ time.

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

The outer loop runs $N$ times. In the worst case, which is when $k = N$, the inner loop runs $N$ times as well. The fragment's time complexity is therefore in $\mathcal{O}(N^2)$.

## Ex5: $\color{rosybrown}{{\mathcal{O}(N\log(N))}}$

```c
int j = 0, s = 1;
while (s < N) {
  s = 2*s;
  for (int i = s; i > 0; i--) {
    j = j + i;
  }
}
```

The outer loop runs $\log(N)$ times. In the worst case, which is when $s \approx N$ in the last iteration, the inner loop runs about $N$ times. The loops are nested, and the fragment's time complexity is therefore in $\mathcal{O}(N\log(N))$.

## Ex6: $\color{rosybrown}{{\mathcal{O}(N\log(N))}}$

```c
int j = 0, s = 1;
while (s < N) {
  s = 2*s;
  for (int i = s; i < N; i++) {
    j = j + i;
  }
}
```

This is the same as the previous example, except that the inner loop runs in the opposite direction and terminates when $i \geq N$. In the worst case, which is when $s = 2$ in the first iteration, the inner loop runs $N - 2$ times. The outer loop, just like in the previous example, runs $\log(N)$ times. The fragment's time complexity is therefore in $\mathcal{O}(N\log(N))$ again.
