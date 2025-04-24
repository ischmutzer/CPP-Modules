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

/* int main() {
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

		//####SHORTEST SPAN TESTS####

		//BASIC TEST CASE with overloaded addNumbers ft
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
		//std::cout << "~~\nEmpty Container:\n" << empty.shortestSpan();

		//####LARGEST SPAN TESTS####
		Span	basic(5);
		basic.addNumber(5);
		basic.addNumber(3);
		basic.addNumber(9);
		basic.addNumber(1);
		basic.addNumber(4);

		std::cout << "\n\n##LONGEST SPAN##\n~~\nBasic Test\nLongest span found = " << basic.longestSpan() << std::endl;
		//expected output = 8

		//EMPTY CONTAINER
		Span	lEmpty;
		//std::cout << "~~\nEmpty Container:\n" << lEmpty.longestSpan();

		//SINGLE ELEMENT
		Span	one(1);
		one.addNumber(2);
		//std::cout << "~~\nSingle Number:\n" << one.longestSpan();

		//IDENTICAL ELEMENTS
		Span	igual(4);
		igual.addNumber(3);
		igual.addNumber(3);
		igual.addNumber(3);
		igual.addNumber(3);

		std::cout << "~~\nIdentical Elements\nLongest span found = " << igual.longestSpan() << std::endl;
		//expected output = 0

		//ALREADY SORTED ASCENDING ORDER
		Span	aSort(5);
		aSort.addNumber(1);
		aSort.addNumber(2);
		aSort.addNumber(3);
		aSort.addNumber(4);
		aSort.addNumber(5);

		std::cout << "~~\nAscending Order Sorted \nLongest span found = " << aSort.longestSpan() << std::endl;
		//expected output = 4

		//ALLREADY SORTED DESCENDING ORDER
		Span	dSort(5);
		dSort.addNumber(10);
		dSort.addNumber(8);
		dSort.addNumber(6);
		dSort.addNumber(4);
		dSort.addNumber(2);

		std::cout << "~~\nDescending Order Sorted\nLongest span found = " << dSort.longestSpan() << std::endl;
		//expected output = 8

		//LARGE POSITIVE AND NEGATIVE NUMBERS
		Span	gran(4);
		gran.addNumber(-1000);
		gran.addNumber(500);
		gran.addNumber(9999);
		gran.addNumber(-5000);

		std::cout << "~~\nLarge Positive and Negative Numbers\nLongest span found = " << gran.longestSpan() << std::endl;
		//expected output = 14999

		//ONLY NEGATIVE NUMBERS
		Span	oNeg(4);
		oNeg.addNumber(-10);
		oNeg.addNumber(-50);
		oNeg.addNumber(-3);
		oNeg.addNumber(-100);

		std::cout << "~~\nOnly Negative Numbers\nLongestpan found = " << oNeg.longestSpan() << std::endl;
		//expected output = 97

		//NUMBERS CLOSE TO INT_MAX AND INT_MIN
		Span	maxMin(2);
		maxMin.addNumber(2147483647);
		maxMin.addNumber(-2147483648);

		std::cout << "~~\nMax Int Value and Min Int Value\nLongest span found = " << maxMin.longestSpan() << std::endl;
		//expected output 

		//VECTOR WITH DUPLICATE VALUES AND OUTLIERS

	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
    return 0;
} */

/* #include <iostream>
#include "Span.hpp"

int main() {
    try {
        std::cout << "\n=== ADDITIONAL TESTS ===\n\n";

        //Large-scale test (N = 10 000)
        
            const unsigned int N = 10000;
            Span large(N);
            // fill with even numbers: so shortest span = 2, longest = (N−1)*2
            for (unsigned int i = 0; i < N; ++i)
                large.addNumber(i * 2);
            std::cout << "Large-scale test (N=" << N << ")\n";
            std::cout << " shortestSpan() = " << large.shortestSpan() << "  (expected 2)\n";
            std::cout << " longestSpan()  = " << large.longestSpan()  << "  (expected " << (long long)(N-1)*2 << ")\n\n";
        } catch (const std::exception& e) {
			std::cerr << "Unexpected exception: " << e.what() << "\n"; }

        // 2) Zero-capacity test
        try {
            Span zero(0);
            zero.addNumber(1);
            std::cout << "Zero-capacity test: unexpectedly succeeded\n";
        } catch (const std::exception& e) {
            std::cout << "Zero-capacity test: caught \"" << e.what() << "\"\n\n"; }

        // 3) Const-correctness test
        try {
            Span s(3);
            s.addNumber(10);
            s.addNumber(20);
            s.addNumber(30);
            const Span& cs = s;
            // shortestSpan() is const—this should compile and run:
            std::cout << "Const test shortestSpan() = " << cs.shortestSpan() << "  (expected 10)\n";
            // longestSpan() must be made const in your class to compile this line:
            std::cout << "Const test longestSpan()  = " << cs.longestSpan()  << "  (expected 20)\n";
        } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << "\n"; }

    return 0;
} */
