
/*
  Header:  person.h

  Purpose: Contains function declarations from fraction.c file
*/

#ifndef FRACTION_H
#define FRACTION_H

#define TRUE 1
#define FALSE 0

struct fraction {
  int numerator;
  int denominator;
};

struct fraction add(struct fraction frac1, struct fraction frac2);
int get_sign(struct fraction frac);
void format(struct fraction *frac);
void display(struct fraction frac);
int gcd(int a, int b);

#endif /* FRACTION_H */
