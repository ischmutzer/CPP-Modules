#pragma once

#include <string>
#include <stdexcept>

#include <stack>
class RPN {
	public:
		RPN();
		RPN(const RPN& source);
		RPN&	operator=(const RPN& source);
		~RPN();

		void	launch(std::string	input);
		void	checkForInvalidChar(std::string input);
		void	tokenization(std::string& input);

	protected:
	private:
		std::stack<int>		numbers;
		std::stack<char>	operators;
		std::string			cleanInput;
};

//std::stack

//NOTES:

//** RPN **
//Reverse Polish Notation

//Rules for Valid RPN
//1) Operands first:
//Always push numbers to the stack.

//2) Operators act on previous operands:
//For an operator, pop the top two values, compute the result,
//and push it back.

//3) Final stack must have exactly one value:
//If the stack has more or fewer values after processing all
//tokens, the expression is invalid.