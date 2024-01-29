# $\color{cadetblue}{\text{Problem 2}}$

## Ex1: $\color{rosybrown}{{\mathcal{O}(\sqrt{N})}}$

```c
int i = 0, j = 0;
while (i < N) {
  j++;
  i += 2*j - 1;
}
```

The variable $j$ keeps track of the number of iterations. Use is made of Gauss' formula for the sum of the first $j$ integers, but modified such that $i$ is the exact square of $j$: so we have $i = j^2$, and not $i = j(j+1)/2$, at the end of each loop iteration. The loop terminates when $i \geq N$, so we have $j \geq \sqrt{N}$. The fragment's time complexity is therefore in $\mathcal{O}(\sqrt{N})$.  

Compare this with ex3 from 2013. It is identical, except that the body statements are swapped, reason why $i$ is incremented by $2j + 1$ instead of $2j - 1$ to still obtain $i = j^2$ at the end of each iteration.  

## Ex2: $\color{rosybrown}{{\mathcal{O}(\log N)}}$

```c
int i = N;
while (i > 1) {
  if (i % 2 == 0) {
    i = i/2;
  } else {
    i++;
  }
}
```

The variable $i$ is initialized to $N$, and then halved if it is even, or incremented by one to make it even if it is odd. The loop terminates when $i = 1$. In the worst case, $i$ is halved half of the time, and incremented by one the other half of the time. In this case, the loop needs less than $2\log_2 N$ iterations to terminate. The fragment's time complexity is therefore in $\mathcal{O}(\log N)$.

## Ex3: $\color{rosybrown}{{\mathcal{O}(N)}}$

```c
int i = 0, j = N;
while (i < j) {
  i++;
  j--;
}
```

The variables $i$ and $j$ are incremented and decremented, respectively, until they meet. The loop terminates when $i = j$, after $N/2$ iterations. The fragment's time complexity is therefore in $\mathcal{O}(N)$.

## Ex4: $\color{rosybrown}{{\mathcal{O}(N)}}$

```c
int i, j, sum = 0, prod = 1;
for (i = 0; i < N; i++) {
  sum++;
}
for (j = 1; j < N; j++) {
  prod = prod * j;
}
```

The first loop is executed $N$ times, and the second loop is executed $N-1$ times. The loops are independent, so the fragment's time complexity is therefore in $\mathcal{O}(N)$.

## Ex5: $\color{rosybrown}{{\mathcal{O}(N^2)}}$

```c
int i, j, sum = 0;
for (i = 0; i < N; i++) {
  for (j = 1; j < N; j++) {
    sum++;
  }
}
```

The inner loop is executed $N-1$ times for each iteration of the outer loop, which is executed $N$ times. The loops are nested, so fragment's time complexity is therefore in $\mathcal{O}(N^2)$.

## Ex6: $\color{rosybrown}{{\mathcal{O}(N \log N)}}$

```c
int i, j, sum = 0, prod = 1;
for (i = 1; i < N; i++) {
  prod *= i;
}
j = 0;
while (prod > 0) {
  prod = prod / 2;
  j++;
}
```

The first loop computes the factorial of $N - 1$, in $N - 1$ iterations. The second loop divides $(N-1)!$ by two until it reaches zero, in $\log \left((N-1)!\right)$ $< \log (N!) = \mathcal{O}(N \log N)$ time. The fragment's time complexity is thus determined by the second, most expensive loop, and is therefore in $\mathcal{O}(N \log N)$.
