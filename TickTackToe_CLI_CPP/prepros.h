#pragma once
#include <iostream>
#include "funcs.h"
#include "global.h"
void getch(void) {
    #if defined(_WIN32) || defined(_WIN64)
        system("@pause>nul");
    #else defined(__linux__) || defined(__unix__)
        system("read b");
    #endif
}
void console_clear(void) {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else defined(__linux__) || defined(__unix__)
        system("clear");
    #endif
    std::cout << "\nBuild date: " << __DATE__ << " " << __TIME__ << "\n";
}