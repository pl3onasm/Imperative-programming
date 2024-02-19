/* file: clib.h
   author: David De Potter
   description: header file for the clib library
*/

#ifndef FUNCTIONS_H_INCLUDED    
#define FUNCTIONS_H_INCLUDED

//::::::::::::::::::::::::: MACROS :::::::::::::::::::::::::::::://

  // macros for min, max, abs, and sign
#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define ABS(a) ((a) < 0 ? -(a) : (a))

#define SIGN(a) ((a) > 0 ? 1 : ((a) < 0 ? -1 : 0))

  // macro definition for swapping two variables
#define SWAP(a, b) swap(&a, &b, sizeof(a))

  // macro for printing an array of a given type and length
  // Examples:  PRINT_ARRAY(myInts, "%d", 10);
  //            PRINT_ARRAY(myDbls, "%.2lf", 20);
#define PRINT_ARRAY(arr, format, len) \
  for (int arr##i = 0; arr##i < len; ++arr##i){ \
    printf(format, arr[arr##i]);\
    printf(arr##i == len-1 ? "\n" : ", "); \
  } 

  // macro for printing a matrix of a given type and dimensions
  // Examples:  PRINT_MATRIX(myInts, "%d", rows, cols);
  //            PRINT_MATRIX(myDbls, "%.2lf", rows, cols);
  //            PRINT_MATRIX(myChrs, "%c", rows, cols);
#define PRINT_MATRIX(matrix, format, rows, cols) \
  for (int matrix##i = 0; matrix##i < rows; ++matrix##i) { \
    for (int matrix##j = 0; matrix##j < cols; ++matrix##j) {\
      printf(format, matrix[matrix##i][matrix##j]); \
      printf(matrix##j == cols-1 ? "\n" : " "); \
    } \
  } 

  // macro for creating an array of a given type and length
  // Examples:  CREATE_ARRAY(myInts, int, 10);
  //            CREATE_ARRAY(myDbls, double, 20);
  //            CREATE_ARRAY(myString, 15);
#define CREATE_ARRAY(type, arr, len) \
  type *arr = safeCalloc(len, sizeof(type))

  // macro for creating a matrix of given type and dimensions
  // Examples:  CREATE_MATRIX(myInts, int, 10, 10);
  //            CREATE_MATRIX(myDbls, double, 10, 15);
  //            CREATE_MATRIX(myChrs, char, 15, 10);
#define CREATE_MATRIX(type, matrix, rows, cols) \
  type **matrix = safeCalloc(rows, sizeof(type *)); \
  for (int matrix##i = 0; matrix##i < rows; ++matrix##i) \
    matrix[matrix##i] = safeCalloc(cols, sizeof(type));

  // macro for freeing the memory of a matrix 
#define FREE_MATRIX(matrix, rows) \
  for (int matrix##i = 0; matrix##i < rows; ++matrix##i) \
    free(matrix[matrix##i]); \
  free(matrix);

  // macro for reading input into an array of known length
  // Examples:  READ_ARRAY(myInts, "%d", 20);
  //            READ_ARRAY(myDbls, "%lf", 15);
  //            READ_ARRAY(myString, "%c", 10);
#define READ_ARRAY(arr, format, len) \
  for (int arr##i = 0; arr##i < len; ++arr##i) \
    (void)! scanf(format, &arr[arr##i]);

  // macro for reading input into a matrix of given dimensions
  // Examples:  READ_MATRIX(myInts, "%d", 10, 5);
  //            READ_MATRIX(myDbls, "%lf", 8, 8);
  //            READ_MATRIX(myChrs, "%c", 5, 10);
#define READ_MATRIX(matrix, format, rows, cols) \
  for (int arr##i = 0; arr##i < rows; ++arr##i) \
    for (int arr##j = 0; arr##j < cols; ++arr##j) \
      (void)! scanf(format, &matrix[arr##i][arr##j]);

  // macro for reading input from stdin as long as it lasts
  // creates a new array of the given type and format,
  // sets the parameter size to the number of elements read
  // and sets the last element to '\0'
  // Examples:  READ(int, "%d", myInts, size);
  //            READ(double, "%lf", myDbls, size);
  //            READ(char, "%c", myChrs, size);
#define READ(type, arr, format, size) \
  type *arr = safeCalloc(100, sizeof(type)); \
  int arr##Len = 0; type arr##var; \
  while (scanf(format, &arr##var) == 1) { \
    arr[arr##Len++] = arr##var; \
    if (arr##Len % 100 == 0) \
      arr = safeRealloc(arr, (arr##Len + 100) * sizeof(type)); \
  } \
  size = arr##Len;\
  arr[arr##Len] = '\0';

  // macro for reading input from stdin until a given 
  // delimiter is encountered 
  // returns a string containing all chars read
  // and sets size to the number of chars read
  // Examples:  READ_UNTIL(char, myString, "%c", '\n', size);
  //            READ_UNTIL(int, myInts, "%d", 0, size);
#define READ_UNTIL(type, arr, format, delim, size) \
  type *arr = safeCalloc(100, sizeof(type)); \
  size_t arr##Len = 0; type arr##var; \
  while (scanf(format, &arr##var) == 1 && arr##var != delim) { \
    arr[arr##Len++] = arr##var; \
    if (arr##Len % 100 == 0) \
      arr = safeRealloc(arr, (arr##Len + 100) * sizeof(type)); \
  } \
  size = arr##Len;\
  arr[arr##Len] = '\0';

//::::::::::::::::::::::::: INTEGERS.C :::::::::::::::::::::::::://

  // returns the number of digits in the given integer
int countDigits(int a);
    
  // returns the reverse of the given integer as a new integer
  // Input of at most 9 digits long to avoid overflow
int reverseInt(int a);
    
  // returns the integer a with the leftmost digit moved
  // to the rightmost position. Input of at most 9 digits. 
int leftRotate(int a);
    
  // returns the integer a with the rightmost digit moved
  // to the leftmost position. Input of at most 9 digits.
int rightRotate(int a);
    
  // returns a string with the binary representation of a,
  // to be freed by the caller; assumes a is non-negative
char *toBinary(int a);
    
  // returns 1 if the year is a leap year, 0 otherwise
int isLeapYear(int year);
    
  // converts the integer to a string, to be freed by the caller
char *toString(int a);
    
  // returns 1 if the integer is a palindrome, 0 otherwise
int isIntPalindrome(int a);
    
//:::::::::::::::::::::::::: MATH.C :::::::::::::::::::::::::::::://

  // returns 1 if the integer is prime, 0 otherwise
  // input is assumed to be non-negative
int isPrime(int a);

  // returns 1 if the integer is a perfect square, 0 otherwise
  // input is assumed to be non-negative
int isPerfSquare(int a);
  
  // returns 1 if b evenly divides a, 0 otherwise
int isDivisor(int a, int b);
    
  // returns the greatest common divisor of the two integers
  // input is assumed to be non-negative
int GCD(int a, int b);
  
  // returns the least common multiple of the two integers
  // input is assumed to be non-negative
int LCM(int a, int b);

  // returns 1 if the integers are coprime (i.e. if they 
  // have no common divisors), 0 otherwise
  // input is assumed to be non-negative
int areCoprime(int a, int b);
  
  // returns a raised to the power of exp, 
  // using repeated squaring. May overflow for large exponents
int power(int a, int exp);
  
  // returns a raised to the power of exp, modulo mod
int modExp(int a, int exp, int mod);
    
//::::::::::::::::::::::::: MEMORY.C ::::::::::::::::::::::::::::://

  // swaps two variables of any type
void swap(void *a, void *b, int size);

  // allocates memory and checks if it succeeded
void *safeMalloc(int n);
    
  // allocates memory, initialized to 0, and checks if it succeeded
void *safeCalloc(int n, int size);
    
  // reallocates memory and checks if it succeeded
void *safeRealloc(void *ptr, int newSize);
    
//:::::::::::::::::::::::: SEARCHING.C ::::::::::::::::::::::::::://

  // linear search for the key in the array of given size;
  // returns the index of the key in the array, -1 if not found
int linSearch(int *array, int size, int key);
    
  // binary search for the key in the sorted array of given size;
  // returns the index of the key in the array, -1 if not found
int binSearch(int *sorted, int size, int key);

//::::::::::::::::::::::::: STRINGS.C :::::::::::::::::::::::::::://

  // case insensitive comparison of two strings str1 and str2
  // returns 0 if equal, -1 if str1 < str2, 1 if str1 > str2
int compareStrings(char *str1, char *str2);
    
  // returns a copy of the string;
  // to be freed by the caller
char *copyString(char *str);
  
  // reverses the string in place
void reverseString(char *str);

  // checks if a (sub)string is a palindrome between
  // pointers start and end; returns 1 if true, 0 otherwise
int isStrPalindrome(char *start, char *end);

//::::::::::::::::::::::::: SORTING.C :::::::::::::::::::::::::::://

  // returns a copy of the subarray from start to end;
  // this function is needed for mergeSort
int *copySubArray(int *array, int start, int end);
    
  // sorts an array of size integers using merge sort in O(n log n)
void mergeSort(int *array, int size);
    
  // sorts an array of size integers using bubble sort in O(n²)
void bubbleSort(int *array, int size);
    
  // sorts an array of size integers using insertion sort in O(n²)
void insertionSort(int *array, int size);
    
  // sorts an array of size integers using selection sort in O(n²)
void selectionSort(int *array, int size);
    
  // sorts an array of size integers using quick sort 
  // in expected O(n log n) time, O(n²) in the worst case
void quickSort(int *array, int size);
    
  // sorts an array of size integers using counting sort in O(n);
  // assumes the range between min and max value is not too large
void countingSort(int *array, int size);
    
#endif // FUNCTIONS_H_INCLUDED