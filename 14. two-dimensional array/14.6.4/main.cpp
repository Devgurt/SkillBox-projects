#include <iostream>

void output (int a[])
{
    for (int i = 0; i < 4; i++) {
        std::cout << a[i] << " ";
    }
}

int main() {
    std::cout << "Multiplying" << std::endl;

    int a[4][4] = {{1, 2, 3, 4},
                   {1, 2, 3, 4},
                   {1, 2, 3, 4},
                   {1, 2, 3, 4}};

    int b[4] = {1, 1, 1, 1};

    int c[4];

    int sum = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            sum += a[i][j] * b[j];
        }
        c[i] = sum;
        sum = 0;
    }

    output(c);

    return 0;
}
