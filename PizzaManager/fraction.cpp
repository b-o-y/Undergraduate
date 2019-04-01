/*
* Travis Henderson
* Date last modified: 17/02/22 
*
* Fraction class makes fraction objects that consist
* of  a numerator and denominator that can be set/get.
* all fractions are reduced when set or created.
*/

#include <iostream>
#include "fraction.h"

/* Creates a fraction object */
Fraction::Fraction()
{
}

/* Creates a fraction object with args.  Reduces it to
* lowest common denominator.  If denominator is zero
* then fraction defaults to 1 over 1. Does not allow
* negative fractions.
*/
Fraction::Fraction(int n, int d)
{
  numerator = n < 0 ? -n : n;
  if (d != 0)
    denominator = d < 0 ? -d : d;
  else
    denominator = 1;

  reduce();
}

int Fraction::equals(const Fraction &other)
{
  if (numerator == other.numerator && denominator == other.denominator)
    return 1;
  else
    return 0;
}

void Fraction::setNumerator(int n)
{    
  numerator = n < 0 ? -n : n;

  reduce();
}

/* Denominator cannot be zero, if so, fraction is 1. */
void Fraction::setDenominator(int d)
{
  if (d != 0)
    denominator = d < 0 ? -d : d;
  else
    denominator = 1;

  reduce();
}

void Fraction::printFraction()
{
  std::cout << numerator << "/" << denominator;
}

/* Private method to reduce the fraction */
void Fraction::reduce()
{
  if (numerator != 0 && denominator != 0)
  {
    int a = numerator;
    int b = denominator;
    while (a != b)
      {
        if (a > b)
          a -= b;
        else
          b -= a;
      }
    numerator /= a;
    denominator /= a;
  }
}
