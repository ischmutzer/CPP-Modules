#include "Harl.hpp"

int	main() {
	Harl	obj;

	obj.complain("debug");
	obj.complain("info");
	obj.complain("warning");
	obj.complain("error");

	//Invalid
	obj.complain("");
}