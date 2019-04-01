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

template <class NumericType>
bool Tokenizer<NumericType>::getChar(char &ch) {
	char tmp;

	// skip blanks
	while (in.get(tmp) && tmp == ' ');

	// read a char 
	if (in.good() && tmp != '\n'&& tmp != '\0') {
		ch = tmp;
		return true; // if it is not a delimiter
	}
	else
		return false; // if it's a delimitter
}

template <class NumericType>
Token<NumericType> Tokenizer<NumericType>::getToken() {

	char ch;
	NumericType theValue;

	if (getChar(ch) == true) {
		char a; // This will be used if I ever need to see what the next char is.
		switch (ch) {
		case '/':
			prevToken = DIV;
			return DIV;
		case '*':
			prevToken = MULT;
			return MULT;
		case '(':
			prevToken = OPAREN;
			return OPAREN;
		case ')':
			prevToken = CPAREN;
			return CPAREN;
		case '+':
			if (prevToken == OPAREN)  // If so then this is a unary '+'
			{
				prevToken = UN_PLUS;
				return UN_PLUS;
			}
			prevToken = PLUS;
			return PLUS;
		case '-':
			if (prevToken == OPAREN)  // If so then this is a unary '-'
			{
				prevToken = UN_MINUS;
				return UN_MINUS;
			}
			prevToken = MINUS;
			return MINUS;
		case '%':
			prevToken = MODULUS;
			return MODULUS;
		case '^':
			prevToken = BIT_EOR;
			return BIT_EOR;
		case '<':
			a = in.get(); // Get next char to see what kind of '<' it is.
			if (a == '<')
			{
				prevToken = SHIFT_L;
				return SHIFT_L;
			}
			if (a == '=')
			{
				prevToken = LE;
				return LE;
			}
			in.putback(a); // Push back if it's not an operator.
			prevToken = LT;
			return LT;
		case '>':
			a = in.get(); // Get next char to see what kind of '<' it is.
			if (a == '>')
			{
				prevToken = SHIFT_R;
				return SHIFT_R;
			}
			if (a == '=')
			{
				prevToken = GE;
				return GE;
			}
			in.putback(a); // Push back if it's not an operator.
			prevToken = GT;
			return GT;
		case '=':
			a = in.get(); // Get next char
			if (a == '=')
			{
				prevToken = EQUAL;
				return EQUAL;
			}
			in.putback(a); // Push back if it's not an operator.
			prevToken = ASSIGN;
			return ASSIGN;
		case '!':
			a = in.get(); // Get next char
			if (a == '=')
			{
				prevToken = NOTEQUAL;
				return NOTEQUAL;
			}
			in.putback(a); // Push back if it's not an operator.
			prevToken = NOT;
			return NOT;
		case '&':
			a = in.get(); // Get next char
			if (a == '&')
			{
				prevToken = LOG_AND;
				return LOG_AND;
			}
			in.putback(a); // Push back if it's not an operator.
			prevToken = BIT_AND;
			return BIT_AND;
		case '|':
			a = in.get(); // Get next char
			if (a == '|')
			{
				prevToken = LOG_OR;
				return LOG_OR;
			}
			in.putback(a); // Push back if it's not an operator.
			prevToken = BIT_IOR;
			return BIT_IOR;
		case '~':
			return BIT_COMP;
		// ----- Variable assignments ------
		case 'a':
			prevToken = VAR_A;
			return Token<NumericType>(VAR_A, 0);
		case 'b':
			prevToken = VAR_B;
			return Token<NumericType>(VAR_B, 0);
		case 'c':
			prevToken = VAR_C;
			return Token<NumericType>(VAR_C, 0);


		default:
			in.putback(ch);
			if (!(in >> theValue)) {
				cerr << "Parse error" << endl;
				prevToken = EOL;
				return EOL;
			}
			prevToken = VALUE;
			return Token<NumericType>(VALUE, theValue);
		}
	}
	prevToken = EOL;
	return prevToken;
}
