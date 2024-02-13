/* file: functions.h
   author: David De Potter
   description: header file for the functions library
*/

#ifndef FUNCTIONS_H_INCLUDED    
#define FUNCTIONS_H_INCLUDED

//::::::::::::::::::::::::: INTEGERS.C :::::::::::::::::::::::::://

int countDigits(int a);
    // returns the number of digits in the given integer

int reverseInt(int a);
    // returns the reverse of the given integer as a new integer
    // Input of at most 9 digits long to avoid overflow

int leftRotate(int a);
    // returns the integer a with the leftmost digit moved
    // to the rightmost position. Input of at most 9 digits. 

int rightRotate(int a);
    // returns the integer a with the rightmost digit moved
    // to the leftmost position. Input of at most 9 digits.

char *toBinary(int a);
    // returns a string with the binary representation of a,
    // to be freed by the caller

int isLeapYear(int year);
    // returns 1 if the year is a leap year, 0 otherwise

char *toString(int a);
    // converts the integer to a string, to be freed by the caller

int isIntPalindrome(int a);
    // returns 1 if the integer is a palindrome, 0 otherwise

//:::::::::::::::::::::::::: MATH.C :::::::::::::::::::::::::::::://

int minimum(int a, int b);
    // returns the minimum of the two given integers

int maximum(int a, int b);
    // returns the maximum of the two given integers
    
int abs(int a);
    // returns the absolute value of the given integer

int isPrime(int a);
    // returns 1 if the integer is prime, 0 otherwise
    // input is assumed to be non-negative

int isPerfSquare(int a);
    // returns 1 if the integer is a perfect square, 0 otherwise
    // input is assumed to be non-negative

int isDivisor(int a, int b);
    // returns 1 if a is a divisor of b, 0 otherwise

int GCD(int a, int b);
    // returns the greatest common divisor of the two integers
    // input is assumed to be non-negative

int LCM(int a, int b);
    // returns the least common multiple of the two integers
    // input is assumed to be non-negative

int areCoprime(int a, int b);
    // returns 1 if the integers are coprime (i.e. if they 
    // have no common divisors), 0 otherwise

int power(int a, int exp);
    // returns a raised to the power of exp, 
    // using repeated squaring. May overflow for large exponents

int modExp(int a, int exp, int mod);
    // returns a raised to the power of exp, modulo mod

//::::::::::::::::::::::::: MEMORY.C ::::::::::::::::::::::::::::://

void swap(void *a, void *b, int size);
    // swaps the contents of the memory at a and b of the 
    // given memory size. Can be used for any type of data

void *safeMalloc(int n);
    // allocates memory and checks if it succeeded

void *safeCalloc(int n, int size);
    // allocates memory, initialized to 0, 
    // and checks if it succeeded

int *createIntArray(int size);
    // creates an array of size integers

char *createString(int size);
    // creates a string of size characters

int **createIntMatrix(int rows, int cols);
    // creates a matrix of rows x cols integers

int **createNullMatrix(int rows, int cols);
    // creates a matrix of rows x cols integers, 
    // initialized to 0

void freeIntMatrix(int **matrix, int rows);
    // frees the memory of the matrix

void *safeRealloc(void *ptr, int newSize);
    // reallocates memory and checks if it succeeded

//::::::::::::::::::::::::::: IO.C ::::::::::::::::::::::::::::::://

void printIntArray(int *array, int size);
    // prints the size integers in the given array

void printIntMatrix(int **matrix, int rows, int cols);
    // prints rows x cols integers in the given matrix

void readIntArray(int *array, int size);
    // reads size integers into the given array

void readIntMatrix(int **matrix, int rows, int cols);
    // reads rows x cols integers into the given matrix

int *readInts(int *size);
    // reads integers as long as the input lasts; 
    // returns the array and sets the size

char *readText(int *size);
    // reads characters as long as the input lasts;
    // returns the string and sets the size

char *readLine(int *size);
    // reads chars until newline is encountered
    // returns the string and sets the size

//:::::::::::::::::::::::: SEARCHING.C ::::::::::::::::::::::::::://

int linSearch(int *array, int size, int key);
    // linear search for the key in the array;
    // returns the index of the key in the array, -1 if not found

int binSearch(int *sorted, int size, int key);
    // binary search for the key in the sorted array;
    // returns the index of the key in the array, -1 if not found

//::::::::::::::::::::::::: STRINGS.C :::::::::::::::::::::::::::://

int compareStrings(char *str1, char *str2);
    // case insensitive comparison of two strings;
    // returns 0 if equal, -1 if str1 < str2, 1 if str1 > str2

char *copyString(char *str);
    // returns a copy of the string

void reverseString(char *str);
    // reverses the string in place

int isStrPalindrome(char *start, char *end);
    // checks if a (sub)string is a palindrome between
    // pointers start and end; returns 1 if true, 0 otherwise

//::::::::::::::::::::::::: SORTING.C :::::::::::::::::::::::::::://

int *copySubArray(int *array, int start, int end);
    // returns a copy of the subarray from start to end

void mergeSort(int *array, int size);
    // sorts an array of size integers using merge sort in O(n log n)

void bubbleSort(int *array, int size);
    // sorts an array of size integers using bubble sort in O(n²)

void insertionSort(int *array, int size);
    // sorts an array of size integers using insertion sort in O(n²)

void selectionSort(int *array, int size);
    // sorts an array of size integers using selection sort in O(n²)

void quickSort(int *array, int size);
    // sorts an array of size integers using quick sort 
    // in expected O(n log n)

void countingSort(int *array, int size);
    // sorts an array of size integers using counting sort in O(n);
    // assumes the range is not too large

#endif // FUNCTIONS_H_INCLUDED