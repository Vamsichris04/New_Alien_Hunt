#include "GameController.h"
#include <iostream>
#include "Room.h"
#include "Person.h"
#include "Entity.h"

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
// Map builder functions

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
