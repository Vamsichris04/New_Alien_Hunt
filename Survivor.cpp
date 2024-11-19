// Authors: Victor Barbulescu & Vamsi Sudersanam
// Course : CSC 2210/001
// Date: 11/17/2024

#include <random>
#include <iostream>

#include "Survivor.h"
#include "Person.h"
#include "Room.h"

// -------------------------------------------------------- //
// Constructor/destructor

Survivor::Survivor() = default;
Survivor::~Survivor() = default;

// -------------------------------------------------------- //
// Helper functions

void Survivor::setXYTranslate() {
    std::random_device rd;  // Seed
    std::mt19937 gen(rd()); // Mersenne Twister engine

    // Define the range
    std::uniform_int_distribution<> dist(-5, 5);

    // Generate a random number
    xTranslate = dist(gen);
    yTranslate = dist(gen);
}

// -------------------------------------------------------- //
// Entity functions

void Survivor::interact(Person *p) {
    std::cout << "You encounter a deranged survivor! He scares you off to a random part of the ship!" << std::endl;
    setXYTranslate();

    Room* currentRoom = p->getRoom();
    currentRoom-> setPerson(nullptr);

    // X motion
    int xIterator = 0;
    if (xTranslate < 0) {
        while(xIterator < -xTranslate && p->getRoom()->getLeft() != nullptr) {
            xIterator++;

            // Set the current room's person to nullptr since the person is leaving
            p->getRoom()->setPerson(nullptr);
            // Set the persons pointer to the room to their left
            p->setRoom(p->getRoom()->getLeft());
            // Set the room to the persons left's person pointer to the person
            p->getRoom()->setPerson(p);
        }
    } else if (xTranslate > 0) {
        while(xIterator < xTranslate && p->getRoom()->getRight() != nullptr) {
            xIterator++;

            // Set the current room's person to nullptr since the person is leaving
            p->getRoom()->setPerson(nullptr);
            // Set the persons pointer to the room to their right
            p->setRoom(p->getRoom()->getRight());
            // Set the room to the persons right's person pointer to the person
            p->getRoom()->setPerson(p);
        }
    }

    // Y Motion
    int yIterator = 0;
    if (yTranslate < 0) {
        while(yIterator < -yTranslate && p->getRoom()->getDown() != nullptr) {
            yIterator++;

            // Set the current room's person to nullptr since the person is leaving
            p->getRoom()->setPerson(nullptr);
            // Set the persons pointer to the room below them
            p->setRoom(p->getRoom()->getDown());
            // Set the room below the person's person pointer to the person
            p->getRoom()->setPerson(p);
        }
    } else if (yTranslate > 0) {
        while(yIterator < yTranslate && p->getRoom()->getUp() != nullptr) {
            yIterator++;

            // Set the current room's person to nullptr since the person is leaving
            p->getRoom()->setPerson(nullptr);
            // Set the persons pointer to the room above them
            p->setRoom(p->getRoom()->getUp());
            // Set the room above the person's person pointer to the person
            p->getRoom()->setPerson(p);
        }
    }
}

void Survivor::hint() {
    std::cout << "You hear the screams of a man nearby..." << std::endl;
}

char Survivor::character() {
    return '!';
}




