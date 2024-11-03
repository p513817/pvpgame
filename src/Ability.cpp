#include <iostream>
#include "Ability.h"

// Implement the addition operator
Ability Ability::operator+(const Ability& other)
{
    return Ability{
        hp + other.hp,
        mp + other.mp,
        attack + other.attack,
        defense + other.defense,
        critical_prob + other.critical_prob
    };
}

Ability Ability::operator-(const Ability& other)
{
    return Ability{
        (hp > other.hp) ? hp - other.hp : 0 ,
        (mp > other.mp) ? mp - other.mp : 0,
        (attack > other.attack) ? attack - other.attack : 0,
        (defense > other.defense) ? defense - other.defense : 0,
        (critical_prob > other.critical_prob) ? critical_prob - other.critical_prob : 0
    };
}


// Implement the display method
void Ability::display() const
{
    if(hp)
        std::cout << "HP +" << hp << " ";
    if(mp)
        std::cout << "MP +" << mp << " ";
    if(attack)
        std::cout << "Attack +" << attack << " ";
    if(defense)
        std::cout << "Defense +" << defense << " ";
    if(critical_prob)
        std::cout << "Critical Porb +" << critical_prob << " ";
}