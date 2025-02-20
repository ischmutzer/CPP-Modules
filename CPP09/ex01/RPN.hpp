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

		void	processInput(std::string	input);
		void	tokenization(const std::string& expression);
		void	validateToken(const std::string& expression);
		bool	isOperator(char c) const;
		void	printResult();

	protected:
	private:
		std::stack<long long>		numbers;
		std::string					cleanInput;
};


//** OLD IMPLEMENTATION **
// void	checkForInvalidChar(std::string& input);
// void	tokenization(std::string& input);

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



// ** STACK DATA STRUCT **
//Operations:
//	->push: adds to the stack
//	->pop: removes the top element from the stack
//	->top: accesses the top element without removing it 