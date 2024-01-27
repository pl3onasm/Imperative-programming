# $\color{cadetblue}{\text{Problem 2}}$

## Ex1: $\color{rosybrown}{{\mathcal{O}(\sqrt{N})}}$  

```c
int d = 2;
while (d*d <= N) {
  if (N % d == 0) {
    break;
  }
  d++;
}
```

The code fragment looks to find the smallest divisor of $N$, if any. In the worst case, $N$ is prime or has no other divisors than its square root (e.g. $N = 25$). In this worst case scenario, the loop will run $\sqrt{N}$ times. Thus, the overall time complexity is in $\mathcal{O}(\sqrt{N})$.

## Ex2: $\color{rosybrown}{{\mathcal{O}(N^2)}}$

```c
int s = 0;
for (int i = 0; i < N; i++) {
  s += i;
}
for (int i = s; i > 1; i -= 2) {
  s++;
}
```

The first loop is linear: it runs $N$ times. When it ends, we get $s = \frac{N(N-1)}{2}$. The second loop then runs $\frac{N(N-1)}{4}$ times, which is quadratic. Since the loops are not nested, and the second one takes the most time, the overall time complexity is in $\mathcal{O}(N^2)$.

## Ex3: $\color{rosybrown}{{\mathcal{O}(N)}}$

```c
int d = 2, n = N;
while (n > 1) {
  if (n % d == 0) {
    n = n / d;
  } else {
    d++;
  }
}
```

The loop keeps dividing $n$ by its divisors until $n$ reaches 1. In the worst case, $N$ is prime, and the loop runs $N$ times: it only terminates after the prime $N$ is divided by itself. Thus, the overall time complexity is in $\mathcal{O}(N)$.

## Ex4: $\color{rosybrown}{{\mathcal{O}(N\log N)}}$

```c
int s = 0;
for (int i = 0; i < N; i++) {
  for (int j = 1; j < i; j *= 2) {
    s++;
  }
}
```

The outer loop is linear in $N$, and the inner loop runs $\log(i)$ times for each iteration of the outer loop, so that the total number of iterations is given by

$$
\begin{align*}
\sum_{i=1}^N \log(i) &= \log\left(\prod_{i=1}^N i\right) \\
&= \log(N!) \\
&= \mathcal{O}(N\log(N))
\end{align*}
$$

Hence, the time complexity of the fragment is in $\mathcal{O}(N\log(N))$.

## Ex5: $\color{rosybrown}{{\mathcal{O}(\log N)}}$

```c
int a = 42, n = N, p = 1;
while (n > 0) {
  if (n % 2 == 1) {
    p *= a;
  }
  a = a*a;
  n /= 2;
}
```

The program computes $42^N$ using the binary exponentiation algorithm. The loop runs $\log(N)$ times, since $n$ is halved at each iteration until it reaches 0. Thus, the overall time complexity is in $\mathcal{O}(\log N)$.

## Ex6: $\color{rosybrown}{{\mathcal{O}(N)}}$

```c
int i = 0, j = 0, s = 0;
while (i < N) {
  i += j;
  j++;
  for (int k = 0; k*k < N; k++) {
    s++;
  }
}
```

The outer loop runs in $\mathcal{O}(\sqrt{N})$ time, since $i$ is incremented by $j$, which itself is incremented by 1 at each iteration.  
The inner loop is in $\mathcal{O}(\sqrt{N})$ as well, since $k$ is incremented by 1 at each iteration, and the loop terminates when $k^2 \geq N$. Since the loops are nested, the fragment's overall time complexity is in $\mathcal{O}(N)$.
