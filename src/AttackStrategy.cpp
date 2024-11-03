
#include "AttackStrategy.h"
#include "Player.h"
#include "Role.h"
#include <string_view>

const int OneValidAttack::getDamage(std::shared_ptr<Player> attacker, std::shared_ptr<Player> target)
{
    // helper
    auto attackerRole{attacker->getRole()};
    auto targetRole{target->getRole()};

    // correct the damage source
    int attacker_damage{attacker->getAbility().attack};
    if(attackerRole->getRoleType()==RoleType::Magic)
        attacker_damage = attacker->getAbility().mp;
    
    // check the relation
    if( attackerRole->isNemesis(targetRole) )
        attacker_damage /= 2;
    else if(targetRole->isNemesis(attackerRole))
        attacker_damage *= 2;
    
    // substract defense value
    attacker_damage -= target->getAbility().defense;
    return ( attacker_damage > 0 ) ? attacker_damage : 0;
};
