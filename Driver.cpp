// Authors: Victor Barbulescu & Vamsi Sudersanam
// Course : CSC 2210/001
// Date: 11/17/2024

#include "GameController.h"

int main() {
    GameController controller;

    // Initialize the map layout
    const std::vector<std::vector<char>> mapBuilder = {
        {'.', '.', '>', '+', '.'},
        {'.', '!', '@', '.', '>'},
        {'.', '?', '.', '>', '!'},
        {'.', '@', '#', '.', '.'},
        {'@', '.', '?', '>', '@'}
    };

    // Play the game
    controller.start(mapBuilder);
}
