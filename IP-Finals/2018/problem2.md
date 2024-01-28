# $\color{cadetblue}{\text{Problem 2}}$

## Ex1: $\color{rosybrown}{{\mathcal{O}(N^2)}}$

```c
int j = 0, s = 0;
for (int i = N; i > 0; i--) {
  j = j + i;
}
while (j > 5) {
  s = s + j % 7;
  j--;
}
```

The first loop runs $N$ times, computing the sum of the first $N$ integers, so that by the end $j = \frac{N(N+1)}{2}$ by Gauss' formula. The second loop iterates a total number of $j - 5$ times. The loops are not nested, so the second loop dominates the overall complexity as it is quadratic in $N$. The fragment's time complexity is therefore in $\mathcal{O}(N^2)$.

## Ex2: $\color{rosybrown}{{\mathcal{O}(\log N)}}$

```c
int i = 1, s = 0;
while (i < N*N) {
  s = s + 3*i;
  i = 2*i;
}
```

The variable $i$ is doubled at each iteration, so that the loop runs $\log(N^2) = 2\log(N)$ times. The fragment's time complexity is therefore in $\mathcal{O}(\log N)$.

## Ex3: $\color{rosybrown}{{\mathcal{O}(N)}}$

```c
int s = 0;
for (int i = 42; i < 7*N; i += 3) {
  s += i;
}
```

The variable $s$ does not affect the complexity of the fragment. The loop runs $\frac{7N - 42}{3} = \frac{7}{3}N - 14$ times. The fragment's time complexity is therefore in $\mathcal{O}(N)$.

## Ex4: $\color{rosybrown}{{\mathcal{O}(\sqrt{N})}}$

```c
int i = 0, s = 0;
while (s < N) {
  s = i*i;
  i++;
}
while (i > 0) {
  s += i;
  i--;
}
```

The first loop ends when $s = i^2 \geq N$, so that $i \geq \sqrt{N}$. In the second loop, $i$ is decremented until it reaches $0$, so that the loop runs $\sqrt{N}$ times. The loops are not nested, so the fragment's time complexity is therefore in $\mathcal{O}(\sqrt{N})$.

## Ex5: $\color{rosybrown}{{\mathcal{O}(N\log N)}}$

```c
int s = 0;
for (int i = N; i > 0; i = i/2) {
  for (int j = i; j < N; j++) {
    s += i + j;
  }
}
```

The index $i$ is halved after each iteration of the outer loop, so that the latter runs $\log N$ times. The inner loop runs $N - i$ times, which is $N - 1$ in the worst case. The loops are nested, so the fragment's time complexity is therefore in $\mathcal{O}(N\log N)$.

## Ex6: $\color{rosybrown}{{\mathcal{O}(N)}}$

```c
int i, j = 0, s = 0;
for (i = 0; i < N; i++ ) {
  j = j + i;
}
for (i = 0; i*i < j; i++) {
  s = i + j;
}
```

The first loop runs $N$ times, computing the sum of the first $N - 1$ integers, so that in the end $j = \frac{N(N-1)}{2}$ by Gauss' formula. The second loop runs about $\sqrt{j}$ times, which is linear in $N$. The loops are not nested, so the fragment's time complexity is therefore in $\mathcal{O}(N)$.
