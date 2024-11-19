// Authors: Victor Barbulescu & Vamsi Sudersanam
// Course : CSC 2210/001
// Date: 11/17/2024

#include "Hazard.h"

#include <iostream>
#include <ostream>

#include "Person.h"

// -------------------------------------------------------------------------------------- //
// Hazard base class implementation

// -------------------------------------------------------- //
// Constructor/destructor

Hazard::Hazard(const std::string &name, int damage) {
    this->damage = damage;
    this->name = name;
}

Hazard::~Hazard() = default;

char Hazard::character() {
    return '@';
}

// -------------------------------------------------------------------------------------- //
// ExposedWires derived class implementation

// -------------------------------------------------------- //
// destructor
ExposedWires::~ExposedWires() = default;

// -------------------------------------------------------- //
// Entity functions

void ExposedWires::interact(Person *p) {
    std::cout << "You were shocked by exposed wires!" << std::endl;
    p->changeHealth(-damage);
}

void ExposedWires::hint() {
    std::cout << "You hear sparks nearby" << std::endl;
}


// -------------------------------------------------------------------------------------- //
// LowOxygenRoom derived class implementation

// -------------------------------------------------------- //
// destructor
LowOxygenRoom::~LowOxygenRoom() = default;

// -------------------------------------------------------- //
// Entity functions

void LowOxygenRoom::interact(Person *p) {
    std::cout << "You nearly choked from the low oxygen!" << std::endl;
    p->changeHealth(-damage);
}

void LowOxygenRoom::hint() {
    std::cout << "You hear air leaking out nearby" << std::endl;
}








