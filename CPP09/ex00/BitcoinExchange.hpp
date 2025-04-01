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
		bool			dateValidation(const std::string& key);
		bool			numberValidation(const std::string& key, const std::string& price);
		bool			isWord(const std::string& word);
		void			processFile(const std::string& file);
		void			processDatabase();
		void			launch(const std::string& inputFile);

	protected:
	private:
		std::map<std::string, double>	_btcPrices;
		double							_newValue;
};

//std::map

//NOTES