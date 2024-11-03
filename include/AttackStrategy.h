#ifndef ATTACKSTRATEGY_H
#define ATTACKSTRATEGY_H

#include <memory>

class Player;

class AttackStrategy {
public:
    AttackStrategy() = default;
    virtual ~AttackStrategy() = default;
    virtual const int getDamage(std::shared_ptr<Player> attacker, std::shared_ptr<Player> target) = 0;
};

class OneValidAttack : public AttackStrategy {
public:
    OneValidAttack() = default;
    const int getDamage(std::shared_ptr<Player> attacker, std::shared_ptr<Player> target) override;
};

#endif
