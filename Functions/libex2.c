/* 
  file: libex2.c
  author: David De Potter
  description: example program for using the functions library
  Compile with the test script and feed it the input file:
    ../ctest.sh libex2.c 
  Usage: ./a.out <input.txt
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/functions.h"

int main() {
  int rows, cols, size;

  // read the dimensions of the matrix
  (void)! scanf("%d %d", &rows, &cols);

  // allocate memory for the 2D array
  CREATE_MATRIX(int, matrix, rows, cols);

  // read input from stdin into the matrix
  READ_MATRIX(matrix, "%d", rows, cols);

  // print the matrix
  printf("\nThe integer matrix is:\n");
  PRINT_MATRIX(matrix, "%02d", rows, cols);
  FREE_MATRIX(matrix, rows);

  // read an array of integers (size is given)
  (void)! scanf("%d", &size);
  CREATE_ARRAY(int, ints, size);
  READ_ARRAY(ints, "%d", size);

  // print the integer array
  printf("\nThe integer input has %d elements:\n", size);
  PRINT_ARRAY(ints, "%d", size);
  
  // sort the integer array
  mergeSort(ints, size);
  printf("\nThe sorted integer array is:\n");
  PRINT_ARRAY(ints, "%d", size);
  free(ints);
  
  // read the array of doubles (size is not given)
  READ(double, dbls, "%lf", size);

  // print the array
  printf("\nThe double input has %d elements:\n", size);
  PRINT_ARRAY(dbls, "%.2lf", size);
  free(dbls);

  // read one line of input 
  READ_UNTIL(char, str, "%c", '\n', size);
  printf("\nThe input string is:\n%s\n", str);
  free(str);

  // read all text until the end of the file 
  READ(char, text, "%c", size);

  printf("\nThe piece of text has %d characters:\n", size);
  printf("%s\n\n", text);
  free(text); 

  return 0;
}