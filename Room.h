// Authors: Victor Barbulescu & Vamsi Sudersanam
// Course : CSC 2210/001
// Date: 11/17/2024

/* Room Class
 * Responsible for managing the contents of a room, including its objects
 * and player. It contains pointers to adjacent rooms for traversal. It also
 * facilitates interaction between the rooms entity and player.
 */

#ifndef ROOM_H
#define ROOM_H

// Forward Declarations
class Entity;
class Person;

class Room {
private:
    // Pointers to the object and player (both optional) in the room
    Entity* object = nullptr;
    Person* player = nullptr;

    // Pointers to adjacent rooms
    Room* up = nullptr;
    Room* down = nullptr;
    Room* left = nullptr;
    Room* right = nullptr;
public:
    Room(Entity* startingObject, Person* startingPlayer);
    ~Room();

    void setEntity(Entity* e);
    void setPerson(Person* p);
    [[nodiscard]] Entity* getEntity() const;
    [[nodiscard]] Person* getPerson() const;

    // Print the contents of the room
    [[nodiscard]] char getContents() const;

    // Activate interactions in the room
    void interact() const;

    [[nodiscard]] Room* getUp() const;
    [[nodiscard]] Room* getDown() const;
    [[nodiscard]] Room* getLeft() const;
    [[nodiscard]] Room* getRight() const;

    void setUp(Room* room);
    void setDown(Room* room);
    void setLeft(Room* room);
    void setRight(Room* room);
};



#endif //ROOM_H
