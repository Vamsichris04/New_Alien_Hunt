// Authors: Victor Barbulescu & Vamsi Sudersanam
// Course : CSC 2210/001
// Date: 11/17/2024

/* Entity Class
 * Pure virtual class that provides an interface for what
 * game entities should be able to do at a minimum.
 */

#ifndef ENTITY_H
#define ENTITY_H

// Forward Declarations
class Person;

/**
 * Pure virtual class that provides an interface for what
 * game entities should be able to do at a minimum
 */
class Entity {
public:
    virtual ~Entity();

    /**
     * Handles interaction with the Person class
     * @param p the person to interact with
     */
    virtual void interact(Person *p) = 0;

    /**
     * Prints the current entities hint to the console
     */
    virtual void hint() = 0;

    /**
     * @return the character representing the type of entity it is
     */
    virtual char character() = 0;
};

#endif //ENTITY_H
