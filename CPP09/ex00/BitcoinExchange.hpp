#pragma once

#include <exception>
#include <iostream>
#include <map>
#include <fstream>

class	btc {
	public:
		btc();
		btc(const btc& source);
		btc&	operator=(const btc& source);
		~btc();

		void	processInput(const std::string& file);

	protected:
	private:
		std::map<int, int>	map;
};

//std::map