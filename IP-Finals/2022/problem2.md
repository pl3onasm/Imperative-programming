# $\color{cadetblue}{\text{Problem 2}}$

## Ex1: $\color{rosybrown}{{\mathcal{O}(\sqrt{N})}}$  

```c
int n = 1, d = 1;
while (d < N) {
  d = d + 2*n + 1;
  n++;
}
```

At the end of each loop iteration, $d$ is exactly equal to the square of $n$, the variable that keeps track of the number of iterations. So at termination, we have $d \approx \sqrt{N}$. Thus, the fragment's overall time complexity is in $\mathcal{O}(\sqrt{N})$.
The fragment is based on Gauss' formula for the sum of the first $n$ integers, but modified so that $d$ becomes the exact square of $n$, and not $\frac{n(n+1)}{2}$, at the end of each iteration.

## Ex2: $\color{rosybrown}{{\mathcal{O}(N^2)}}$

```c
int s = 0;
for (int i = 0; i < N; i++) {
  for (int j = N; j > i; j -= 2) {
    s++;
  }
}
```

The outer loop is linear: it runs $N$ times. The inner loop runs at most $\frac{N}{2}$ times, when $i = 0$. Since the loops are nested, the time complexity is in $\mathcal{O}(N^2)$.

## Ex3: $\color{rosybrown}{{\mathcal{O}(N)}}$  

```c
int s = 0, i = 0;
while (i < N) {
  i += (s % 2 == 0) ? 1 : 2;
  s++;
}
```

In each iteration, $i$ is incremented by either $1$ or $2$, depending on the parity of $s$, which changes every iteration. This means that the total number of iterations is $\frac{N}{2} + \frac{N}{4} = \frac{3N}{4}$. Thus, the time complexity is in $\mathcal{O}(N)$.

## Ex4: $\color{rosybrown}{{\mathcal{O}(N\log N)}}$

```c
int s = 0;
for (int i = 0; i < N; i++) {
  for (int j = 1; j < i; j *= 2) {
    s++;
  }
}
```

The outer loop is linear: it runs $N$ times, whereas the inner loop runs at most $\log(N)$ times. Since the loops are nested, the fragment's time complexity is in $\mathcal{O}(N\log N)$.

## Ex5: $\color{rosybrown}{{\mathcal{O}(\log N)}}$

```c
int l = 0, r = N;
while (l + 1 < r) {
  int m = (l + r) / 2;
  if (N < m * m) {
    l = m;
  } else {
    r = m;
  }
}
```

We can interpret the variables $l$ and $r$ as indexes indicating the left and right end of a sequence of $N$ elements. In each iteration, the fragment checks whether the middle element of the sequence is greater than $\sqrt{N}$ or not. If it is, then the left end of the sequence is moved to the middle index, otherwise the right end, meaning that half of the sequence is discarded in each iteration.  
This process is repeated until the left and right ends are adjacent to each other. Thus, just like binary search, the fragment runs in $\mathcal{O}(\log N)$ time.

## Ex6: $\color{rosybrown}{{\mathcal{O}(N)}}$  

```c
int a = 0, b = 1, n = 0;
while (n < N) {
  b = a + b;
  a = b - a;
  n++;
}
```

The fragment is based on the Fibonacci sequence. In each iteration, the variables $a$ and $b$ are updated to the next two numbers in the sequence. For example, after five iterations, we get $a = 5$ and $b = 8$. The variable $n$ is incremented by $1$ in each iteration, and the loop terminates when $n = N$. Thus, the fragment runs in $\mathcal{O}(N)$ time.
