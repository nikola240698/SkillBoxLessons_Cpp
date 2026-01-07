#include <iostream>
#include <cassert>

float travelTime(float distance, float speed) {
    float time = distance / speed;
    assert(time > 0);
    return time;
}

int main() {

    float distance, speed;

    std::cout << "Program for calculating time travel" << std::endl;
    std::cout << std::endl;

    std::cout << "Input the distance: ";
    std::cin >> distance;
    std::cout << "Input the speed: ";
    std::cin >> speed;

    std::cout << "Travel time " << travelTime(distance, speed) << std::endl;

    return 0;
}
