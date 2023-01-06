/**
 * Benjamin Michael Taylor
 * January 2023
 */

#pragma once

#include <windows.h>

#include <cstdint>
#include <vector>

const COORD topLeft = {0, 0};

struct Colour {
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

struct Character {
    char character;
    Colour colour;
};

inline void printCharacter(Character character) {
    printf("\033[38;2;%d;%d;%dm%c\033[0m", character.colour.r,
           character.colour.g, character.colour.b, character.character);
};

class Drawer {
   public:
    Drawer();

    void clear();
    void resetCursor();
    void printFrame();

   private:
    HANDLE console;
    CONSOLE_SCREEN_BUFFER_INFO screen;
    std::vector<std::vector<Character>> characterBuffer;
};