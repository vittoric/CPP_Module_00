#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.attack();
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }

    std::cout << std::endl;

    {
        std::cout << "==== Testing HumanA with weapon ====" << std::endl;
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
   std::cout << std::endl;
    {
        std::cout << "==== Testing HumanB without weapon ====" << std::endl;
        HumanB jim("Jim");
        jim.attack(); // Jim no tiene arma todavía
    }
   std::cout << std::endl;
    {
        std::cout << "==== Testing HumanB with weapon ====" << std::endl;
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
   std::cout << std::endl;
    {
        std::cout << "==== Testing multiple weapons with HumanA ====" << std::endl;
        Weapon sword = Weapon("sharp sword");
        Weapon axe = Weapon("mighty axe");
        HumanA alice("Alice", sword);
        alice.attack();
        sword.setType("golden sword");
        alice.attack();

        std::cout << "Alice switches to another weapon!" << std::endl;
        // Simulate Alice picking up a new weapon (manually changing reference)
        axe.setType("silver axe");
        alice.attack(); // Should still attack with the sword because reference hasn't changed
    }
   std::cout << std::endl;
    {
        std::cout << "==== Testing multiple weapons with HumanB ====" << std::endl;
        Weapon sword = Weapon("sharp sword");
        Weapon axe = Weapon("mighty axe");
        HumanB charlie("Charlie");
        charlie.setWeapon(sword);
        charlie.attack();
        sword.setType("golden sword");
        charlie.attack();

        std::cout << "Charlie switches to another weapon!" << std::endl;
        charlie.setWeapon(axe); // Now Charlie should use the axe
        charlie.attack();
        axe.setType("silver axe");
        charlie.attack();
    }
    return 0;
}