/**
 * Benjamin Michael Taylor
 * January 2023
 */

# pragma once

#include <cstdint>

struct Coords {
    int x;
    int y;
};

struct Colour {
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

class Drawer {
public:
    Drawer();

    void clear();

private:
};