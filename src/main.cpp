/**
 * Benjamin Michael Taylor
 * January 2023
 */

#include <windows.h>

#include <iostream>



int main() {
    std::cout << "\x1b[38;2;40;177;249mTRUE\rCOLOR\x1b[0m" << std::endl;
    std::cout << "\x1B[2J\x1B[H";
    std::cout << "Helloworld\n";
    return 0;
}
