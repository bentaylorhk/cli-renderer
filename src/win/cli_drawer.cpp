/**
 * Benjamin Michael Taylor
 * January - April 2023
 */

#include "cli_drawer.h"

#include <cstdio>
#include <windows.h>

namespace cli_renderer {

    namespace {
        // Windows terminal variables
        HANDLE console;
        CONSOLE_SCREEN_BUFFER_INFO cbsi;

        const COORD TOP_LEFT = {0, 0};
    }

    Drawer::Drawer() {
        // Initialising the Windows terminal variables
        console = GetStdHandle(STD_OUTPUT_HANDLE);
        GetConsoleScreenBufferInfo(console, &cbsi);

        this->width = cbsi.dwSize.X;
        this->height = cbsi.dwSize.Y;
        this->charCount = this->width * this->height;

        this->characters = std::vector<std::vector<Character>>(
                this->height,
                std::vector<Character>(this->width)
               // std::vector<Character>(this->width, {' ', {255, 0, 0}})
        );

        this->clear();
    }

    void Drawer::resetCursor() {
        SetConsoleCursorPosition(console, TOP_LEFT);
    }

    void Drawer::clear() {
        DWORD written;

        FillConsoleOutputCharacter(console, ' ', this->charCount,
                                    TOP_LEFT, &written);
        FillConsoleOutputAttribute(
                console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
                this->charCount, TOP_LEFT, &written);

        this->resetCursor();
    }

    void Drawer::drawFrame() {
        for (const auto &row: characters) {
            for (const auto &character: row) {
                printCharacter(character);
            }
            printf("\n");
        }
    }

}