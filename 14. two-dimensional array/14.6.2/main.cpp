#include <iostream>


void output (char a[][3])
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::cout << "Tic-tac-toe" << std::endl;

    char field[3][3] {{' ', ' ', ' '},
                      {' ', ' ', ' '},
                      {' ', ' ', ' '}};

    bool win = false;
    int x = 0, y = 0, co = 0;
    char gamerName = 'X';

    while (!win) {
        std::cout << "Gamer " << gamerName << ": ";
        std::cin >> x >> y;

        bool check = false;
        while(!check) {
            if (field[x][y] == ' ' && x >= 0 && x < 4 && y >= 0 && y < 4) {
                check = true;
            } else if (field[x][y] != ' ' && x >= 0 && x < 4 && y >= 0 && y < 4) {
                std::cout << "This cell is already occupied! Try again: ";
                std::cin >> x >> y;
            } else {
                std::cout << "Incorrect input! Try again: ";
                std::cin >> x >> y;
            }
        }

        field[x][y] = gamerName;

        co++;

        std::cout << "Game field:" << std::endl;
        output(field);

        if (field[x][0] == field[x][1] && field[x][1] == field[x][2] && field[x][0] != ' ' ||
            field[0][y] == field[1][y] && field[1][y] == field[2][y] && field[0][y] != ' ') {
            win = true;
            std::cout << "Gamer " << gamerName << " - winner!";
            break;
        }

        if (co == 9) {
            std::cout << "It's a draw!";
            break;
        }

        gamerName = gamerName == 'X' ? 'O' : 'X';
    }


    return 0;
}
