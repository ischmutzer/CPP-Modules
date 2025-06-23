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
		bool			isWord(const std::string& word);

		bool			dbNumberValidation(const std::string& key, const std::string& price);
		bool			dateValidation(const std::string& key);
		bool			inputDateValidation(const std::string& key);

		bool			inNumberValidation(const std::string& val);
		double			getExchangeRate(const std::string& key);

		void			calculateRateXValue(double rate, const std::string& key);

		void			processFile(const std::string& file);
		void			processDatabase();
		void			launch(const std::string& inputFile);

	protected:
	private:
		std::map<std::string, double>	_btcPrices;
		double							_value;
		std::string						_date;
};

//std::map

//NOTES