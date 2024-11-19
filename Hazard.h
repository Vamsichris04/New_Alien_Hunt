// Authors: Victor Barbulescu & Vamsi Sudersanam
// Course : CSC 2210/001
// Date: 11/17/2024

/* Hazard Class
 * Defines the attributes of a hazard including name, damage, char notation
 * on the map, and interaction with the player
 */

#ifndef HAZARD_H
#define HAZARD_H

#include <string>
#include "Entity.h"

class Hazard : public Entity{
protected:
    std::string name;
    int damage = 0;
public:
    Hazard(const std::string& name, int damage);
    ~Hazard() override;

    char character() override;
};

class ExposedWires final : public Hazard {
public:
    using Hazard::Hazard;
    ~ExposedWires() override;

    void interact(Person *p) override;
    void hint() override;
};

class LowOxygenRoom final : public Hazard {
public:
    using Hazard::Hazard;
    ~LowOxygenRoom() override;

    void interact(Person *p) override;
    void hint() override;
};
#endif //HAZARD_H
