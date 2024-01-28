# $\color{cadetblue}{\text{Problem 2}}$

## Ex1: $\color{rosybrown}{{\mathcal{O}(N\log(N))}}$

```c
int s = 0;
for (int i = N; i > 0; i /= 2) {
  for (int j = i; j > 0; j--) {
    s += i*i;
  }
}
```

The outer loop runs $\log(N)$ times, since $i$ starts at $N$ and is then halved after each iteration. The inner loop runs $N$ times in the worst case, when $i = N$. Therefore, the overall time complexity is in $\mathcal{O}(N\log(N))$.

## Ex2: $\color{rosybrown}{{\mathcal{O}(N\log(N))}}$

```c
int s = 0;
for (int i = N; i > 0; i--) {
  for (int j = i; j > 0; j /= 2) {
    s += i*i;
  }
}
```

The fragment is similar to the previous one, but now the outer loop runs $N$ times, and the inner loop runs $\log(N)$ times in the worst case, when $i = N$. Therefore, the fragment's time complexity is in $\mathcal{O}(N\log(N))$.

## Ex3: $\color{rosybrown}{{\mathcal{O}(N^2)}}$

```c
int s = 0;
for (int i = N; i > 0; i--) {
  for (int j = i; j > 0; j -= 2) {
    s += i*i;
  }
}
```

The outer loop runs $N$ times, and the inner loop runs $N/2$ times in the worst case, when $i = N$. Therefore, the fragment's time complexity is in $\mathcal{O}(N^2)$.

## Ex4: $\color{rosybrown}{{\mathcal{O}(\sqrt{N})}}$

```c
int s = 0;
for (int i = 0; i < N/i; i++) {
  s += i;
}
```

The loop condition is $i < N/i$, which is equivalent to $i^2 < N$. Therefore, the loop runs about $\sqrt{N}$ times, and the fragment's time complexity is in $\mathcal{O}(\sqrt{N})$.  
To be fair, the program fragment will actually result in undefined behavior as the initial value of the loop condition is undefined, with $i$ being initialized to 0.

## Ex5: $\color{rosybrown}{{\mathcal{O}(\log(N))}}$

```c
int s = 0, i = N;
while (i >= 0) {
  int d = 1 + i % 5;
  s += d;
  i = (i % d == 0 ? i - 1 : i/d);
}
```

The variable $i$ is initialized to $N$, and is either decremented by 1 or divided by $d$ in each iteration. The value of $d$ is always between 1 and 5. Only when $i$ is evenly divisible by $d$ is it decremented by $1$, otherwise it is integer divided by $d$. This means that there is a one in five chance that $i$ is decremented by $1$, and a four in five chance that it is divided by $d$. Clearly, the division is the dominant operation. The fragment's time complexity is therefore in $\mathcal{O}(\log(N))$.

## Ex6: $\color{rosybrown}{{\mathcal{O}(N\log(N))}}$

```c
int j = 0, s = 0;
for (i = 1; i < N; i *= 2) {
  while (j < i) {
    s += (i + j);
    j++;
  }
}
```

The outer loop runs $\log(N)$ times, since $i$ is doubled after each iteration. For each iteration of the outer loop, the inner one makes $j$ catch up to the current value of $i$: $j$ is not reset to 0 after each iteration, but its previous value is instead incremented until it equals $i$ again. Therefore, the inner loop runs a total of $N$ times, and since the loops are nested, we obtain an overall time complexity of $\mathcal{O}(N\log(N))$.
