/* file: functions.h
   author: David De Potter
   description: header file for the functions library
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
  // usage: PRINT_ARRAY(arr, "%d", size);
  //        PRINT_ARRAY(arr, "%.2lf", size);
  //        PRINT_ARRAY(arr, "%c", size);
#define PRINT_ARRAY(arr, format, len) \
  for (int i = 0; i < len; ++i) \
    printf(format, arr[i]), printf(i == len-1 ? "\n" : ", "); \
  printf("\n");

  // macro for printing a matrix of a given type and dimensions
  // usage: PRINT_MATRIX(matrix, "%d", rows, cols);
  //        PRINT_MATRIX(matrix, "%.2lf", rows, cols);
  //        PRINT_MATRIX(matrix, "%c", rows, cols);
#define PRINT_MATRIX(matrix, format, rows, cols) \
  for (int i = 0; i < rows; ++i) { \
    for (int j = 0; j < cols; ++j) \
      printf(format, matrix[i][j]), printf(j == cols-1 ? "\n" : " "); \
  } 

  // macro for creating an array of a given type and length
  // usage: CREATE_ARRAY(int, 10);
  //        CREATE_ARRAY(double, 20);
  //        CREATE_ARRAY(char, 15);
#define CREATE_ARRAY(arr, type, len) \
  type *arr = safeCalloc(len, sizeof(type))

  // macro for creating a matrix of given type and dimensions
  // usage: CREATE_MATRIX(matrix, int, 10, 10);
  //        CREATE_MATRIX(matrix, double, 10, 15);
  //        CREATE_MATRIX(matrix, char, 15, 10);
#define CREATE_MATRIX(matrix, type, rows, cols) \
  type **matrix = safeCalloc(rows, sizeof(type *)); \
  for (int i = 0; i < rows; ++i) \
    matrix[i] = safeCalloc(cols, sizeof(type));

  // macro for freeing the memory of a matrix 
#define FREE_MATRIX(matrix, rows) \
  for (int i = 0; i < rows; ++i) \
    free(matrix[i]); \

  // macro for reading input into an array of given length
  // usage: READ_ARRAY(arr, "%d", size);
  //        READ_ARRAY(arr, "%lf", size);
  //        READ_ARRAY(arr, "%c", size);
#define READ_ARRAY(arr, format, len) \
  for (int i = 0; i < len; ++i) \
    (void)! scanf(format, &arr[i]);

  // macro for reading input into a matrix of given dimensions
  // usage: READ_MATRIX(matrix, "%d", rows, cols);
  //        READ_MATRIX(matrix, "%lf", rows, cols);
  //        READ_MATRIX(matrix, "%c", rows, cols);
#define READ_MATRIX(matrix, format, rows, cols) \
  for (int i = 0; i < rows; ++i) \
    for (int j = 0; j < cols; ++j) \
      (void)! scanf(format, &matrix[i][j]);

  // macro for reading input from stdin as long as it lasts
  // sets the size to the number of elements read
  // usage: READ(int, "%d", arr, size);
  //        READ(double, "%lf", arr, size);
  //        READ(char, "%c", arr, size);
#define READ(arr, type, format, size) \
  type *arr = safeCalloc(100, sizeof(type)); \
  int arr##Len = 0; type arr##var; \
  while (scanf(format, &arr##var) == 1) { \
    arr[arr##Len++] = arr##var; \
    if (arr##Len % 100 == 0) \
      arr = safeRealloc(arr, (arr##Len + 100) * sizeof(type)); \
  } \
  size = arr##Len;

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
  
  // returns 1 if a evenly divides b, 0 otherwise
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
    
//::::::::::::::::::::::::::: IO.C ::::::::::::::::::::::::::::::://

  // reads chars until delim is encountered, 
  // returns a string containing all chars read
  // and sets size to the number of chars read
char *readUntil(char delim, int *size);
    
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