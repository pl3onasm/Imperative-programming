/* 
  file: prob6-2.c
  author: David De Potter
  description: extra, problem 6, balanced brackets
  version: 6.2, using the clib library
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../Functions/clib/clib.h"

int isBalanced(char *s, int len) {
  CREATE_ARRAY(char, stack, len);
  int top = 0;
  for (int i = 0; i < len; i++) {
    if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
      stack[top++] = s[i];
      continue;
    } 
    --top;
    if (top < 0 
      || (s[i] == ')' && stack[top] != '(') 
      || (s[i] == ']' && stack[top] != '[') 
      || (s[i] == '}' && stack[top] != '{')) {
        free(stack);
        return 0;
      }
  }
  free(stack);
  return top == 0;  
}


int main (int argc, char *argv[]) {
  int len;
  READ_UNTIL(char, str, "%c", '\n', len);
  
  printf(isBalanced(str, len) ? "YES\n" : "NO\n");

  free(str);
  return 0;
}