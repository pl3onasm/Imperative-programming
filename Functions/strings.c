#include "functions.ih"

int isStrPalindrome(char *start, char *end) {
  /* checks whether a string is a palindrome;
     start and end are pointers to the first and last
     characters of the (sub)string we want to check */
  while (start < end)
    if (*start++ != *end--) return 0;
  return 1;
}

int compareStrings(char *s1, char *s2) {
  /* case-insensitive string comparison;
     returns -1 if s1 < s2, 0 if s1 == s2, 1 if s1 > s2 */
  int i = 0;
  while (s1[i] && s2[i]) {
    if (tolower(s1[i]) < tolower(s2[i])) return -1;
    if (tolower(s1[i]) > tolower(s2[i])) return 1;
    i++;
  }
  if (s1[i] && !s2[i]) return 1;
  if (!s1[i] && s2[i]) return -1;
  return 0;
}

char *copyString(char *s) {
  /* returns a copy of string s, which must be 
     freed by the caller */
  char *copy = safeMalloc((strlen(s)+1) * sizeof(char));
  strcpy(copy, s);
  return copy;
}

void reverseString(char *str) {
  // reverses a given string in place
  int len = strlen(str);
  for (int i = 0; i < len/2; i++)
    swap(&str[i], &str[len-i-1], sizeof(char));
}
