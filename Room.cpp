// Authors: Victor Barbulescu & Vamsi Sudersanam
// Course : CSC 2210/001
// Date: 11/17/2024

#include "Room.h"

#include <iostream>
#include <ostream>

#include "Entity.h"
#include "Person.h"

// -------------------------------------------------------- //
// Constructor/destructor

// Room constructor definition
Room::Room(Entity *startingObject, Person *startingPlayer) {
    object = startingObject;
    player = startingPlayer;
}
// Room destructor definition
Room::~Room() {
    delete object;
    delete player;

    object = nullptr;
    player = nullptr;
}

// -------------------------------------------------------- //
// Room contents functions

// Get and set object in room
void Room::setEntity(Entity* e) {
    object = e;
}
Entity *Room::getEntity() const {
    return object;
}

// Get and set person in room
void Room::setPerson(Person *p) {
    player = p;
}
Person *Room::getPerson() const {
    return player;
}

// -------------------------------------------------------- //
// Adjacent room functions

// Get adjacent rooms
Room *Room::getUp() const {
    return up;
}
Room *Room::getDown() const {
    return down;
}
Room *Room::getLeft() const {
    return left;
}
Room *Room::getRight() const {
    return right;
}

// Set adjacent rooms
void Room::setUp(Room *room) {
    this->up = room;
}
void Room::setDown(Room *room) {
    this->down = room;
}
void Room::setLeft(Room *room) {
    this->left = room;
}
void Room::setRight(Room *room) {
    this->right = room;
}

// -------------------------------------------------------- //
// Interaction function

// Trigger interaction between player and object
void Room::interact() const {
    if (object != nullptr && player != nullptr) {
        object->interact(player);
    }
}

// -------------------------------------------------------- //
// Get contents of the room functions

// Print out the contents of the room
char Room::getContents() const {
    char output;
    if (player != nullptr) {
        output = player->character();
    } else if (object != nullptr) {
        output = object->character();
    } else {
        output = '.';
    }

    return output;
}











