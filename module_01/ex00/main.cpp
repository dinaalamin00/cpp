#include "Zombie.hpp"

int main()
{
    Zombie  stackZomb();
    Zombie  *heapZomb;
    
    heapZomb = newZombie("heap");
    heapZomb->announce();
    delete(heapZomb);

    randomChump("Stack");



    // z1 = newZombie("ZombieHeap")   // Allocated on heap
    // z1->announce()
    // delete z1   // Destructor is called

    // randomChump("ZombieStack")   // Created and destroyed automatically
}
