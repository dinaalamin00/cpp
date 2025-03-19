
#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout<< "FragTrap Constructor" <<std::endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::FragTrap(const std::string &_name) : ClapTrap(_name)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout<< "FragTrap "<<_name<< " created!" <<std::endl;
}


FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << "FragTrap Copy Constructor called" << std::endl;
    if (this != &other)
       ClapTrap::operator=(other);
    return *this;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout<< "FragTrap Copy Constructor called" <<std::endl;
}

FragTrap::~FragTrap()
{
	std::cout<< "FragTrap Destructor" <<std::endl;
}

void	FragTrap::attack(const std::string &target)
{
	if (energyPoints <= 0 || hitPoints <= 0)
	{
		std::cout<< "FragTrap " <<name<<  " can't attack!" <<std::endl;
		return ;
	}
	std::cout<< "FragTrap " <<name<< " attacks " <<target<< ", causing " <<attackDamage<< " points of damage!";
	std::cout<< std::endl;
	energyPoints = energyPoints - 1;

}

void FragTrap::highFivesGuys()
{
	std::cout<< "FragTrap " <<name<< "  high-fives request." <<std::endl;
}
