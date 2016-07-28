#include <stdio.h>
#include "calc.h"

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;     /* next free position in buf */

// get a character (possibly pushed back)
int getch(void) {
  return (bufp > 0) ? buf[--bufp] : getchar();
}

// push character back on input
void ungetch(int c) {
  if (bufp >= BUFSIZE) 
    printf("ungetch: too many characters\n");
  else 
    buf[bufp++] = c;
}