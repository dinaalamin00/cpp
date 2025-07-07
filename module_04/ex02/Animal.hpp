
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
	protected:
		std::string _type;
	public:
		AAnimal();
		AAnimal(const std::string &type);
		AAnimal(const AAnimal &other);
		AAnimal&	operator=(const AAnimal &other);
		virtual ~AAnimal();

		std::string getType() const;
		virtual void    makeSound() const = 0;
};



#endif
 