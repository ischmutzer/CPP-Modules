#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
	public:
		Fixed();
		Fixed(const Fixed& source);
		~Fixed();
		Fixed&	operator=(const Fixed& source);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		
	private:
		int					_fixedPoint;
		static const int	_fractionalBits;
};

#endif