#include <iostream>
#include <vector>

int main() {
    std::cout << "Purchase amount" << std::endl;

    std::vector<float> prices {2.5f, 4.25f, 3.0f, 10.0f};

    std::vector<int> items {1, 1, 0, 3, 2, 2, 1};

    float amount = 0.f;
    for (int i = 0; i < items.size(); i++) {
        amount += prices[items[i]];
    }

    std::cout << "Purchase total amount = " << amount << std::endl;
    return 0;
}
