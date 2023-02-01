#include <iostream>

void output (int a[][5])
{
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::cout << "Snake passage" << std::endl;

    int a[5][5];
    int mult = -1, number = 0;

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
           a[i][2 + 2 * mult - j * mult] = number;
           number++;
        }
        mult *= -1;
    }

    output(a);

    return 0;
}

