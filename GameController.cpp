#include "GameController.h"
#include <iostream>

#include "Alien.h"
#include "Room.h"
#include "Person.h"
#include "Entity.h"
#include "Hazard.h"
#include "Survivor.h"
#include "Treasure.h"
#include "Weapon.h"

using namespace std;

// -------------------------------------------------------- //

// Constructor
GameController::GameController() = default;

//Destructor

GameController::~GameController() {
    // Delete the map and its contents
    for (auto& row : currMap) {
        for (auto& element : row) {
            if (element != nullptr) {
                delete element;
                element = nullptr;
            }
        }
    }

    currMap.clear();

    // Delete the current room pointer
    delete currRoom;
    currRoom = nullptr;

    // Delete the current player pointer
    delete player;
    player = nullptr;
}
// -------------------------------------------------------- //
// Check if the Game is Over

bool GameController::checkGameOver(const Person* p) {
    if (p->getHealth() <= 0) {
        cout << "Your health has dropped to zero.\n";
        return true; // Game ends if health is zero or less
    }
    return false;
}

void GameController::printGameDescription() {
    cout << "\n=== Spaceship Survival Game Instructions ===\n";
    cout << "Navigate through the spaceship, avoiding hazards and defeating the alien.\n";
    cout << "\nControls:\n";
    cout << "  - 'n': Move North\n";
    cout << "  - 's': Move South\n";
    cout << "  - 'e': Move East\n";
    cout << "  - 'w': Move West\n";
    cout << "  - 'f': Attack (Use your equipped weapon)\n";
    cout << "  - 'h': Display this help message\n";
    cout << "  - 'q': Quit the game\n";
    cout << "\nHazards:\n";
    cout << "  - Alien: Encounter it without preparation, and it's game over.\n";
    cout << "  - Exposed Wires: Entering a room may cause damage.\n";
    cout << "  - Low Oxygen Rooms: Damage your health over time.\n";
    cout << "\nWeapons:\n";
    cout << "  - Knife: Close-range weapon.\n";
    cout << "  - Gun: Medium-range weapon (requires ammo).\n";
    cout << "  - Flamethrower: Long-range and powerful (requires ammo).\n";
    cout << "\nObjectives:\n";
    cout << "  - Find weapons and treasures.\n";
    cout << "  - Avoid hazards.\n";
    cout << "  - Defeat the alien to win the game.\n";
    cout << "===========================================\n";
}

// -------------------------------------------------------- //
// Map builder functions

// Print the Current Map

void GameController::printCurrMap() const {
    if (!debugMode) return; // Only print the map in debug mode

    cout << "\nCurrent Map:\n";
    for (const auto& row : currMap) {
        for (const auto& room : row) {
            if (room->getPerson() != nullptr) {
                cout << '+'; // Represent the player's position
            } else if (room->getEntity() != nullptr) {
                cout << room->getEntity()->character(); // Display entity's character
            } else {
                cout << '.'; // Empty room
            }
            cout << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// -------------------------------------------------------- //

vector<vector<Room *>> GameController::buildMap(const vector<vector<char>> &map) {
    const int rows = map.size();
    const int cols = map[0].size();
    vector<vector<Room*>> roomGrid(rows, vector<Room*>(cols, nullptr));

    // Create Room objects and store them in the grid
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            roomGrid[i][j] = buildRoom(map[i][j]);
        }
    }

    // Link the rooms
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            Room* currentRoom = roomGrid[i][j];
            if (i > 0) {
                currentRoom->setUp(roomGrid[i - 1][j]);
                roomGrid[i - 1][j]->setDown(currentRoom);
            }
            if (i < rows - 1) {
                currentRoom->setDown(roomGrid[i + 1][j]);
                roomGrid[i + 1][j]->setUp(currentRoom);
            }
            if (j > 0) {
                currentRoom->setLeft(roomGrid[i][j - 1]);
                roomGrid[i][j - 1]->setRight(currentRoom);
            }
            if (j < cols - 1) {
                currentRoom->setRight(roomGrid[i][j + 1]);
                roomGrid[i + 1][j]->setLeft(currentRoom);
            }
        }
    }

    return roomGrid;
}

Room *GameController::buildRoom(char entity) {
    Entity* startingEntity = nullptr;

    // Build entities in the room (if applicable)
    switch (entity) {
        case '>': {
            // Create two guns and two flamethrowers on the map
            if (gunCount < 2) {
                startingEntity = new Gun(3, "gun", 2);
                gunCount++;
            } else {
                startingEntity = new Flamethrower(3, "flamethrower", 3);
                flamethrowerCount++;
            }
            break;
        } case '!': {
            startingEntity = new Survivor();
            break;
        } case '@': {
            // Create two exposed wire hazards and two low oxygen hazards
            if (exposedWiresCount < 2) {
                startingEntity = new ExposedWires("exposed wires", 5);
                exposedWiresCount++;
            } else {
                startingEntity = new LowOxygenRoom("low oxygen", 4);
                lowOxygenCount++;
            }
            break;
        } case '?': {
            // Create one ammo and one medkit
            if (ammoCount < 1) {
                startingEntity = new Ammo(3, "ammo");
                ammoCount++;
            } else {
                startingEntity = new Medkit(3, "medkit");
                medkitCount++;
            }
            break;
        } case '#': {
            startingEntity = new Alien();
            break;
        } default:
            break;
    }

    // Build room with the assigned entity
    Room* startingRoom = new Room(startingEntity, nullptr);

    // If the entity in the room is a person, add a person to the room.
    if (entity == '+') {
        Person* newPerson = new Person(10, startingRoom);
        newPerson->setWeapon(new Knife(1, "knife", 1));
        startingRoom->setPerson(newPerson);

    }

    return startingRoom;
}


// -------------------------------------------------------- //
// Print Control Prompt
char GameController::printControlPrompt() {
    char input;
    cout << "Action: N)orth, S)outh, E)ast, W)est, F)ire, H)elp, Q)uit: ";
    cin >> input;
    return input; // Convert input to lowercase for consistent handling
}

// -------------------------------------------------------- //
// Print hints for adjacent rooms

void GameController::printRoomHints(const Room *room) {
    if (room->getLeft() && room->getLeft()->getEntity()) {
        room->getLeft()->getEntity()->hint();
    }
    if (room->getRight() && room->getRight()->getEntity()) {
        room->getRight()->getEntity()->hint();
    }
    if (room->getUp() && room->getUp()->getEntity()) {
        room->getUp()->getEntity()->hint();
    }
    if (room->getDown() && room->getDown()->getEntity()) {
        room->getDown()->getEntity()->hint();
    } else {
        std::cout << "No dangers detected nearby.\n";
    }
}

// -------------------------------------------------------- //
// Game loop and player movement

void GameController::start(const std::vector<std::vector<char>>& mapBuilder) {
    std::cout << "Welcome to the Spaceship Survival Game!\n\n";
    printGameDescription();

    currMap = buildMap(mapBuilder);

    Room* room = currMap[0][3];
    player = room->getPerson();
    bool gameOver = false;

    while (!gameOver) {
        printCurrMap();
        room->interact();
        gameOver = checkGameOver(player);

        if (gameOver) {
            cout << "You were tragically killed! Game Over!" << endl;
            break;
        }

        printRoomHints(room);

        char choice = printControlPrompt();
        switch (choice) {
            case 'w':
                if (room->getLeft()) {
                    player->setRoom(room->getLeft());
                    room->getLeft()->setPerson(player);
                    room->setPerson(nullptr);
                    room = room->getLeft();
                }
                break;
            case 'e':
                if (room->getRight()) {
                    player->setRoom(room->getRight());
                    room->getRight()->setPerson(player);
                    room->setPerson(nullptr);
                    room = room->getRight();
                }
                break;
            case 'n':
                if (room->getUp()) {
                    player->setRoom(room->getUp());
                    room->getUp()->setPerson(player);
                    room->setPerson(nullptr);
                    room = room->getUp();
                }
                break;
            case 's':
                if (room->getDown()) {
                    player->setRoom(room->getDown());
                    room->getDown()->setPerson(player);
                    room->setPerson(nullptr);
                    room = room->getDown();
                }
                break;
            case 'f':
                if (player->attack()) {
                    cout << "Congratulations! You killed the alien!" << endl;
                    gameOver = true;
                }
                break;
            case 'h':
                printGameDescription();
                break;
            case 'd':
                cout << "Toggling debug mode" << endl;
                debugMode = !debugMode;
                break;
            case 'q':
                gameOver = true;
                break;
            default:
                break;
        }
    }
}
