/* file: prob9.c
* author: David De Potter
* description: extra, problem 9,
*   well-formed strings of parentheses
*/

#include <stdio.h>
#include <stdlib.h>

int countParentheses (int len, int idx, int open, int close) {
  /* counts all possible well formed strings of parentheses */

  // base case: we have reached the end of the string
  if (idx == len) {
    if (open == close) return 1;
    return 0;
  }

  // if open == close, then we must add an open parenthesis
  if (open == close) 
    return countParentheses (len, idx+1, open+1, close);

  // else we can add either an open or a close parenthesis
  return countParentheses (len, idx+1, open+1, close) 
         + countParentheses (len, idx+1, open, close+1);
}

int main (int argc, char *argv[]) {
  int len;

  (void)! scanf("%d", &len);

  // for a string to be well-formed, it must have an even length
  printf("%d\n", len % 2 ? 0 : countParentheses (len, 0, 0, 0));
  
  return 0;
}