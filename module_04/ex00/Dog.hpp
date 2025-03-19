

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include <string>

class Dog : public Animal
{
	protected:

	public:
        Dog();
        Dog(const std::string &name);
        Dog(const Dog &other);
        Dog&	operator=(const Dog &other);
            ~Dog();

};



#endif
