#include "Player.h"
#include <iostream>

Player::Player(std::string_view name, std::shared_ptr<Role> role)
    : m_name(name), m_role(std::move(role)), m_equipment(nullptr)
{
    m_ability = m_role->getAbility();
}

Player::~Player()
{
}

void Player::setEquipment(std::shared_ptr<Equipment> equipment)
{
    if (m_equipment) {
        m_ability = m_ability - m_equipment->getAbility();
    }

    m_equipment = std::move(equipment);
    if (m_equipment) {
        m_ability = m_ability + m_equipment->getAbility();
    }
}

const Ability& Player::getAbility() const
{
    return m_ability;
}

const std::shared_ptr<Role> Player::getRole() const
{
    return m_role;
}

const std::shared_ptr<Equipment> Player::getEquipment() const
{
    return m_equipment;
}

void Player::display() const
{
    std::cout << "Name: " << m_name << ", ";
    std::cout << "Role: " << m_role->getName() << ", ";
    
    if (m_equipment) {
        std::cout << "Equipment: " << m_equipment->getName() << ", ";
    } else {
        std::cout << "Equipment: None" << ", ";
    }
    
    std::cout << "Abilities: ";
    std::cout << "HP " << m_ability.hp << " ";
    std::cout << "MP " << m_ability.mp << " ";
    std::cout << "Attack " << m_ability.attack << " ";
    std::cout << "Defense " << m_ability.defense << " ";
    std::cout << "Critical Porb " << m_ability.critical_prob << " ";
    std::cout << "\n";
}


void Player::setAttackStrategy(std::shared_ptr<AttackStrategy> strategy)
{
    m_attackStrategy = std::move(strategy);
    std::cout << "Set Attack Strategy: " << typeid(decltype(*m_attackStrategy)).name() << "\n";
}

void Player::takeDamage(int damage_value)
{
    m_ability.hp -= damage_value;
    if (m_ability.hp < 0) 
        m_ability.hp = 0;
    // std::cout << "Remaining HP: " << m_ability.hp << "\n";
}

void Player::attack(std::shared_ptr<Player> target)
{
    if (!m_attackStrategy) {
        std::cout << "No attack strategy set for " << m_name << ".\n";
        return;
    }
    
    int damage = m_attackStrategy->getDamage(shared_from_this(), target);
    target->takeDamage(damage);
    
}

const bool Player::isDied()
{
    return m_ability.hp == 0;
}