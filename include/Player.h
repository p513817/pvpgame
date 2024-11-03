#ifndef PLAYER_H
#define PLAYER_H

#include <string_view>
#include <memory>
#include "Role.h"
#include "Equipment.h"
#include "Ability.h"
#include "AttackStrategy.h"

class Player : public std::enable_shared_from_this<Player>
{
private:
    std::string_view m_name;
    std::shared_ptr<Role> m_role;
    std::shared_ptr<Equipment> m_equipment;
    Ability m_ability;
    std::shared_ptr<AttackStrategy> m_attackStrategy;

public:
    Player(std::string_view name, std::shared_ptr<Role> role);
    ~Player();

    void setEquipment(std::shared_ptr<Equipment> equipment);
    const Ability& getAbility() const;  
    const std::shared_ptr<Role> getRole() const;
    const std::shared_ptr<Equipment> getEquipment() const;
    void display() const;
    void setAttackStrategy(std::shared_ptr<AttackStrategy> strategy);
    void takeDamage(int);
    void attack(std::shared_ptr<Player> target);
    const bool isDied();
};

#endif
