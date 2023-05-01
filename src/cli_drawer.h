/**
 * Benjamin Michael Taylor
 * January 2023
 */

#pragma once


#include <cstdint>
#include <cstdio>
#include <vector>

namespace cli_renderer {
    struct Coord {
        int x;
        int y;
    };

    struct Colour {
        uint8_t r;
        uint8_t g;
        uint8_t b;
    };

    struct Character {
        char value;
        //Colour colour;
    };

    class Drawer {
    public:
        Drawer();

        void clear();

        void drawFrame();

        void resetCursor();

        int width;
        int height;

        inline Character getCharacter(int x, int y) {
            return characters[y][x];
        }

        inline void setCharacter(Character character, int x, int y) {
            characters[y][x] = character;
        }

        std::vector<std::vector<Character>> characters;
    private:
        static inline void printCharacter(Character character) {
            printf("%c", character.value);
            //printf("\033[38;2;%d;%d;%dm%c\033[0m", character.colour.r,
            //       character.colour.g, character.colour.b, character.character);
        };

        int charCount;
    };
}