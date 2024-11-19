// Authors: Victor Barbulescu & Vamsi Sudersanam
// Course : CSC 2210/001
// Date: 11/17/2024

#include "Person.h"

#include <iostream>

#include "Room.h"
#include "Weapon.h"

// -------------------------------------------------------- //
// Constructor/destructor

Person::Person(int startingHealth, Room *startingRoom) {
    health = startingHealth;
    room = startingRoom;
}
Person::~Person() {
    delete weapon;
    weapon = nullptr;
}

// -------------------------------------------------------- //
// Health functions

int Person::getHealth() const {
    return health;
}

void Person::changeHealth(int amount) {
    health += amount;
}

// -------------------------------------------------------- //
// Weapon functions

void Person::setWeapon(Weapon *w) {
    if (weapon) {
        delete weapon;
    }
    weapon = w;
}

Weapon *Person::getWeapon() const {
    return weapon;
}
void Person::replaceWeapon(Weapon* weapon) {
    if (this->weapon != nullptr) {
        std::cout << "Replacing existing weapon: " << this->weapon->getName() << std::endl;
        delete this->weapon;
    }
    std::cout << "New weapon equipped: " << weapon->getName() << std::endl;
    this->weapon = weapon;

}

// -------------------------------------------------------- //
// Room functions

Room *Person::getRoom() const {
    return room;
}
void Person::setRoom(Room *r) {
    room = r;
}

// -------------------------------------------------------- //
// Character function

char Person::character() {
    return '+';
}

// -------------------------------------------------------- //
// Attack function

bool Person::attack() const {
    char direction;
    std::cout << "Fire N)orth, S)outh, E)ast, W)est?";
    std::cin >> direction;
    std::cout << std::endl;

    if (direction == 'n') {
        return weapon->fire(room->getUp(), 'n');
    }
    if (direction == 'e') {
        return weapon->fire(room->getRight(), 'e');
    }
    if (direction == 's') {
        return weapon->fire(room->getDown(), 's');
    }
    if (direction == 'w') {
        return weapon->fire(room->getLeft(), 'w');
    }

    // If the input is bad, hold your fire
    std::cout << "No such direction!\n";
    return false;
}













