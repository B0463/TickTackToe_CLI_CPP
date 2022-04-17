#include "prepros.h"

int main(void) {
    console_clear();
    std::cout << "\n";
    for (;;) {
        user_move();
        console_clear();
        if (check_part() != '0') {
            show_map();
            std::cout << "the winner is: " << check_part() << "\n";
            getch();
            exit(0);
        }
        pc_move();
        console_clear();
        if (check_part() != '0') {
            show_map();
            std::cout << "the winner is: " << check_part() << "\n";
            getch();
            exit(0);
        }
    }
    return 0;
}

char check_part(void) {
    if (map[0][0] == 'x' && map[0][1] == 'x' && map[0][2] == 'x') return 'x';
    if (map[1][0] == 'x' && map[1][1] == 'x' && map[1][2] == 'x') return 'x';
    if (map[2][0] == 'x' && map[2][1] == 'x' && map[2][2] == 'x') return 'x';
    if (map[0][0] == 'x' && map[1][0] == 'x' && map[2][0] == 'x') return 'x';
    if (map[0][1] == 'x' && map[1][1] == 'x' && map[2][1] == 'x') return 'x';
    if (map[0][2] == 'x' && map[1][2] == 'x' && map[2][2] == 'x') return 'x';
    if (map[0][0] == 'x' && map[1][1] == 'x' && map[2][2] == 'x') return 'x';
    if (map[2][0] == 'x' && map[1][1] == 'x' && map[0][2] == 'x') return 'x';
    if (map[0][0] == 'o' && map[0][1] == 'o' && map[0][2] == 'o') return 'o';
    if (map[1][0] == 'o' && map[1][1] == 'o' && map[1][2] == 'o') return 'o';
    if (map[2][0] == 'o' && map[2][1] == 'o' && map[2][2] == 'o') return 'o';
    if (map[0][0] == 'o' && map[1][0] == 'o' && map[2][0] == 'o') return 'o';
    if (map[0][1] == 'o' && map[1][1] == 'o' && map[2][1] == 'o') return 'o';
    if (map[0][2] == 'o' && map[1][2] == 'o' && map[2][2] == 'o') return 'o';
    if (map[0][0] == 'o' && map[1][1] == 'o' && map[2][2] == 'o') return 'o';
    if (map[2][0] == 'o' && map[1][1] == 'o' && map[0][2] == 'o') return 'o';
    else return '0';
}

int check_locale(int lcx, int lcy) {
    if (map[lcx][lcy] == '-') {
        return 1;
    }
    else {
        return 0;
    }
}

void user_move(void) {
    int usx;
    int usy;
    for (;;) {
        console_clear();
        show_map();
        std::cout << "\nEnter the X position of the move: ";
        std::cin >> usx;
        std::cout << "\nEnter the Y position of the move: ";
        std::cin >> usy;
        usy--;
        usx--;
        if (check_locale(usx, usy)) {
            map[usx][usy] = 'x';
            std::cout << "\nPC time\n";
            break;
        }
        else {
            std::cout << "\ninvalid input\n";
            getch();
        }
    }
}

void show_map(void) {
    std::cout << "\n  1 2 3  X\n";
    std::cout << "1 "<<map[0][0] << " " << map[1][0] << " " << map[2][0] << "\n";
    std::cout << "2 "<<map[0][1] << " " << map[1][1] << " " << map[2][1] << "\n";
    std::cout << "3 "<<map[0][2] << " " << map[1][2] << " " << map[2][2] << "\n";
    std::cout << "\nY\n";
}

void pc_move(void) {
    int pcx;
    int pcy;
    for (;;) {
        pcx = rand() % 3;
        pcy = rand() % 3;
        if (check_locale(pcx, pcy)) {
            map[pcx][pcy] = 'o';
            break;
        }
    }
}