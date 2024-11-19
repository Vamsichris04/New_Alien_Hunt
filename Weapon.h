// Authors: Victor Barbulescu & Vamsi Sudersanam
// Course : CSC 2210/001
// Date: 11/17/2024

#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include "Entity.h"

class Room;

class Weapon : public Entity {
protected:
    std::string name;
    int ammo = 0;
    int range = 0;

    Room* getRoomInDirection(Room *r, char direction);

    static bool checkIfHit(const Room* r);

public:
    Weapon(int ammo, const std::string& name, int range);
    ~Weapon() override;

    [[nodiscard]] int getAmmo() const;
    [[nodiscard]] std::string getName() const;

    void changeAmmo(int amount);
    void setName(const std::string& name);

    char character() override;

    virtual bool fire(Room *r, char direction) = 0;
    virtual Weapon* clone() const = 0;  // Pure virtual method for cloning
};

class Knife final : public Weapon {
public:
    using Weapon::Weapon;
    ~Knife() override;

    void interact(Person *p) override;
    void hint() override;

    bool fire(Room *r, char direction) override;
    [[nodiscard]] Weapon* clone() const override;  // Override clone
};

class Gun final : public Weapon {
public:
    using Weapon::Weapon;
    ~Gun() override;

    void interact(Person *p) override;
    void hint() override;

    bool fire(Room *r, char direction) override;
    [[nodiscard]] Weapon* clone() const override;  // Override clone
};

class Flamethrower final : public Weapon {
public:
    using Weapon::Weapon;
    ~Flamethrower() override;

    void interact(Person *p) override;
    void hint() override;

    bool fire(Room *r, char direction) override;
    [[nodiscard]] Weapon* clone() const override;  // Override clone
};

#endif // WEAPON_H
