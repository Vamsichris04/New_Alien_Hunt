// Authors: Victor Barbulescu & Vamsi Sudersanam
// Course : CSC 2210/001
// Date: 11/17/2024

/* Person Class
 * Responsible for managing a persons inventory, health, actions
 * and location on the spaceship
 */

#ifndef PERSON_H
#define PERSON_H

// Forward Declarations
class Weapon;
class Room;

class Person {
private:
    int health = 0;
    Weapon* weapon = nullptr;
    Room* room = nullptr;
public:
    Person(int startingHealth, Room* startingRoom);
    ~Person();

    [[nodiscard]] int getHealth() const;
    void changeHealth(int amount);

    [[nodiscard]] Weapon* getWeapon() const;

    void replaceWeapon(Weapon *weapon);

    void setWeapon(Weapon* w);

    [[nodiscard]] Room* getRoom() const;
    void setRoom(Room* r);

    [[nodiscard]] static char character();

    [[nodiscard]] bool attack() const;
};



#endif //PERSON_H
