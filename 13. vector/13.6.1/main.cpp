#include <iostream>
#include <vector>

int main() {
    std::cout << "Removing a value from a vector" << std::endl;

    int n = 0;
    std::cout << "Enter the size of the vector 'n' = ";
    std::cin >> n;
    bool check = false;
    while (!check) {
        if (n > 0) {
            check = true;
        } else {
            std::cout << "Incorrect input!" << std::endl;
            std::cout << "'n' = ";
            std::cin >> n;
        }
    }

    std::vector<int> vec(n);

    for (int i = 0; i < n; i++) {
        std::cout << "vec[" << i << "] = ";
        std::cin >> vec[i];
    }

    std::cout << "Enter which value you would like to remove from the vector = ";
    std::cin >> n;


    bool mark = false;
    int k = 0;
    for (int i = 0; i < vec.size() - k; i++) {
        if (vec[i] == n) {
            for (int l = 0; l < vec.size() - i - 1; l++) {
                std::swap(vec[i+l], vec[i+l+1]);
            }
            k++;
            mark = true;
        }
    }

    for (int i = 0; i < k; i++) {
        vec.pop_back();
    }

    if (!mark) {
        std::cout << "It looks like the value you wanted to delete was not found in the vector." << std::endl;
    }


    std::cout << "Your final vector:" << std::endl;
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }

    return 0;
}