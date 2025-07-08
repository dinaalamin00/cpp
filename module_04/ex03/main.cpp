#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"


void basicTests() // subject main()
{
    std::cout << "----------- BASIC TESTS -----------" << std::endl;

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("CharacterName");
    AMateria* tmp;

    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob); 
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    std::cout << "-----------------------------------\n" << std::endl;
}

void inventoryTests()
{
    std::cout << "------- INVENTORY TESTS -------" << std::endl;

    ICharacter* me = new Character("Character-1");
    ICharacter* enemy = new Character("Enemy");

    AMateria* ice1 = new Ice();
    AMateria* cure1 = new Cure();
    AMateria* ice2 = new Ice();
    AMateria* cure2 = new Cure();
    AMateria* extra = new Cure();

    // Fill inventory
    me->equip(ice1);
    me->equip(cure1);
    me->equip(ice2);
    me->equip(cure2);

    std::cout << "\nTrying to equip a 5th Materia (should fail silently):" << std::endl;
    me->equip(extra);

    std::cout << "\nUsing all inventory slots:" << std::endl;
    for (int i = 0; i < 4; ++i) {
        me->use(i, *enemy);
    }

    std::cout << "\nTrying to use slot 4 (should do nothing):" << std::endl;
    me->use(4, *enemy);

    std::cout << "\nUnequipping slot 1 (Cure):" << std::endl;
    me->unequip(1);

    std::cout << "\nTrying to use unequipped slot 1 (should do nothing):" << std::endl;
    me->use(1, *enemy);

    std::cout << "\nEquipping a new Cure into freed slot 1:" << std::endl;
    me->equip(extra);
    me->use(1, *enemy);

    delete enemy;
    delete me;

    std::cout << "-----------------------------------\n" << std::endl;
}

void deepCopyTests()
{
    std::cout << "------- DEEP COPY TESTS -------" << std::endl;

     ICharacter* original = new Character("original");
    original->equip(new Ice());
    original->equip(new Cure());


    ICharacter* bob = new Character("bob");

    std::cout << "Original Character uses Materias:" << std::endl;
    original->use(0, *bob); 
    original->use(1, *bob); 

    std::cout << "Copy Character uses Materias:" << std::endl;
    original->unequip(0);
    original->equip(new Ice());

    std::cout << "After modification - Original uses Materias:" << std::endl;
    original->use(0, *bob); 
    original->use(1, *bob); 


    delete bob;
    delete original;
    std::cout << "--------------------------------------\n" << std::endl;
}

void sourceTests()
{
    std::cout << "------- MATERIA SOURCE TESTS -------" << std::endl;

    IMateriaSource* src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    AMateria* ice1 = src->createMateria("ice");
    AMateria* cure1 = src->createMateria("cure");

    if (ice1) std::cout << "Successfully created ice Materia" << std::endl;
    if (cure1) std::cout << "Successfully created cure Materia" << std::endl;

    AMateria* unknown = src->createMateria("fire");
    if (!unknown) std::cout << "Unknown Materia could not be created" << std::endl;

    src->learnMateria(new Ice());  
    src->learnMateria(new Cure()); 
    src->learnMateria(new Ice()); 

    delete ice1;
    delete cure1;
    delete src;

    std::cout << "------------------------------------------\n" << std::endl;
}


int main() {
    basicTests(); // subject main()
    inventoryTests();
    deepCopyTests();
    sourceTests();

    return 0;
}