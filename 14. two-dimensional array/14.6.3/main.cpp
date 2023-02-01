#include <iostream>

bool equality_check(int a[][4], int b[][4])
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (a[i][j] != b[i][j]) {
                std::cout << "The matrices are not equal!" << std::endl;
                return false;
            }
        }
    }
    std::cout << "The matrices are equal!" << std::endl;
    return true;
}

void d_shape(int a[][4])
{
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            a[i][j] = 0;
            a[j][i] = a[i][j];
        }
    }
}

void output (int a[][4])
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::cout << "Matrices" << std::endl;

    int a[4][4], b[4][4];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << "a[" << i << "][" << j << "] = ";
            std::cin >> a[i][j];
        }
    }

    std::cout << std::endl;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << "b[" << i << "][" << j << "] = ";
            std::cin >> b[i][j];
        }
    }

    if (equality_check(a, b)) {
        d_shape(a);
        std::cout << "D shape:" << std::endl;
        output(a);
    }

    return 0;
}
