// Authors: Victor Barbulescu & Vamsi Sudersanam
// Course : CSC 2210/001
// Date: 11/17/2024

#include "Treasure.h"

#include <iostream>
#include <ostream>

#include "Person.h"
#include "Weapon.h"

// -------------------------------------------------------------------------------------- //
// Treasure base class implementation

// -------------------------------------------------------- //
// Constructor/destructor
Treasure::Treasure(int changeValueBy, std::string name) {
    this->changeValueBy = changeValueBy;
    this->name = name;
}
Treasure::~Treasure() = default;

// -------------------------------------------------------- //
// Entity function

char Treasure::character() {
    return '?';
}

// -------------------------------------------------------------------------------------- //
// Ammo derived class implementation

// -------------------------------------------------------- //
// destructor
Ammo::~Ammo() = default;

// -------------------------------------------------------- //
// Entity functions
void Ammo::interact(Person *p) {
    std::cout << "You found some ammo!" << std::endl;
    p->getWeapon()->changeAmmo(this->changeValueBy);
}

void Ammo::hint() {
    std::cout << "You see some bullets scattered across the floor nearby..." << std::endl;
}

// -------------------------------------------------------------------------------------- //
// Medkit derived class implementation

// -------------------------------------------------------- //
// destructor
Medkit::~Medkit() = default;

// -------------------------------------------------------- //
// Entity functions
void Medkit::interact(Person *p) {
    std::cout << "You found a medkit!" << std::endl;
    p->changeHealth(this->changeValueBy);
}

void Medkit::hint() {
    std::cout << "You see bandages littered across the floor nearby..." << std::endl;
}






