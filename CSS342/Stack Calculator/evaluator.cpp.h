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



// Public routine that performs the evaluation. Examines the postfix machine
// to see if a single result is left and if so, return it; otherwise prints
// error.
template<class NumericType>
NumericType Evaluator<NumericType>::getValue() {

	Tokenizer<NumericType> tok(str);
	Token<NumericType> lastToken;

	do {
		lastToken = tok.getToken();
		processToken(lastToken);
	} while (lastToken.getType() != EOL);

	if (postFixStack.empty()) {
		cerr << "Missing operatnd!" << endl;
		return 0;
	}

	NumericType theResult = postFixStack.back();
	postFixStack.pop_back();
	postFixVarStack.pop_back();
	if (!postFixStack.empty())
		cerr << "Warning: missing operators!" << endl;

	return theResult;
}

// After token is read, use operator precedence parsing algorithm to process
// it; missing opening parentheses are detected here.
template<class NumericType>
void Evaluator<NumericType>::
processToken(const Token<NumericType> &lastToken) {
	TokenType topOp;
	TokenType lastType = lastToken.getType();

	switch (lastType) {
	case VALUE:
		postFixStack.push_back(lastToken.getValue());
		postFixVarStack.push_back(' ');
		return;

	case CPAREN:
		while ((topOp = opStack.back()) != OPAREN &&
			topOp != EOL)
			binaryOp(topOp);
		if (topOp == OPAREN)
			opStack.pop_back(); // get rid of opening parethesis
		else
			cerr << "Missing open parenthesis" << endl;
		break;

		// ------- Variables --------
	case VAR_A:
		postFixStack.push_back(var_a);
		postFixVarStack.push_back('a');
		return;
	case VAR_B:
		postFixStack.push_back(var_b);
		postFixVarStack.push_back('b');
		return;
	case VAR_C:
		postFixStack.push_back(var_c);
		postFixVarStack.push_back('c');
		return;

	default: // general operator case
		while (PREC_TABLE[lastType].inputSymbol <=
			PREC_TABLE[topOp = opStack.back()].topOfStack)
			binaryOp(topOp);

		if (lastToken.getType() != EOL)
			opStack.push_back(lastType);

		break;
	}
}

// Process an operator by taking two items off the postfix stack, applying
// the operator, and pushing the result.
// Print error if missing closing parenthesis or division by 0.
template<class NumericType>
void Evaluator<NumericType>::binaryOp(TokenType topOp) {
	if (topOp == OPAREN) {
		cerr << "Unbalanced parenthss" << endl;
		opStack.pop_back();
		return;
	}
	NumericType rhs = getTop();
	NumericType lhs;

	// if topOp is a unary operator, then don't get lhs, because it gives an operand error.
	if (!((topOp == UN_PLUS) || (topOp == UN_MINUS) || (topOp == NOT) || (topOp == BIT_COMP) || (topOp == ASSIGN))) 
	{
		if (topOp == ASSIGN)
		{
			lhs = getTopVar(); // If it's an assignment, then that means a variable is getting assigned, so go to the variable stack.
		}
		else
		{
			lhs = getTop();  // Otherwise, it's just a normal unary operation.
		}
	}

	if (topOp == PLUS)
	{
		postFixStack.push_back(lhs + rhs);
		postFixVarStack.push_back(' ');
	}
	else if (topOp == MINUS)
	{
		postFixStack.push_back(lhs - rhs);
		postFixVarStack.push_back(' ');
	}
	else if (topOp == MULT)
	{
		postFixStack.push_back(lhs * rhs);
		postFixVarStack.push_back(' ');
	}
	else if (topOp == DIV)
		if (rhs != 0)
		{
			postFixStack.push_back(lhs / rhs);
			postFixVarStack.push_back(' ');
		}
		else {
			cerr << "Division by zero" << endl;
			postFixStack.push_back(lhs);
			postFixVarStack.push_back(' ');
		}
	else if (topOp == MODULUS) { // For the modulo operator
		if (rhs != 0)
		{
			postFixStack.push_back(lhs % rhs);
			postFixVarStack.push_back(' ');
		}
		else {
			cerr << "MODULUS by zero" << endl;
			postFixStack.push_back(lhs);
			postFixVarStack.push_back(' ');
		}
	}

	else if (topOp == BIT_EOR) { // For exponents, can't do negative exponents since it works with ints.
		if (rhs == 0) {
			lhs = 1; // Not sure if it's necessary to do this, but figured I should I push a numerictype and not an int.
			postFixStack.push_back(lhs);
			postFixVarStack.push_back(' ');
		}
		else if (lhs == 0 && rhs != 0) {  // zero raised to ANY exponent is zero.
			lhs = 0;
			postFixStack.push_back(lhs);
			postFixVarStack.push_back(' ');
		}
		else if (lhs != 0 && rhs > 0) // 'normal'  exponent operations
		{
			int exp = lhs;
			for (int i = 1; i < rhs; i++) { // Multiply lhs by itself rhs times.
				lhs *= exp;
			}
			postFixStack.push_back(lhs);
			postFixVarStack.push_back(' ');
		}
	}

	else if (topOp == LT) // Less than
	{
		postFixStack.push_back(lhs < rhs);
		postFixVarStack.push_back(' ');
	}
	else if (topOp == LE) // Less than or equal than
	{
		postFixStack.push_back(lhs <= rhs);
		postFixVarStack.push_back(' ');
	}
	else if (topOp == SHIFT_L) // Shift left
	{
		postFixStack.push_back(lhs << rhs);
		postFixVarStack.push_back(' ');
	}

	else if (topOp == GT) // Greater than
	{
		postFixStack.push_back(lhs > rhs);
		postFixVarStack.push_back(' ');
	}
	else if (topOp == GE) // Greater than or equal than
	{
		postFixStack.push_back(lhs >= rhs);
		postFixVarStack.push_back(' ');
	}
	else if (topOp == SHIFT_R) // Shift right
	{
		postFixStack.push_back(lhs >> rhs);
		postFixVarStack.push_back(' ');
	}

	else if (topOp == EQUAL) // they equal?
	{
		postFixStack.push_back(lhs == rhs);
		postFixVarStack.push_back(' ');
	}
	else if (topOp == NOTEQUAL) // are they not equal?
	{
		postFixStack.push_back(lhs != rhs);
		postFixVarStack.push_back(' ');
	}

	else if (topOp == LOG_AND) // Logical and
	{
		postFixStack.push_back(lhs && rhs);
		postFixVarStack.push_back(' ');
	}
	else if (topOp == BIT_AND) // bit and
	{
		postFixStack.push_back(lhs & rhs);
		postFixVarStack.push_back(' ');
	}

	else if (topOp == LOG_OR)  // logical or
	{
		postFixStack.push_back(lhs || rhs);
		postFixVarStack.push_back(' ');
	}
	else if (topOp == BIT_IOR) // bit or
	{
		postFixStack.push_back(lhs | rhs);
		postFixVarStack.push_back(' ');
	}

	// --------- PROGRAM 6 IMPLEMENTATION ---------
	else if (topOp == UN_PLUS)  // unary '+'
	{
		postFixStack.push_back(rhs);  // Nothing needs to be done, the value is fine as it is.
		postFixVarStack.push_back(' ');
	}
	else if (topOp == UN_MINUS)  // unary '-'
	{
		postFixStack.push_back(rhs*(-1)); // Return the opposite of the value.
		postFixVarStack.push_back(' ');
	}

	else if (topOp == NOT) // logical negation.
	{
		postFixStack.push_back(!rhs);
		postFixVarStack.push_back(' ');
	}
	else if (topOp == BIT_COMP) // '~' don't know what this is called, but that's what this is for.
	{
		postFixStack.push_back(~rhs);
		postFixVarStack.push_back(' ');
	}

	else if (topOp == ASSIGN)  // Assignment operator.
	{
		// Then need to check what variable it is specifically.
		if (postFixStack.back() == var_a)
		{
			var_a = rhs;  // This actually assigns the variable.
			postFixStack.pop_back(); // Since back is a void method, pop_back needs to be done to destroy the element that had the variable assigned to nothing.
			postFixStack.push_back(var_a);  // Push the variable that now has an assignment back on to the stack.
			postFixVarStack.push_back(' ');
		}
		else if (postFixStack.back() == var_b)
		{
			var_b = rhs;  // This actually assigns the variable.
			postFixStack.pop_back();  // Since back is a void method, pop_back needs to be done to destroy the element that had the variable assigned to nothing.
			postFixStack.push_back(var_b);  // Push the variable that now has an assignment back on to the stack.
			postFixVarStack.push_back(' ');
		}
		else if (postFixStack.back() == var_c)
		{
			var_c = rhs;  // This actually assigns the variable.
			postFixStack.pop_back();  // Since back is a void method, pop_back needs to be done to destroy the element that had the variable assigned to nothing.
			postFixStack.push_back(var_c);  // Push the variable that now has an assignment back on to the stack.
			postFixVarStack.push_back(' ');
		}
	}

	opStack.pop_back();
}

// top and pop the postfix machine stack; return the result.
// If the stack is empty, print an error message.
template<class NumericType>
NumericType Evaluator<NumericType>::getTop() {
	if (postFixStack.empty()) {
		cerr << "Missing operand" << endl;
		return 0;
	}

	NumericType tmp = postFixStack.back();
	postFixStack.pop_back();
	return tmp;
}

template<class NumericType>
NumericType Evaluator<NumericType>::getTopVar() {
	if (postFixVarStack.empty()) {
		cerr << "Missing operand from getTopVar" << endl;
		return 0;
	}


	NumericType tmp = postFixVarStack.back();
	postFixVarStack.pop_back();
	return tmp;
}
