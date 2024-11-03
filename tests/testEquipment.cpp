
#include "Equipment.h"

int main()
{
    // hp, mp, attack, defense, critical_prob
    Equipment Sword {"Sword", {0,0,5,0,0}};
    Equipment Shield {"Shield", {0,0,2,3,0}};
    Equipment Staff {"Staff", {0,5,0,0,0}};
    
    Sword.display();
    Shield.display();
    Staff.display();

    return 0;
}