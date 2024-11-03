
#include <iostream>

#include "Role.h"
#include <memory>

Role::Role(std::string_view name, Ability ability, RoleType type):
    m_name{name}, m_ability{ability}, m_type{type} {};

const std::string_view Role::getName()
{
    return m_name;
}

const Ability& Role::getAbility()
{
    return m_ability;
}

const RoleType Role::getRoleType()
{
    return m_type;
}

void Role::setNemesis(std::shared_ptr<Role> nemesis) 
{
    m_nemesis = nemesis;
}

const std::shared_ptr<Role>  Role::getNemesis() 
{
    return m_nemesis;
}

const bool Role::isNemesis(std::shared_ptr<Role> target)
{
    if(!m_nemesis and !target->getNemesis())
        return false;
    return m_nemesis->getName() == target->getName(); 
}

void Role::display()
{
    std::cout << m_name;
    
    std::cout << " ( ";
    m_ability.display();
    std::cout << ")";

    std::cout << "( Nemesis: ";
    if (m_nemesis)
        std::cout << m_nemesis->getName();
    else
        std::cout << "None";
    std::cout << " )\n";
}

