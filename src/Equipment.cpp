
#include <iostream>
#include "Equipment.h"

Equipment::Equipment(std::string_view name, Ability ability):
    m_name{name}, m_ability{ability} {};

const std::string_view Equipment::getName()
{
    return m_name;
}

const Ability& Equipment::getAbility()
{
    return m_ability;
}

void Equipment:: display()
{
    std::cout << m_name;

    std::cout << " ( ";
    m_ability.display();
    std::cout << ")\n";
};
