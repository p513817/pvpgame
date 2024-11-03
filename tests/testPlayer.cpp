#include <vector>

#include "Player.h"
#include "Role.h"
#include "Equipment.h"
#include "AttackStrategy.h"

void baseCase()
{
    std::cout << "\n======================================\n";
    std::cout << "Base Case" << "\n";
    auto Warrior = std::make_shared<Role>("Warrior", Ability{100, 0, 5, 5, 0}, RoleType::General);    
    Player p1{"Max", Warrior};
    p1.display();
    p1.getAbility();

}

void equipCase()
{
    std::cout << "\n======================================\n";
    std::cout << "Equip Case" << "\n";

    auto Warrior = std::make_shared<Role>("Warrior", Ability{100, 0, 5, 5, 0}, RoleType::General);
    auto Sword = std::make_shared<Equipment>("Sword", Ability{0, 0, 5, 0, 0});
    auto Shield = std::make_shared<Equipment>("Shield", Ability{0, 0, 2, 3, 0});
    
    Player p1{"Max", Warrior};
    p1.setEquipment(Sword);
    p1.setEquipment(Shield);
    p1.display();
}

void testSameRoleSameEquipmentCase()
{
    std::cout << "\n======================================\n";
    std::cout << "Same Role Case" << "\n";

    auto Warrior = std::make_shared<Role>(
        "Warrior", Ability{100, 0, 5, 5, 0}, RoleType::General);
    auto Sword = std::make_shared<Equipment>("Sword", Ability{0, 0, 5, 0, 0});
    auto Shield = std::make_shared<Equipment>("Shield", Ability{0, 0, 2, 3, 0});
    
    Player p1{"Max", Warrior};
    p1.setEquipment(Sword);
    p1.setEquipment(Shield);
    p1.display();

    Player p2{"Joe", Warrior};
    p2.setEquipment(Shield);
    p2.display();
}

void sharedPtrCase()
{
    std::cout << "\n======================================\n";
    std::cout << "Shared Pointer Case" << "\n";

    auto Warrior = std::make_shared<Role>("Warrior", Ability{100, 0, 5, 5, 0}, RoleType::General);
    
    Player p1{"Max", Warrior};
    p1.getRole()->display();
    if(p1.getEquipment())
        p1.getEquipment()->display();
}


void attackEmptyCase()
{
    std::cout << "\n======================================\n";
    std::cout << "Attack Case\n";

    auto Warrior = std::make_shared<Role>("Warrior", Ability{100, 0, 6, 3, 0}, RoleType::General);
    auto Knight = std::make_shared<Role>("Knight", Ability{100,0,3,6,0}, RoleType::General);
    
    auto Sword = std::make_shared<Equipment>("Sword", Ability{0, 0, 6, 0, 0});
    auto Shield = std::make_shared<Equipment>("Shield", Ability{0, 0, 2, 3, 0});

    auto p1 = std::make_shared<Player>("A", Warrior);
    auto p2 = std::make_shared<Player>("B", Knight);

    p1->setEquipment(Sword);
    p1->display();

    p2->setEquipment(Shield);
    p2->display();

    // Simulate attack
    p1->attack(p2);
    p2->attack(p1);
}



void attackWithStrategyCase()
{
    std::cout << "\n======================================\n";
    std::cout << "Attack With Strategy Case\n";

    auto Warrior = std::make_shared<Role>("Warrior", Ability{100, 0, 6, 3, 0}, RoleType::General);
    auto Knight = std::make_shared<Role>("Knight", Ability{100,0,3,6,0}, RoleType::General);
    
    auto Sword = std::make_shared<Equipment>("Sword", Ability{0, 0, 6, 0, 0});
    auto Shield = std::make_shared<Equipment>("Shield", Ability{0, 0, 2, 3, 0});

    auto p1 = std::make_shared<Player>("A", Warrior);
    auto p2 = std::make_shared<Player>("B", Knight);

    auto one_attack = std::make_shared<OneValidAttack>();

    p1->setEquipment(Sword);
    p1->display();

    p2->setEquipment(Shield);
    p2->display();

    p1->setAttackStrategy(one_attack);
    
    p1->attack(p2);
    p2->attack(p1);

    p2->setAttackStrategy(one_attack);

    p1->attack(p2);
    p2->attack(p1);

}

void attackedAndDied()
{
    std::cout << "\n======================================\n";
    std::cout << "Attacked And Died Case\n";

    auto Warrior = std::make_shared<Role>("Warrior", Ability{100, 0, 7, 3, 0}, RoleType::General);
    auto Knight = std::make_shared<Role>("Knight", Ability{100,0,3,6,0}, RoleType::General);
    
    auto p1 = std::make_shared<Player>("A", Warrior);
    auto p2 = std::make_shared<Player>("B", Knight);

    auto one_attack = std::make_shared<OneValidAttack>();

    p1->display();
    p2->display();

    p1->setAttackStrategy(one_attack);
    
    int attack_times {0};
    do
    {
        p1->attack(p2);
        attack_times += 1;
    } while (!p2->isDied());
    std::cout << "Attack " << attack_times << " Times." << "\n";
}

int main()
{
    baseCase();
    sharedPtrCase();
    testSameRoleSameEquipmentCase();
    equipCase();
    attackEmptyCase();
    attackWithStrategyCase();
    attackedAndDied();
    return 0;
}