#include "functions.ih"

int minimum(int x, int y) {
  // returns the minimum of x and y
  return x < y ? x : y;
}

int maximum(int x, int y) {
  // returns the maximum of x and y
  return x > y ? x : y;
}

int abs(int x) {
  // returns the absolute value of x
  return x < 0 ? -x : x;
} 

int isPrime(int x) {
  // returns 1 if x is prime, 0 otherwise
  if (x == 2) return 1;
  if (x % 2 == 0 || x == 1) return 0;
  for (int i = 3; i*i <= x; i += 2) 
    if (x % i == 0) return 0;
  return 1;
}

int isPerfSquare(int n) {
  // returns 1 if n is a perfect square, 0 otherwise 
  int root = sqrt(n);
  return root * root == n;
}

int isDivisor(int x, int y) {
  // checks whether y evenly divides x
  return x % y == 0;
}

int GCD(int a, int b) {
  // returns the greatest common divisor of a and b
  if (b == 0) return a;
  return GCD(b, a % b);
}

int LCM(int a, int b) {
  // returns the least common multiple of a and b
  return a / GCD(a, b) * b;
}

int areCoprime(int a, int b) {
  /* checks if a and b have no common divisors,
     i.e. if they are coprime */
  return GCD(a, b) == 1;
}

int power(int n, int exp) {
  /* returns n^exp using binary exponentiation 
     also known as exponentiation by squaring */
  int pow = 1;
  while (exp) {
    if (exp & 1) pow *= n; 
    if (exp > 1) n *= n;
    exp /= 2;
  }
  return pow;
}

int modExp(int n, int exp, int m) {
  /* computes n^exp mod m using modular exponentiation */
  int pow = 1; n %= m;
  while (exp) {
    if (exp & 1) pow = (pow * n) % m;
    if (exp > 1) n = (n * n) % m;
    exp /= 2;
  }
  return pow;
}