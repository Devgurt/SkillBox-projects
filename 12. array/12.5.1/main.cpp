#include <iostream>

int main() {
    std::cout << "Apartment building" << std::endl;
    std::string tenants[10];

    std::cout << "Please enter the names of the tenants by apartment:" << std::endl;

    for (int i = 0; i < 10; i++) {
        std::cout << "apartment " << i + 1 << " - ";
        std::cin >> tenants[i];
    }

    for (int i = 0, number = 0; i < 3; i++) {
        std::cin >> number;
        if (number =< 0 || number > 10) {
            std::cout << "Incorrect input" << std::endl;
        } else {
            std::cout << tenants[number - 1] << std::endl;
        }
    }

    return 0;
}
