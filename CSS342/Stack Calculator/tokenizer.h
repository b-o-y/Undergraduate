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

#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <iostream>

#include "token.h"
using namespace std;

template <class NumericType>
class Tokenizer {
 public:
  Tokenizer( istream &is ) : in( is ), prevToken( OPAREN ) {
  }
  Token<NumericType> getToken( );

 private:
  istream &in;
  bool getChar( char &ch );

  TokenType prevToken = OPAREN; // it may be necessary for the programming assignment 6
	// ^^^ Assignment description says to add this, but it's already here, just had to initialize it.
};

#include "tokenizer.cpp.h"
#endif

