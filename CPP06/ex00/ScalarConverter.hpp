#pragma once

#include <string>

class	ScalarConverter {
	public:
		virtual ~ScalarConverter();

		static void convert(std::string input);
		static void	checkInput(std::string& input);
		// static bool	charCheck(std::string input);
		static bool	intCheck(std::string& input);
		static bool	floatCheck(std::string input);
		// static bool	doubleCheck(std::string input);

	protected:
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter& source);
		ScalarConverter&	operator=(ScalarConverter& source);

		static char		charVal;
		static int		intVal;
		static float	floatVal;
		static double	doubleVal;
};


//making constructor private acomplishes the same as virtual (type) ft() const = 0
//-> it makes the class abstract 