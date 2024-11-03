#include "Role.h"
#include <memory>

void testBaseCase()
{
    auto Warrior = std::make_shared<Role>("Warrior", Ability{100, 0, 5, 5, 0}, RoleType::General);
    auto Knight = std::make_shared<Role>("Knight", Ability{100,0,3,8,0}, RoleType::General);
    Warrior->setNemesis(Knight);
    Warrior->display();
    std::cout << Warrior->isNemesis(Knight) << "\n";
}

void testRoleBasicCase()
{
    auto Warrior = std::make_shared<Role>("Warrior", Ability{100, 0, 5, 5, 0}, RoleType::General);
    auto Knight = std::make_shared<Role>("Knight", Ability{100,0,3,8,0}, RoleType::General);
    auto Sorcerer = std::make_shared<Role>("Sorcerer", Ability{100,6,0,4,0}, RoleType::Magic);
    
    Warrior->setNemesis(Sorcerer);
    Knight->setNemesis(Warrior);
    Sorcerer->setNemesis(Knight);
    
    Warrior->display();
    Knight->display();
    Sorcerer->display();

    std::cout << "Sorcerer's Nemesis is " << Sorcerer->getNemesis()->getName() << "\n";

    std::cout << Warrior->isNemesis(Warrior) << "\n";
    std::cout << Warrior->isNemesis(Knight) << "\n";
    std::cout << Warrior->isNemesis(Sorcerer) << "\n";

    std::cout << Knight->isNemesis(Warrior) << "\n";
    std::cout << Knight->isNemesis(Knight) << "\n";
    std::cout << Knight->isNemesis(Sorcerer) << "\n";

    std::cout << Sorcerer->isNemesis(Warrior) << "\n";
    std::cout << Sorcerer->isNemesis(Knight) << "\n";
    std::cout << Sorcerer->isNemesis(Sorcerer) << "\n";

}

int main()
{
    testRoleBasicCase();
    return 0;
}