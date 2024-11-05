#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
	private:
		int					_fixedPoint;
		static const int	_bits;
	public:
		Fixed();
		Fixed(const Fixed& source);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBIts(int const raw);
};

#endif