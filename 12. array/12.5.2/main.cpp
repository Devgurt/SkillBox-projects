#include <iostream>

int main() {
    std::cout << "Sorting" << std::endl;

    float mas[15];
    for (int i = 0; i < 15; i++) {
        std::cin >> mas[i];
    }

    bool flag = true;
    int l = 15;
    while (flag) {
        flag = false;
        for (int i = 0; i < l; i++) {
            if (mas[i] < mas [i+1]) {
                std::swap(mas[i], mas[i+1]);
                flag = true;
            }
        }
        l--;
    }

    for (int i = 0; i < 15; i++) {
        std::cout << mas[i] << " ";
    }

    return 0;
}
