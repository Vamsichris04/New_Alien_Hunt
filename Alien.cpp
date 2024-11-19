// Authors: Victor Barbulescu & Vamsi Sudersanam
// Course : CSC 2210/001
// Date: 11/17/2024

#include <iostream>

#include "Alien.h"
#include "Person.h"

// -------------------------------------------------------- //
// Constructor/destructor

Alien::Alien() = default;
Alien::~Alien() = default;

// -------------------------------------------------------- //
// Entity functions

// Alien will one-shot the player
// Setting the players health to zero will lose
// the game in the controller class
void Alien::interact(Person *p) {
    std::cout << "You step into the room and find the hideous alien! It swiftly kills you!" << std::endl;
    p->changeHealth(-p->getHealth());
}

void Alien::hint() {
    std::cout << "You hear a grotesque screeching nearby..." << std::endl;
}

char Alien::character() {
    return '#';
}