#include <iostream>
#include <cassert>

float travelTime(float distance, float speed) {
    assert (speed > 0);
    return distance / speed;
}

int main() {
    std::cout << "Using assert" << std::endl;
    float distance = 0, speed = 0;

    std::cin >> distance >> speed;

    std::cout << "Travel time = " << travelTime(distance, speed) << std::endl;
    return 0;
}
