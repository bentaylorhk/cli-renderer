/**
 * Benjamin Michael Taylor
 * January 2023
 */

#include "cli_drawer.h"

#include <windows.h>

Drawer::Drawer() {
    // Getting the console and screen information
    this->console = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(console, &screen);

    // Setting the character buffer size.
    characterBuffer = std::vector<std::vector<Character>>(
        screen.dwSize.Y,
        std::vector<Character>(screen.dwSize.X, {'x', {255, 0, 0}}));
}

void Drawer::resetCursor() {
    // Setting the cursors position to the top left
    SetConsoleCursorPosition(console, topLeft);
}

void Drawer::clear() {
    DWORD written;

    FillConsoleOutputCharacterA(console, ' ', screen.dwSize.X * screen.dwSize.Y,
                                topLeft, &written);
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
}

void Drawer::printFrame() {
    for (auto row : characterBuffer) {
        for (auto character : row) {
            printCharacter(character);
        }
        printf("\n");
    }
}