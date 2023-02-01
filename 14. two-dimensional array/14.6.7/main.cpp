#include <iostream>

void output (bool a[][5][5], int level)
{
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << a[i][j][level] << " ";
        }
        std::cout << std::endl;
    }
}

void world_initialisation(bool world[][5][5], int heights[][5])
{
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if(heights[i][j] - k > 0) {
                    world[i][j][k] = 1;
                } else {
                    world[i][j][k] = 0;
                }
            }
        }
    }
}

void slicing(bool world[][5][5])
{
    int level = 0;
    while (level != -1) {
        std::cout << "Input slice: ";
        std::cin >> level;
        assert(level >= 0 && level < 5);
        if (level == -1) {
            break;
        } else {
            output(world, level);
        }
    }
}

int main() {
    std::cout << "Almost \"Minecraft\"" << std::endl;

    int heights[5][5] = {{5, 5, 5, 5, 5},
                          {4, 4, 4, 4, 4},
                          {3, 2, 2, 2, 3},
                          {2, 1, 1, 1, 2},
                          {1, 1, 1, 1, 1}};

    bool world[5][5][5];

    world_initialisation(world, heights);

   slicing(world);

    return 0;
}
