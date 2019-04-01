/*
* Travis Henderson
* Date last modified: 17/02/22 
*
* Fraction class makes fraction objects that consist
* of  a numerator and denominator that can be set/get.
* all fractions are reduced when set or created.
*/

#ifndef FRACTION_H
#define FRACTION_H

class Fraction
{
  public:
    Fraction(); // Default no args constructor.
    Fraction(int, int); // Constructor which initializes data.
        
    int equals(const Fraction &other); // Compares this to other.
        
    // Getters and setters.
    int getNumerator();
    int getDenominator();
    void setDenominator(int);
    void setNumerator(int);

    void printFraction();
        
  private:
    int numerator;
    int denominator;
        
    void reduce(); // Reduce any fractions to LCD.
};
#endif
  
  
