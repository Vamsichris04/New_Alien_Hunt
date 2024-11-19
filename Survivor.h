// Authors: Victor Barbulescu & Vamsi Sudersanam
// Course : CSC 2210/001
// Date: 11/17/2024

/* Survivor Class
 * Teleports the player in a random direction after interaction
 */

#ifndef SURVIVOR_H
#define SURVIVOR_H

#include "Entity.h"

class Survivor final : public Entity{
private:
    int xTranslate = 0;
    int yTranslate = 0;

    /**
     * Generates random values between -5 and 5
     * for xTranslate and yTranslate variables
     */
    void setXYTranslate();
public:
    Survivor();
    ~Survivor() override;

    void interact(Person *p) override;
    void hint() override;
    char character() override;
};



#endif //SURVIVOR_H
