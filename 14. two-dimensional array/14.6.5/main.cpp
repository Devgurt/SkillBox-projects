#include <iostream>
#include <vector>

std::vector<std::vector<bool>> initialization(std::vector<std::vector<bool>> vec)
{
   vec.resize(12, std::vector<bool>(12, true));
   return vec;
}

std::vector<std::vector<bool>> initialization_1(std::vector<std::vector<bool>> vec) //если вдруг первый способ не удовлетворяет поставленной задаче
{
    vec.resize(12);
    for (int i = 0; i < 12; i++) {
        vec[i].resize(12);
        for (int j = 0; j < 12; i++) {
            vec[i][j] = true;
        }
    }
}

void output (std::vector<std::vector<bool>> vec)
{
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            if (vec[i][j] == true) {
                std::cout << "O";
            } else {
                std::cout << "X";
            }
        }
        std::cout << std::endl;
    }
}

void pop (std::vector<std::vector<bool>> vec)
{
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0, co = 0;

    while (co < 144) {
        std::cout << "Input first coordinates (x, y): ";
        std::cin >> x1 >> y1;
        bool check = false;
        while (!check) {
            if (x1 < 0 || x1 >= vec.size() || y1 < 0 || y1 >= vec[x1].size()) {
                std::cout << "Incorrect input! Try again:";
                std::cin >> x1 >> y1;
            } else {
                check = true;
            }
        }

        std::cout << "Input second coordinates (x, y): ";
        std::cin >> x2 >> y2;
        check = false;
        while (!check) {
            if (x2 < 0 || x2 >= vec.size() || y2 < 0 || y2 >= vec[x2].size()) {
                std::cout << "Incorrect input! Try again:";
                std::cin >> x2 >> y2;
            } else {
                check = true;
            }
        }

        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                if (vec[i][j]) {
                    std::cout << "Pop!" << std::endl;
                    vec[i][j] = false;
                    co++;
                }
            }
        }

        output(vec);
    }
}

int main() {
    std::cout << "Bubble wrap" << std::endl;

    std::vector<std::vector<bool>> vec;
    vec = initialization(vec);
    output(vec);
    pop(vec);

    return 0;
}
