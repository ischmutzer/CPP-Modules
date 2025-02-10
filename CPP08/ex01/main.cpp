#include "Span.hpp"

//subject main
/* int main()
{
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;

return 0;
} */

int main() {
	try {
		//EXCEPTION CHECK
		Span	sp(4);
		sp.addNumber(1);
		sp.addNumber(3);
		sp.addNumber(5);
		sp.addNumber(7);
		//sp.addNumber(7);

		//EMPTY CONTAINER CHECK
		Span	emptySp;
		//sp.addNumber(1);

		//NEGATIVE CONTAINER CHECK*****???
		Span	negSp(-1); //que pasa aqui ***
		negSp.addNumber(2); //expected invalid format

		//SHORTEST SPAN BASIC TEST CASE with overloaded addNumbers ft
		Span				overload(5);
		std::vector<int>	num;
		num.push_back(5);
		num.push_back(3);
		num.push_back(9);
		num.push_back(1);
		num.push_back(4);

		overload.addNumber(num);
		std::cout << "##SHORTEST SPAN##\n~~\nBasic Test Case\nShortest span found = " << overload.shortestSpan() << std::endl;
		//expected output = 1

		//ALL IDENTICAL NUMBERS CASE
		Span	id(4);
		id.addNumber(7);
		id.addNumber(7);
		id.addNumber(7);
		id.addNumber(7);

		std::cout << "~~\nAll Identical Numbers\nShortest span found = " << id.shortestSpan() << std::endl;
		//expected output = 0

		//NEGATIVE NUMBERS
		Span	neg(5);
		neg.addNumber(-5);
		neg.addNumber(-3);
		neg.addNumber(-9);
		neg.addNumber(-1);
		neg.addNumber(-4);

		std::cout << "~~\nNegative Numbers\nShortest span found = " << neg.shortestSpan() << std::endl;
		//expected output = 1

		//MIXED POSITVE AND NEGATIVE NUMBERS
		Span	mix(5);
		mix.addNumber(-2);
		mix.addNumber(5);
		mix.addNumber(-8);
		mix.addNumber(3);
		mix.addNumber(0);

		std::cout << "~~\nMixed Numbers\nShortest span found = " << mix.shortestSpan() << std::endl;
		//expected output = 2

		//LARGE NUMBERS
		Span	large(4);
		large.addNumber(1000000);
		large.addNumber(2000000);
		large.addNumber(1500000);
		large.addNumber(3000000);

		std::cout << "~~\nLarge Numbers\nShortest span found = " << large.shortestSpan() << std::endl;
		//expected output = 500000

		//TWO NUMBERS
		Span	two(2);
		two.addNumber(10);
		two.addNumber(20);

		std::cout << "~~\nTwo Numbers\nShortest span found = " << two.shortestSpan() << std::endl;
		//expected output = 10

		//REPEATED NUMBERS
		Span	rep(6);
		rep.addNumber(5);
		rep.addNumber(5);
		rep.addNumber(5);
		rep.addNumber(10);
		rep.addNumber(10);
		rep.addNumber(15);

		std::cout << "~~\nRepeated Numbers\nShortest span found = " << rep.shortestSpan() << std::endl;
		//expected output = 0

		//LARGE DATASET
		Span	lData(11);
		lData.addNumber(1);
		lData.addNumber(5);
		lData.addNumber(10);
		lData.addNumber(15);
		lData.addNumber(20);
		lData.addNumber(25);
		lData.addNumber(30);
		lData.addNumber(35);
		lData.addNumber(40);
		lData.addNumber(45);
		lData.addNumber(50);

		std::cout << "~~\nLarge Dataset\nShortest span found = " << lData.shortestSpan() << std::endl;
		//expected output = 4

		//DUPLICATED MIN SPAN
		Span	dupli(10);
		dupli.addNumber(10);
		dupli.addNumber(20);
		dupli.addNumber(30);
		dupli.addNumber(40);
		dupli.addNumber(50);
		dupli.addNumber(60);
		dupli.addNumber(70);
		dupli.addNumber(80);
		dupli.addNumber(90);
		dupli.addNumber(100);

		std::cout << "~~\nDuplicated Min Diff\nShortest span found = " << dupli.shortestSpan() << std::endl;
		//expected output = 10

		//~~ EDGE CASES ~~

		//SINGLE NUMBER
		Span	sin(1);
		sin.addNumber(42);

		//std::cout << "~~\nSingle Number:\n" << sin.shortestSpan();
		
		//EMPTY CONTAINER
		Span	empty;
		//std::cout << "~~\nEmpty container:\n" << empty.shortestSpan();

	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
    return 0;
}
