#include <iostream>
#include <cstdio>

bool compare_min(const double &value, const double &compare, const double &delta) {
    return (value <= compare + delta);
}

bool compare_max(const double &value, const double &compare, const double &delta) {
    return (value >= compare - delta);
}

int main() {

    double speed_value = .0;
    double speed_delta;

    char speed_str[5];

    do {

        std::sprintf(speed_str, "%.1f", speed_value);
        std::cout << "Car seed: " << speed_str << "km/h" << std::endl;
        std::cout << "Input the Speed delta: ";
        std::cin >> speed_delta;

        speed_value += speed_delta;

        if (compare_max(speed_value, 150.0, 0.01)) {
            speed_value = 150.0;
            std::cout << "We have reached maximum speed" << std::endl;
        }

    } while (!compare_min(speed_value, 0.0, 0.01));

    std::cout << "Your car stopped" << std::endl;
    
    return 0;
}
