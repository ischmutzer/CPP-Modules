#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
class ClapTrap {
	public:
		ClapTrap();
		ClapTrap(const ClapTrap& source);
		ClapTrap(std::string name);
		ClapTrap(std::string name, unsigned int health, unsigned int energy, unsigned int damage);
		ClapTrap&	operator=(const ClapTrap& source);
		~ClapTrap();

		std::string	getName();
		int			getHealth();
		int			getEnergy();
		int			getAttackDamage();

		void	setHealth(unsigned int amount);
		void	setEnergy(unsigned int amount);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	private:
		std::string	_name;
		unsigned int			_hitPoints;
		unsigned int			_energyPoints;
		unsigned int			_attackDamage;
};

#endif