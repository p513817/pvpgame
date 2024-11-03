#ifndef ABILITY_H
#define ABILITY_H

#include <iostream>

struct Ability
{
    int hp{0};
    int mp{0};
    int attack{0};
    int defense{0};
    double critical_prob{0.0};

    Ability operator+(const Ability& other);
    Ability operator-(const Ability& other);
    void display() const;
};

#endif
