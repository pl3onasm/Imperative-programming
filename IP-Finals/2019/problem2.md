# $\color{cadetblue}{\text{Problem 2}}$

## Ex1: $\color{rosybrown}{{\mathcal{O}(\sqrt{N})}}$

```c
int s = 0;
for (int i = 0; i < N; i += s) {
  s++;
}
```

After each iteration, the loop index $i$ is incremented by $s$, which is itself incremented by $1$ in each execution of the loop body. This means that $i$ is first incremented by $1$, then by $2$, then $3$, ..., so that after $k$ iterations $i = \frac{k(k+1)}{2}$. The loop terminates when $i \geq N$, which happens when $k \geq \sqrt{2N + \frac{1}{4}} - \frac{1}{2}$. The loop therefore runs in $\mathcal{O}(\sqrt{N})$ time.

## Ex2: $\color{rosybrown}{{\mathcal{O}(\log(N))}}$

```c
int s = 0;
for (int i = 1; i < N*N; i *= 2) {
  s = s + i;
}
```

The loop index $i$ is multiplied by 2 at each iteration, so that after $k$ iterations $i = 2^k$. The loop terminates when $i \geq N^2$, which happens when $k \geq \log(N^2) = 2\log(N)$. The loop therefore runs in $\mathcal{O}(\log(N))$ time.

## Ex3: $\color{rosybrown}{{\mathcal{O}(N^2)}}$

```c
int s = 0;
for (int i = 0; i < 2*N; i += 2) {
  for (int j = N; j > 0; j -= 3) {
    s += i + j;
  }
}
```

The outer loop runs $N$ times, and the inner loop runs $\frac{N}{3}$ times. This means that the loop body is executed $\frac{N^2}{3}$ times, so that the total running time is in $\mathcal{O}(N^2)$.

## Ex4: $\color{rosybrown}{{\mathcal{O}(\log(N))}}$

```c
int i = 0, s = 0;
while (s < N) {
  s = (i % 2 == 0 ? 2*s : s + 1);
  i++;
}
```

As the parity of $i$ flips each time the loop body is executed, the variable $s$ is doubled half of the time, and incremented by $1$ the other half of the time.  
After $k$ iterations, we have $s = 2^{\lfloor k/2 \rfloor} + \lfloor k/2 \rfloor$. The loop terminates when $s \geq N$, which happens for a value for $k$ that lies between $\log(N)$ and $2\log(N)$. The loop therefore runs in $\mathcal{O}(\log(N))$ time.

## Ex5: $\color{rosybrown}{{\mathcal{O}(N\log(N))}}$

```c
int s = 0;
for (int i = N*N; i > 0; i = i/2) {
  for (int j = 0; j < N; j++) {
    s += i + j;
  }
}
```

The outer loop runs $\log(N^2) = 2\log(N)$ times, and the inner loop runs $N$ times. This means that the inner loop body is executed $2N\log(N)$ times, so that the fragment's overall time complexity is in $\mathcal{O}(N\log(N))$.

## Ex6: $\color{rosybrown}{{\mathcal{O}(N)}}$

```c
int k = 0, s = 0;
for (int i = 0; i < N; i += k) {
  k++;
  for (int j = 0; j*j < N; j++) {
    s = s + j;
  }
}
```

The outer loop has an index $i$ which after each iteration is incremented by $k$, which is itself incremented by $1$ in each execution of the loop body. This means that $i$ is first incremented by $1$, then by $2$, then $3$, ..., so that after $k$ iterations $i = \frac{k(k+1)}{2}$. The loop terminates when $i \geq N$, which happens when $k \geq \sqrt{2N + \frac{1}{4}} - \frac{1}{2}$, so that $k\approx \sqrt{2N}$.  
The inner loop runs $\sqrt{N}$ times, so that the inner loop body is executed about $\sqrt{2}N$ times, and the fragment's total time complexity is in $\mathcal{O}(N)$.
