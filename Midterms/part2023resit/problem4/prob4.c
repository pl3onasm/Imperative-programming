/* file: prob4.c
   author: David De Potter
   description: PF 1/3rd resit 2023, problem 4, isograms
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void resetCounts (char *chars) {
  /* resets the histogram of characters */
  for (int i = 0; i < 26; i++) chars[i] = 0;
}

int main(int argc, char *argv[]) {
  int wLen = 0, found = 0;
  char ch, word[200], chars[26] = {0};
  
  // read each word and check for isogram
  while (scanf("%s", word) == 1) {
    for (int i = 0; i < strlen(word); i++) {
      ch = word[i];
      if (ch == '.') {
        word[wLen] = '\0';  // replace the dot with null char
        break;
      }
      if ('A' <= ch && ch <= 'Z') ch -= 'A' - 'a';
      if (ch < 'a' || ch > 'z' || chars[ch - 'a'] == 1) {
        wLen = 0;
        break;
      }
      chars[ch - 'a'] = 1;
      word[wLen++] = ch;
    } 
    if (wLen) {
      printf(found ? " " : "");
      printf("%s", word);
      found = 1;
    }
    resetCounts(chars);
    wLen = 0;
  }
  printf("\n");
  return 0;
}