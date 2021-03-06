// ----------------- evaluator.cpp.h -----------------
// Travis Henderson
// CSS342A
// Program 6
// 16/05/25
// ---------------------------------------------------
// Purpose: To familiarize students with stacks and
// compilers by implementing functions in a calculator.
//
// Notes: For whatever reason this program will not
// compile in VisualStudio, but it does work on
// the linux shell, so I guess it's okay.  Just
// seems strange.
// ---------------------------------------------------

#ifndef TOKEN_H
#define TOKEN_H

using namespace std;

enum TokenType { 
  EOL,         // end of line                   the same as the original
  VALUE,       // constant                      the same as the original
  OPAREN,      // (                             the same as the original
  CPAREN,      // )                             the same as the original

  NOT,         // ! (logical negation)          reserved for PROG 5
  BIT_COMP,    // ~                             reserved for PROG 5
  
  UN_MINUS,    // -                             reserved for PROG 5
  UN_PLUS,     // +                             reserved for PROG 5

  MULT,        // *                             the same as the original
  DIV,         // /                             the same as the original
  MODULUS,     // %                     

  PLUS,        // -                             the same as the original
  MINUS,       // +                             the same as the original

  SHIFT_L,     // <<
  SHIFT_R,     // >>
  LT,          // < 
  LE,          // <=
  GT,          // > 
  GE,          // >=

  EQUAL,       // ==
  NOTEQUAL,    // !=

  BIT_AND,     // & 
  BIT_EOR,     // ^   
  BIT_IOR,     // | 

  LOG_AND,     // && 
  LOG_OR,      // || 

	// ---- Assignment 6 Implementation ----

	VAR_A,       // variable a
	VAR_B,       // variable b
	VAR_C,       // variable c
	ASSIGN,		// ASSIGNMENT
};

// the class definition is the same as the original
template <class NumericType>
class Token {
 public:
  Token( TokenType tt = EOL, const NumericType & nt = 0 )
    : theType( tt ), theValue( nt ) {
  }

  TokenType getType( ) const {
    return theType;
  }
  const NumericType &getValue( ) const {
    return theValue;
  }
  
 private:
  TokenType   theType;
  NumericType theValue;
};

#endif
