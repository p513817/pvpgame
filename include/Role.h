#ifndef ROLE_H
#define ROLE_H

#include <optional>
#include <iostream>
#include <string_view>
#include "Ability.h"

enum RoleType
{
    General,
    Magic
};

class Role
{
private:
    std::string_view m_name;
    Ability m_ability;     
    RoleType m_type;
    std::shared_ptr<Role> m_nemesis;
    
public:
    Role(std::string_view name, Ability ability, RoleType type);
    ~Role(){};
    const std::string_view getName();
    const Ability& getAbility();
    const RoleType getRoleType();
    void setNemesis(std::shared_ptr<Role> );
    const std::shared_ptr<Role> getNemesis();
    const bool isNemesis(std::shared_ptr<Role>);
    void display();
};

#endif