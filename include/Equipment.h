#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <string_view>
#include "Ability.h"

class Equipment
{
private:
    std::string_view m_name;
    Ability m_ability;
public:
    Equipment(std::string_view name, Ability ability);
    ~Equipment(){};
    const std::string_view getName();
    const Ability& getAbility();
    void display();
};

#endif