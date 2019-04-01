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

int main()
{
  Fraction x(-2, 5), y(-14, -16), z;

  std::cout << "x:"; y.printFraction(); std::cout << std::endl;

  z.setNumerator(10);
  z.setDenominator(0);
  std::cout << "z: "; z.printFraction(); std::cout << std::endl;

  z.setNumerator(-7);
  z.setDenominator(-8);

  Fraction b(0, 0);
std::cout << "hello\n";
  std::cout << b.equals(z) << std::endl;

  std::cout << y.equals(z) << std::endl;
  x.setNumerator(20);
  std::cout << "y:"; x.printFraction(); std::cout << std::endl;

  return 0;
}
