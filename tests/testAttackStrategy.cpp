#include "AttackStrategy.h"
#include "Role.h"
#include "Player.h"

#include <vector>
#include <memory>

void OneValidAttackCase()
{
    std::cout << "\n======================================\n";
    std::cout << "OneValidAttackCase\n";

    auto Warrior = std::make_shared<Role>("Warrior", Ability{100, 0, 5, 5, 0}, RoleType::General);
    auto Knight = std::make_shared<Role>("Knight", Ability{100, 0, 3, 8, 0}, RoleType::General);
    auto Sorcerer = std::make_shared<Role>("Sorcerer", Ability{100, 6, 0, 4, 0}, RoleType::Magic);

    Warrior->setNemesis(Sorcerer);
    Knight->setNemesis(Warrior);
    Sorcerer->setNemesis(Knight);

    auto p1 = std::make_shared<Player>("A", Warrior);
    auto p2 = std::make_shared<Player>("B", Knight);
    auto p3 = std::make_shared<Player>("C", Sorcerer);

    for (const auto& player : {p1, p2, p3}) {
        player->display();
    }

    OneValidAttack attackStrategy;

    std::vector<std::pair<std::shared_ptr<Player>, std::shared_ptr<Player>>> attackPairs = {
        {p1, p2}, {p2, p1}, {p1, p3}, {p3, p1}, {p2, p3}, {p3, p2}
    };

    for (const auto& [attacker, target] : attackPairs) {
        std::cout << "Damage from " << attacker->getRole()->getName() << " to " << target->getRole()->getName()
                  << ": " << attackStrategy.getDamage(attacker, target) << "\n";
    }
}


int main()
{
    OneValidAttackCase();
    return 0;
}