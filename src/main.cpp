/**
 * Benjamin Michael Taylor
 * January 2023
 */

#include <iostream>

#include "cli_drawer.h"

int main() {
    cli_renderer::Drawer drawer;
    drawer.setCharacter({'X'}, drawer.width / 2, drawer.height / 2);
    drawer.drawFrame();

    return 0;
}
