

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include <string>

class Cat : public Animal
{
	protected:

	public:
        Cat();
        Cat(const std::string &name);
        Cat(const Cat &other);
        Cat&	operator=(const Cat &other);
        ~Cat();

};



#endif
