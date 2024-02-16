/* 
  file: libtest.c
  author: David De Potter
  description: example program for using the functions library
  Compile with the test script and feed it the input file:
    ../ctest.sh libtest.c <input.txt
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/functions.h"

int main() {
  // read from stdin
  int rows, cols, size;

  (void)! scanf("%d %d", &rows, &cols);

  // allocate memory for the 2D array
  CREATE_MATRIX(matrix, int, rows, cols);

  // read input from stdin
  READ_MATRIX(matrix, "%d", rows, cols);

  // print the matrix
  printf("\nThe integer matrix is:\n");
  PRINT_MATRIX(matrix, "%02d", rows, cols);
  FREE_MATRIX(matrix, rows);

  // read an array of integers (size is given)
  (void)! scanf("%d", &size);
  CREATE_ARRAY(ints, int, size);
  READ_ARRAY(ints, "%d", size);

  // print the array
  printf("\nThe integer input has %d elements:\n", size);
  PRINT_ARRAY(ints, "%d", size);
  free(ints);
  
  // read the array of doubles (size is not given)
  READ(dbls, double, "%lf", size);

  // print the array
  printf("The double input has %d elements:\n", size);
  PRINT_ARRAY(dbls, "%.2lf", size);
  free(dbls);

  // read one line of input 
  char *str = readUntil('\n', &size);
  printf("The given string is:\n%s\n", str);
  free(str);

  // read all text until the end of the file 
  READ(text, char, "%c", size);

  printf("\nThe piece of text has %d characters:\n", size);
  printf("%s\n\n", text);
  free(text); 

  return 0;
}