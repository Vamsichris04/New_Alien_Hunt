# Spaceship Survival Game  

Welcome to the **Spaceship Survival Game**! This project is an interactive, text-based adventure game where players navigate through a perilous spaceship, encounter dangerous hazards, and battle an alien lurking in its corridors.

---

## **Game Overview**  

Your mission is to survive and eliminate the Alien before it gets to you. But beware—the spaceship is filled with deadly hazards, insane survivors, and hidden treasures that will either help or hinder your journey.

### **Core Features**  
- **Dynamic Map**: Navigate through a grid-based spaceship with interconnected rooms.
- **Hazards and Obstacles**:
  - **Alien**: Encountering it without preparation means game over.
  - **Exposed Wires, Pits, Low Oxygen Rooms, and Faulty Doors**: These can deal random damage.
  - **Survivors**: They teleport you to random locations.
- **Weapons**:
  - **Knife**: Close-range, always available.
  - **Gun**: Medium-range, effective but requires ammo.
  - **Flamethrower**: Long-range and powerful but consumes ammo.
- **Clues and Hints**: Each hazard provides subtle clues about its proximity.

---

## **How to Play**  

### **Controls**  
- `w` - Move West  
- `e` - Move East  
- `n` - Move North  
- `s` - Move South  
- `f` - Attack (Use your equipped weapon)  
- `h` - Display How to Play instructions  
- `q` - Quit the game
- `d` - Debugging mode

### **Hints for Hazards**  
- **"You hear a grotesque screeching nearby...."** - An Alien is nearby.  
- **"You hear sparks nearby."** - Exposed wires in the adjacent room.  
- **"You hear air leaking out nearby."** - Low oxygen detected nearby.  
- **"You hear a creaking sound."** - A faulty door might be close.  
- **"You hear distant screeching...."** - A Survivor is nearby and may relocate you.

---

## **Setup and Installation**  

### **Prerequisites**  
- **C++ Compiler**: Ensure you have a C++17 compatible compiler (e.g., GCC, Clang, MSVC).  
- **Development Environment**: Recommended to use CLion, Visual Studio, or any preferred IDE.  

### **Clone the Repository**  
1. Open your terminal and run:  
   ```bash
   git clone https://github.com/Vamsichris04/wumpus_hunt
