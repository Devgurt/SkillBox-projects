#include <iostream>
#include <cmath>

void initialisation (bool a[][10])
{
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            a[i][j] = false;
        }
    }
}

void war_fog_ini (char b[][10])
{
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            b[i][j] = '.';
        }
    }
}

void output (bool a[][10], char b[][10])
{
    std::cout << "Player's field\t\t\t\t\t\t\t\tEnemy field" << std::endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) {
            if (j < 10) {
                if (a[i][j]) {
                    std::cout << "#\t";
                } else {
                    std::cout << ".\t";
                }
            } else if (j == 10) {
                std::cout << "\t" << b[i][j - 10];
            } else {
                std::cout << "\t" << b[i][j - 10];
            }
        }
        std::cout << std::endl;
    }
}

bool flag (bool a[][10], int x1, int x2, int y1, int y2, int k)
{
    for (int n = 0; n <= k; n++) {
        if (x1 == x2) {
            if (y1 < y2) {
                if (a[x1][y1 + n]) {
                    return false;
                } else {
                    return true;
                }
            } else {
                if (a[x1][y2 + n]) {
                    return false;
                } else {
                    return true;
                }
            }
        } else {
            if (x1 < x2){
                if (a[x1 + n][y1]) {
                    return false;
                } else {
                    return true;
                }
            } else {
                if (a[x2 + n][y1]) {
                    return false;
                } else {
                    return true;
                }
            }
        }
    }
}

void placement (bool a[][10], int n)
{
    std::cout << "Placement of player " << n << " ships" << std::endl;
    int k = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    for (int i = 1; i < 5; i++) {
        for (int j = 0; j < 4 - k; j++) {
            if (k == 0) {
                std::cout << "Input the coordinates (x, y) of the "<< j + 1 << " " << i << "-deck ship: ";
                std::cin >> x1 >> y1;

                bool check = false;
                while (!check) {
                    if (x1 < 0 || x1 > 9 || y1 < 0 || y1 > 9) {
                        std::cout << "Incorrect input! Try again: ";
                        std::cin >> x1 >> y1;
                    } else if (a[x1][y1]) {
                        std::cout << "The cell is already occupied by another ship! Try again: ";
                        std::cin >> x1 >> y1;
                    } else {
                        a[x1][y1] = true;
                        check = true;
                    }
                }
            } else {
                std::cout << "Input the coordinates (x1, y1, x2, y2) of the "<< j + 1 << " " << i << "-deck ship: ";
                std::cin >> x1 >> y1 >> x2 >> y2;

                bool check = false;
                while (!check) {
                    if (x1 < 0 || x1 > 9 || y1 < 0 || y1 > 9 || x2 < 0 || x2 > 9 ||
                            y2 < 0 || y2 > 9 || x1 == x2 && y1 == y2) {
                        std::cout << "Incorrect input! Try again: ";
                        std::cin >> x1 >> y1 >> x2 >> y2;
                    } else if (x1 != x2 && y1 != y2) {
                        std::cout << "Ships can only be positioned vertically or horizontally! Try again: ";
                        std::cin >> x1 >> y1 >> x2 >> y2;
                    } else if (y1 == y2 && std::abs(x1 - x2) != k || x1 == x2 && std::abs(y1 - y2) != k) {
                        std::cout << "Incorrect input! Try again: ";
                        std::cin >> x1 >> y1 >> x2 >> y2;
                    } else if (!flag(a, x1, x2, y1, y2, n)){
                        std::cout << "The cell is already occupied by another ship! Try again: ";
                        std::cin >> x1 >> y1 >> x2 >> y2;
                    } else {
                        for (int n = 0; n <= k; n++) {
                            if (x1 == x2) {
                                if (y1 < y2) {
                                    a[x1][y1 + n] = true;
                                } else {
                                    a[x1][y2 + n] = true;
                                }
                            } else {
                                if (x1 < x2){
                                    a[x1 + n][y1] = true;
                                } else {
                                    a[x2 + n][y1] = true;
                                }
                            }
                        }
                        check = true;
                    }
                }
            }
        }
        k++;
    }
}

void shooting (bool a[][10], bool b[][10], char af[][10], char bf[10][10])
{
    int d1 = 0, d2 = 0, n = 1, x = 0, y = 0;
    while (d1 < 20 || d2 < 20) {
        bool hit = false;
        std::cout << "Player " << n << " move" << std::endl;
        if (n == 1) {
            output (a, bf);
        } else {
            output (b, af);
        }
        std::cout << "Shooting coordinates (x, y): ";
        std::cin >> x >> y;

        if (n == 1 && b[x][y]) {
            hit = true;
            d1++;
            b[x][y] = false;
            bf[x][y] = 'X';
            std::cout << "Hit!" << std::endl;
            while (hit) {
                output (a, bf);
                std::cout << "Shooting coordinates (x, y): ";
                std::cin >> x >> y;
                if (b[x][y]) {
                    b[x][y] = false;
                    bf[x][y] = 'X';
                    d1++;
                    std::cout << "Hit!" << std::endl;
                } else {
                    std::cout << "Miss :(" << std::endl;
                    hit = false;
                    n = 2;
                    af[x][y] = 'o';
                }
            }
        } else if (n == 2 && a[x][y]) {
            hit = true;
            d2++;
            a[x][y] = false;
            af[x][y] = 'X';
            std::cout << "Hit!" << std::endl;
            while (hit) {
                output (b, af);
                std::cout << "Shooting coordinates (x, y): ";
                std::cin >> x >> y;
                if (a[x][y]) {
                    a[x][y] = false;
                    af[x][y] = 'X';
                    d2++;
                    std::cout << "Hit!" << std::endl;
                } else {
                    std::cout << "Miss :(" << std::endl;
                    hit = false;
                    n = 1;
                    bf[x][y] = 'o';
                }
            }
        } else if (n == 1 && !b[x][y]) {
            std::cout << "Miss :(" << std::endl;
            n = 2;
            bf[x][y] = 'o';
        } else if (n == 2 && !a[x][y]) {
            std::cout << "Miss :(" << std::endl;
            n = 1;
            af[x][y] = 'o';
        }

    }

    if (d1 == 20) {
        std::cout << "Player 1 WIN!" << std::endl;
        std::cout << "Game over" << std::endl;
    } else if (d2 == 20) {
        std::cout << "Player 2 WIN!" << std::endl;
        std::cout << "Game over" << std::endl;
    }
}

int main() {
    std::cout << "Sea battle" << std::endl;

    bool field_1[10][10], field_2[10][10];

    char war_fog_1[10][10], war_fog_2[10][10];

    initialisation (field_1);
    initialisation (field_2);
    war_fog_ini(war_fog_1);
    war_fog_ini(war_fog_2);

    placement (field_1, 1);
    placement (field_2, 2);

    shooting (field_1, field_2, war_fog_1, war_fog_2);

    return 0;
}


