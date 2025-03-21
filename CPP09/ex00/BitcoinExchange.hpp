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

		std::string		trim(const	std::string& str);
		void		processFile(const std::string& file);
		void	processDatabase();
		void		launch(const std::string& inputFile);

	protected:
	private:
		std::map<std::string, double>	_btcPrices;
};

//std::map

//NOTES