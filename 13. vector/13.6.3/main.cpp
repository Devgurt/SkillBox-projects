#include <iostream>
#include <vector>

int main() {
    std::cout << "Ring buffer" << std::endl;

    std::vector<int> rb(4);
    int mark = 0, count = 0;
    bool flag = false;

    std::cin >> mark;

    while (mark != -1) {
        if (count < rb.size()) {
            rb[count] = mark;
            count++;
        } else {
            count = 0;
            rb[count] = mark;
            count++;
            flag = true;
        }
        std::cin >> mark;
    }

    for (int i = 0; i < rb.size(); i++) {
        if (flag && count + i < rb.size()) {
            std::cout << rb[count + i] << " ";
        } else if (flag && count + i >= rb.size()) {
            std::cout << rb[(count + i) - rb.size()] << " ";
        } else {
            std::cout << rb[i] << " ";
            if (i == count - 1) {
                break;
            }
        }
    }

    return 0;
}
