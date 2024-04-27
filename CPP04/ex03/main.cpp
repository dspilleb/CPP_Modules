#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

void main_test ( void )
{
    std::cout << "\n*-*-*-*-*-*- MAIN_TEST *-*-*-*-*-*-\n " << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
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

}

void deep_copy_test( void )
{
    std::cout << "\n*-*-*-*-*-*- DEEP_COPY_TEST *-*-*-*-*-*- \n" << std::endl;
    AMateria* tmp;
    Character original = Character("Original");
    Character copy = Character("Copy");

    tmp = new Ice();
    original.equip(tmp);
    original.use(0, copy);

    copy.use(0, original);
    copy = original;
    copy.use(0, original);
    original.unequip(0);
    delete tmp;
    tmp = NULL;
    copy.use(0, original); // Should not crash if the copy is deep

}

void inventory_tests( void )
{
    std::cout << "\n*-*-*-*-*-*- INVENTORY_TESTS *-*-*-*-*-*-\n " << std::endl;
    AMateria* tmp;
    Character original = Character("Original");

    tmp = new Ice();
    original.equip(tmp);
    tmp = new Cure();
    original.equip(tmp);
    tmp = new Ice();
    original.equip(tmp);
    tmp = new Cure();
    original.equip(tmp);
    original.equip(tmp); // inventory is full, should do nothing

    original.use(-1, original); // should not crash
    original.use(4, original); // should not crash
    original.use(0, original); //should use an ice spell
    original.use(1, original); // should cure
    original.unequip(3);
    delete tmp;
    original.use(3, original); // should not crash
    original.unequip(3); // should not crash
    original.unequip(-1); // should not crash
    original.unequip(4); // should not crash
}

void MateriaSource_test( void )
{
    std::cout << "\n*-*-*-*-*-*- SOURCE_MATERIA_TEST *-*-*-*-*-*-\n " << std::endl;
    AMateria* tmp;
    IMateriaSource* src = new MateriaSource();

    tmp = src->createMateria("ice"); // should be NULL
    std::cout << "Should be 0 / NULL : " << tmp << std::endl;

    tmp = src->createMateria("cure"); // should be NULL
    std::cout << "Should be 0 / NULL : " << tmp << std::endl;

    tmp = new Ice();
    src->learnMateria(tmp);
    tmp = new Cure();
    src->learnMateria(tmp);
    tmp = new Ice();
    src->learnMateria(tmp);
    tmp = new Cure();
    src->learnMateria(tmp);
    src->learnMateria(tmp); // Inventory should be full
    {
        tmp = src->createMateria("ice");
        std::cout << "Should be 'ice': " << tmp->getType() << std::endl;
        delete tmp; //since it's not stored in the inventory we must free ourselves
    }
    {
        tmp = src->createMateria("cure");
        std::cout << "Should be 'cure': " << tmp->getType() << std::endl;
        delete tmp; //since it's not stored in the inventory we must free ourselves
    }
    delete src;
}

int main(void)
{
    main_test();
    deep_copy_test();
    inventory_tests();
    MateriaSource_test();
    std::cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-\n" << std::endl;
    system("leaks Materia");
    return 0;
}