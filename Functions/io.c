#include "functions.ih"

void printIntArray(int *arr, int n) {
  // prints an array of size n
  printf("[");
  for (int i = 0; i < n; i++) 
    printf(i < n-1 ? "%d, " : "%d", arr[i]);
  printf("]\n");
}

void printIntMatrix(int **matrix, int rows, int cols) {
  // prints a matrix of size rows x cols
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) 
      printf(j < cols-1 ? "%d " : "%d\n", matrix[i][j]);
  }
}

void readIntArray(int *arr, int size) {
  // reads an array of size integers from stdin
  for (int i=0; i < size; i++) 
    (void)! scanf("%d", &arr[i]);
}

void readIntMatrix(int **arr, int m, int n) {
  // reads an m x n matrix from stdin
  for (int i=0; i<m; ++i) 
    for (int j=0; j<n; ++j) 
      (void)! scanf("%d", &arr[i][j]);
}

int *readInts(int *size) {
  /* reads int array as long as integer input lasts; 
     stores its length in size */
  int n, len = 0, *arr = safeMalloc(100 * sizeof(int)); 
  while (scanf("%d", &n) == 1) {
    arr[len++] = n;
    if (len % 100 == 0)
      arr = safeRealloc(arr, (len + 100) * sizeof(int));
  }
  *size = len;
  return arr;
}

char *readText(int *size) {
  /* reads a string from stdin, including new line chars, 
     and returns the string and stores its length in size */
  char c; int len = 0; 
  char *str = safeMalloc(100 * sizeof(char));
  while (scanf("%c", &c) == 1) {
    str[len++] = c; 
    if (len % 100 == 0) 
      str = safeRealloc(str, (len + 100) * sizeof(char));
  }
  str[len] = '\0';
  *size = len;
  return str;
}

char *readLine(int *size) {
  /* reads a line from stdin, returns the string, 
     and stores its length in size */
  char c; int len = 0; 
  char *str = safeMalloc(100 * sizeof(char));
  while (scanf("%c", &c) == 1 && c != '\n') {
    str[len++] = c; 
    if (len % 100 == 0) 
      str = safeRealloc(str, (len + 100) * sizeof(char));
  }
  str[len] = '\0';
  *size = len;
  return str;
}