// Authors: Victor Barbulescu & Vamsi Sudersanam
// Course : CSC 2210/001
// Date: 11/17/2024

/* Treasure Class
 * Defines the attributes of a treasure including name, change amount, char notation
 * on the map, and interaction with the player
 */

#ifndef TREASURE_H
#define TREASURE_H

#include <string>
#include "Entity.h"

class Treasure : public Entity{
protected:
    int changeValueBy = 0;
    std::string name;
public:
    Treasure(int changeValueBy, std::string name);
    ~Treasure() override;

    char character() override;
};

class Ammo final : public Treasure {
public:
    using Treasure::Treasure;
    ~Ammo() override;

    void interact(Person *p) override;
    void hint() override;
};

class Medkit final : public Treasure {
public:
    using Treasure::Treasure;
    ~Medkit() override;

    void interact(Person *p) override;
    void hint() override;
};



#endif //TREASURE_H
