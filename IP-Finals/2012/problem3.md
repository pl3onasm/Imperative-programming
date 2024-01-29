# $\color{cadetblue}{\text{Problem 2}}$

## Ex1: $\color{rosybrown}{{\mathcal{O}(N)}}$

```c
int i = 0, j = N;
while (i < j) {
  i++;
  j--;
}
```

Both variables run through their consecutive values, until they meet in the middle at which point the loop terminates. The total number of iterations is $N/2$, and the fragment's complexity is therefore in $\mathcal{O}(N)$.

## Ex2: $\color{rosybrown}{{\mathcal{O}(\log N)}}$

```c
int i = 0, j = N;
while (j - i > 1) {
  if (i % 2 == 0) {
    i = (i + j)/2;
  } else {
    j = (i + j)/2;
  }
}
```

This is similar to a binary search algorithm. At each iteration, the size of the interval is halved, and the loop terminates when the interval is of size $1$ or less. The number of iterations is therefore the number of times $N$ can be halved before reaching $1$, which is $\log(N)$. Thus, the fragment's complexity is in $\mathcal{O}(\log N)$.

## Ex3: $\color{rosybrown}{{\mathcal{O}(\sqrt{N})}}$

```c
int i = 0;
while (i*i < N) {
  i++;
}
```

The loop terminates when $i^2 \geq N$, which is equivalent to $i \geq \sqrt{N}$. Thus, the number of iterations is $\sqrt{N}$, and the fragment's complexity is in $\mathcal{O}(\sqrt{N})$.

## Ex4: $\color{rosybrown}{{\mathcal{O}(N^2)}}$

```c
int i, j = 0, s = 0;
for (i = 0; i < N; i++) {
  s += i;
}
for (i = 0; i < s; i++) {
  j += i;
}
```

The first loop computes the sum of the first $N - 1$ integers, so that in the end, we have $s = \frac{N(N-1)}{2}$. The second loop then runs $s$ times, which is quadratic in $N$. The loops are not nested, and so the overall complexity is determined by the most expensive loop, which is the second one. Thus, the fragment's complexity is in $\mathcal{O}(N^2)$.

## Ex5: $\color{rosybrown}{{\mathcal{O}(N \log N)}}$

```c
int i, j, s = 0;
for (i = 1; i < N; i++) {
  for (j = 1; j < i; j *= 2) {
    s += j;
  }
}
```



## Ex6: $\color{rosybrown}{{\mathcal{O}(N)}}$

```c
int i, j, s = 0, a[5] = {0, 0, 0, 0, 0};
for (i = 0; i < N; i++) {
  a[i % 5]++;
}
for (i=0; i < 5; i++) {
  for (j=0; j < a[i]; j++) {
    s += i + j;
  }
}
```


