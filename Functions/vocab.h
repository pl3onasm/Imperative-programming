/* file: vocabulary.h
   author: David De Potter
   description: header file for vocabulary.c,
    so you can use it as a library
*/

#ifndef VOCAB_H
#define VOCAB_H

#include <stdio.h>
#include <stdlib.h>

int minimum(int a, int b);
int maximum(int a, int b);
int abs(int a);
int countDigits(int a);
void swap(void *a, void *b, int size);
int reverseInt(int a);
int leftRotate(int a);
int rightRotate(int a);
int isPrime(int a);
int isPerfSquare(int a);
int toBinary(int n, char *str);
int isLeapYear(int year);

int isDivisor(int a, int b);
int GCD (int a, int b);
int LCM (int a, int b);
int areCoprime(int a, int b);
int sumDivisors(int a);

int power(int a, int exp);
int modExp(int a, int exp, int mod);

int isIntPalindrome(int a, int b);
int isPalindrome(int start, int end, char *str);

void *safeMalloc(int n);
void *safeCalloc(int n, int size);
int *createIntArray(int size);
char *createString(int size);
int **createIntMatrix(int rows, int cols);
int **createNullMatrix(int rows, int cols);
void freeIntMatrix(int **matrix, int rows);
void *safeRealloc(void *ptr, int newSize);

void printIntArray(int *array, int size);
void printIntMatrix(int **matrix, int rows, int cols);

void readIntArray(int *array, int size);
void readIntMatrix(int **matrix, int rows, int cols);
int *readIntVector(int *size);
char *readText(int *size);
char *readLine(int *size);

int linSearch(int *array, int size, int key);
int binSearch(int *sorted, int size, int key);

int *copySubArray(int *array, int start, int end);
void mergeSort(int *array, int size);
void bubbleSort(int *array, int size);
void insertionSort(int *array, int size);
void selectionSort(int *array, int size);
void quickSort(int *array, int size);
void countingSort(int *array, int size);

int stringLength(char *str);
int stringCompare(char *str1, char *str2);
char *stringCopy(char *str);
char *reverse(char *str, int len);

#endif