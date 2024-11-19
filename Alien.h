// Authors: Victor Barbulescu & Vamsi Sudersanam
// Course : CSC 2210/001
// Date: 11/17/2024

#ifndef ALIEN_H
#define ALIEN_H

#include "Entity.h"

class Alien : public Entity{
private:
    bool hit = false;
public:
    Alien();
    ~Alien() override;

    void interact(Person *p) override;
    void hint() override;
    char character() override;
};



#endif //ALIEN_H
