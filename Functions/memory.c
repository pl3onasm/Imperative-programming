#include "functions.ih"

void swap(void *a, void *b, int size) {
  // swaps the contents of the memory at a and b
  // of the given memory size
  unsigned char *x = a, *y = b, tmp;
  for (int i = 0; i < size; ++i) {
    tmp = x[i];
    x[i] = y[i];
    y[i] = tmp;
  }
}

void *safeMalloc(int n) {
  // allocates memory and checks whether this was successful
  void *ptr = malloc(n);
  if (ptr == NULL) {
    printf("Error: malloc(%d) failed. Out of memory?\n", n);
    exit(EXIT_FAILURE);
  }
  return ptr;
}

void *safeCalloc(int n, int size) {
  /* allocates memory, initialized to 0, and
     checks whether this was successful */
  void *ptr = calloc(n, size);
  if (ptr == NULL) {
    printf("Error: calloc(%d, %d) failed. Out of memory?\n", n, size);
    exit(EXIT_FAILURE);
  }
  return ptr;
}

int *createIntArray(int size) {
  // creates an array of size integers
  return safeMalloc(size * sizeof(int));
}

char *createString(int size) {
  // creates a string of size characters
  return safeMalloc((size + 1) * sizeof(char));
}

int **createIntMatrix(int rows, int cols) {
  // creates a integer matrix of size rows x cols
  int **matrix = safeMalloc(rows * sizeof(int*));
  for (int i = 0; i < rows; i++)
    matrix[i] = createIntArray(cols);
  return matrix;
}

int **createNullMatrix(int m, int n) {
  // creates a m x n null matrix, using safeCalloc
  int **matrix = safeCalloc(m, sizeof(int*));
  for (int i = 0; i<m; ++i)
    matrix[i] = safeCalloc(n, sizeof(int));
  return matrix;
}

void freeIntMatrix(int **matrix, int rows) {
  // frees a matrix of size rows x cols
  for (int i = 0; i < rows; i++)
    free(matrix[i]);
  free(matrix);
}

void *safeRealloc(void *ptr, int newSize) {
  // reallocates memory and checks whether it was successful
  ptr = realloc(ptr, newSize);
  if (ptr == NULL) {
    printf("Error: realloc(%d) failed. Out of memory?\n", newSize);
    exit(EXIT_FAILURE);
  }
  return ptr;
}
