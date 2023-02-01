#include <iostream>

void output (int a[][6])
{
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::cout << "Banquet table" << std::endl;

    int tableware[2][6] = {{4, 3, 3, 3, 3, 3},
                           {4, 3, 3, 3, 3, 3}};

    int plates[2][6] = {{3, 2, 2, 2, 2, 2},
                        {3, 2, 2, 2, 2, 2}};

    int chairs[2][6] = {{1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1, 1}};

    std::cout << "The hall before the banquet is prepared as follows:" << std::endl;
    std::cout << "Tableware:" << std::endl;
    output(tableware);
    std::cout << "Plates:" << std::endl;
    output(plates);
    std::cout << "chairs:" << std::endl;
    output(chairs);

    chairs[0][4] += 1;
    tableware[1][2] -= 1;
    tableware[0][0] -= 1;
    tableware[1][2] += 1;
    plates[0][0] -= 1;

    std::cout << "The hall after the events::" << std::endl;
    std::cout << "Tableware:" << std::endl;
    output(tableware);
    std::cout << "Plates:" << std::endl;
    output(plates);
    std::cout << "chairs:" << std::endl;
    output(chairs);


    return 0;
}
