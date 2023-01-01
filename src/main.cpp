#include <windows.h>

#include <iostream>

void clear() {
    COORD topLeft = {0, 0};
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(console, ' ', screen.dwSize.X * screen.dwSize.Y,
                                topLeft, &written);
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    SetConsoleCursorPosition(console, topLeft);
}

can get info and create a 'class Drawer' or
    something to specify pixells and that kinds thing.

    int
    main() {
    // std::cout << "\x1b[38;2;40;177;249mTRUE\rCOLOR\x1b[0m" << std::endl;
    std::cout << "\x1B[2J\x1B[H";
    std::cout << "Helloworld\n";
    clear();
    return 0;
}
