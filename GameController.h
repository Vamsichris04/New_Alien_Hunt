// Authors: Victor Barbulescu & Vamsi Sudersanam
// Course : CSC 2210/001
// Date: 11/17/2024

/* GameController class
 * A class that controls the back-end of the game
 * while providing users with one function, start(), which
 * takes in a map layout and generates a game.
 */

#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <vector>

class Entity;
class Room;
class Person;
class Hazard;
class Survivor;
class Treasure;
class Weapon;
class Alien;

class GameController {
private:

    // If the user enters d, the program enters debug mode and the map is always displayed
    bool debugMode = false;

    std::vector<std::vector<Room*>> currMap;

    Room* currRoom = nullptr;
    Person* player = nullptr;

    // Count of hazard types, used for map building
    int exposedWiresCount = 0;  // max 2
    int lowOxygenCount = 0;     // max 2

    // Count of weapon types, used for map building
    int gunCount = 0;           // max 2
    int flamethrowerCount = 0;  // max 2

    // Count of treasure types, used for map building
    int ammoCount = 0;          // max 1
    int medkitCount = 0;        // max 1

    std::vector<std::vector<Room*>> buildMap(const std::vector<std::vector<char>>& map);
    Room* buildRoom(char entity);
    static void printRoomHints(const Room* room);
    static void printGameDescription() ;
    void printCurrMap() const;
    static bool checkGameOver(const Person* p) ;

    [[nodiscard]] static char printControlPrompt() ;
public:
    GameController();
    ~GameController();

    void start(const std::vector<std::vector<char>>& mapBuilder);
};



#endif //GAMECONTROLLER_H
