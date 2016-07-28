/* Calculator with + - * / uses reverse Polish notation */
#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define MAXOP 100  /* max size of operand of operator */

int main(void) {
  
  int type;
  double op2;
  char s[MAXOP];
  
  while ( (type = getop(s)) != EOF ) {
    switch (type) {
      case NUMBER: 
        push(atof(s));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0) {
          push(pop() / op2);
        } else {
          printf("Error: zero division\n");
        }
        break;
      case '\n':
        printf("\t%.8g\n", pop());
        break;
      default: 
        printf("error: unknown thing %s\n", s);
        break;
    }
  }
  return 0;
}