# $\color{cadetblue}{\text{Problem 2}}$

## Ex1:   

```c
int s = 0;
for (int i = 0; i < N; i++) {
  for (int j = i; j > 0; j--) {
    s += i + j;
  }
}
```



## Ex2: $\color{rosybrown}{{\mathcal{O}(N^2)}}$

```c
int i = 0, s = 0;
while (s < N) {
  i++;
  s = i*i;
}
```


## Ex3: 

```c
int n = N, a = 2, p = 1;
while (n > 0) {
  if (n % 2 == 1) {
    p = p*a;
    n--;
  } else {
    a = a*a;
    n = n/2;
  }
}
```



## Ex4: 

```c
int i, j = 0, s = 0;
for (i = 0; i < N; i++) {
  s += i;
}
for (i = 0; i < s; i += 2) {
  j += i;
}
```



## Ex5:

```c
int i = 0, s = 1;
for (i = 0; i < 4*N; i += 2) {
  s = 2*s;
}
```



## 

```c
int i, j, s = 0;
for (i = 0; i < N; i++) {
  for (j = N; j > i ; j /= 2) {
    s++;
  }
}
```


