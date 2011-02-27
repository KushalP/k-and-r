#include <stdio.h>
#include <ctype.h>

#define NUMBER	1
#define OTHER	0

int getch(void);
void ungetch(int character);
int getfloat(float *pn);

int buf;      // buffer for ungetch
int bufp = 0; // indicates whether the buffer is in use

int main() {
  int c;
  float number;
  
  while ((c = getfloat(&number)) != OTHER && c != EOF) {
    printf("%f\n", number);
  }

  return 0;
}

int getfloat(float *pn) {
  int c, sign;
  float power = 1;

  while (isspace(c = getch()))
    ; // skip whitespace

  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c); // it's not a number!
    return OTHER;
  }

  sign = (c == '-') ? -1 : 1;

  if (c == '+' || c == '-') c = getch();

  if (isdigit(c)) {
    for (*pn = 0; isdigit(c); c = getch()) {
      *pn = 10 * *pn + (c - '0');
    }

    if (c == '.') {
      c = getch();

      while (isdigit(c)) {
        *pn = 10 * *pn + (c - '0');
        power *= 10;
        c = getch();
      }
    }
  } else { // it is a lone '+' or '-' sign
    ungetch(c);
    return OTHER;
  }

  *pn *= (sign / power);

  if (c != EOF) ungetch(c);

  return NUMBER;
}

/**
 * gets a (possible pushed back) character
 */
int getch(void) {
  if (bufp > 0) {
    bufp = 0;
    return buf;
  } else {
    return getchar();
  }
}

/**
 * pushes a character back onto the input
 */
void ungetch(int c) {
  buf = c;
  bufp = 1;
}
