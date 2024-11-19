// Authors: Victor Barbulescu & Vamsi Sudersanam
// Course : CSC 2210/001
// Date: 11/17/2024

#include "Weapon.h"

#include <iostream>
#include "Alien.h"
#include "Person.h"
#include "Room.h"

// -------------------------------------------------------------------------------------- //
// Weapon base class implementation

Weapon::Weapon(const int ammo, const std::string &name, const int range) {
    this->ammo = ammo;
    this->name = name;
    this->range = range;
}

Weapon::~Weapon() = default;

int Weapon::getAmmo() const {
    return ammo;
}

void Weapon::changeAmmo(int amount) {
    this->ammo += amount;
}

std::string Weapon::getName() const {
    return name;
}

void Weapon::setName(const std::string &name) {
    this->name = name;
}

char Weapon::character() {
    return '>';
}

bool Weapon::checkIfHit(const Room *r) {
    if (dynamic_cast<Alien*>(r->getEntity())) {
        std::cout << "You hit the alien!" << std::endl;
        return true;
    }
    std::cout << "You missed!" << std::endl;
    return false;
}

Room *Weapon::getRoomInDirection(Room *r, char direction) {
    Room* roomInDirection = nullptr;
    switch (direction) {
        case 'n': roomInDirection = r->getUp(); break;
        case 'e': roomInDirection = r->getRight(); break;
        case 's': roomInDirection = r->getDown(); break;
        case 'w': roomInDirection = r->getLeft(); break;
        default: std::cout << "Error determining direction" << std::endl;
    }
    return roomInDirection;
}

// -------------------------------------------------------------------------------------- //
// Knife derived class implementation

Knife::~Knife() = default;

Weapon* Knife::clone() const {
    return new Knife(this->ammo, this->name, this->range);
}

void Knife::interact(Person *p) {
    char grab;
    std::cout << "You found a knife! Grab? y/n" << std::endl;
    std::cin >> grab;

    if (grab == 'y') {
        std::cout << "You grabbed the knife on the ground!" << std::endl;
        Weapon* newWeapon = this->clone();
        delete p->getWeapon();
        p->setWeapon(newWeapon);
    } else {
        std::cout << "You ignored the knife on the ground!" << std::endl;
    }
}

void Knife::hint() {
    std::cout << "You see the glint of a blade through a crack in the wall..." << std::endl;
}

bool Knife::fire(Room *r, char direction) {
    return checkIfHit(r);
}

// -------------------------------------------------------------------------------------- //
// Gun derived class implementation

Gun::~Gun() = default;

Weapon* Gun::clone() const {
    return new Gun(this->ammo, this->name, this->range);
}

void Gun::interact(Person *p) {
    char grab;
    std::cout << "You found a gun! Grab? y/n" << std::endl;
    std::cin >> grab;

    if (grab == 'y') {
        std::cout << "You grabbed the gun on the ground!" << std::endl;
        Weapon* clonedWeapon = this->clone();
        p->replaceWeapon(clonedWeapon);
    } else {
        std::cout << "You ignored the gun on the ground!" << std::endl;
    }
}

void Gun::hint() {
    std::cout << "You see the smoking barrel of a gun through the door..." << std::endl;
}

bool Gun::fire(Room *r, char direction) {
    std::cout << "You pull the trigger of your gun!" << std::endl;
    Room* toReturn = r;

    if (r != nullptr && ammo > 0) {
        ammo--;
        if (checkIfHit(toReturn)) return true;

        int i = 1;
        while (i < range) {
            toReturn = getRoomInDirection(toReturn, direction);
            if (toReturn == nullptr) break;
            if (checkIfHit(toReturn)) return true;
            i++;
        }
    }

    std::cout << "You missed!" << std::endl;
    return false;
}

// -------------------------------------------------------------------------------------- //
// Flamethrower derived class implementation

Flamethrower::~Flamethrower() = default;

Weapon* Flamethrower::clone() const {
    return new Flamethrower(this->ammo, this->name, this->range);
}

void Flamethrower::interact(Person *p) {
    char grab;
    std::cout << "You found a flamethrower! Grab? y/n" << std::endl;
    std::cin >> grab;

    if (grab == 'y') {
        std::cout << "You grabbed the flamethrower on the ground!" << std::endl;
        Weapon* newWeapon = this->clone();
        delete p->getWeapon();
        p->setWeapon(newWeapon);
    } else {
        std::cout << "You ignored the flamethrower on the ground!" << std::endl;
    }
}

void Flamethrower::hint() {
    std::cout << "You see the flaming barrel of a flamethrower through the door..." << std::endl;
}

bool Flamethrower::fire(Room *r, char direction) {
    std::cout << "You pull the trigger of your flamethrower!" << std::endl;
    Room* toReturn = r;

    if (r != nullptr && ammo > 0) {
        ammo--;
        if (checkIfHit(toReturn)) return true;

        int i = 1;
        while (i < range) {
            toReturn = getRoomInDirection(toReturn, direction);
            if (toReturn == nullptr) break;
            if (checkIfHit(toReturn)) return true;
            i++;
        }
    }

    std::cout << "You missed!" << std::endl;
    return false;
}
