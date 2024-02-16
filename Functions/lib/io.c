#include "functions.ih"

  // reads chars until delim is encountered,
  // returns a string containing the chars read
char *readUntil(char delim, int *size) {
  CREATE_ARRAY(str, char, 100);
  int len = 0;
  char c;
  while (scanf("%c", &c) == 1 && c != delim) {
    str[len++] = c;
    if (len % 100 == 0)
      str = safeRealloc(str, (len + 100) * sizeof(char));
  }
  str[len] = '\0';
  *size = len;
  return str;
}