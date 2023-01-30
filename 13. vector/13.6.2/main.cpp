#include <iostream>
#include <vector>

int main() {
    std::cout << "Purchase amount" << std::endl;

    std::vector<float> prices {2.5f, 4.25f, 3.0f, 10.0f};

    std::vector<int> items {1, 1, 0, 3, 2, 2, 1};

    bool mark = true;
    for (int i = 0; i < items.size(); i++) {
        if (items[i] >= prices.size()) {
            mark = false;
            break;
        }
    }

    if (mark) {
        float amount = 0.f;
        for (int i = 0; i < items.size(); i++) {
            amount += prices[items[i]];
        }

        std::cout << "Purchase total amount = " << amount << std::endl;
    } else {
        std::cout << "It seems that at least one value in the 'items' vector goes beyond the boundaries of the 'prices' vector" << std::endl;
    }

    return 0;
}
