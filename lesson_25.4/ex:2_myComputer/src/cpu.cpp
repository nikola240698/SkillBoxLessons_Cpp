#include "cpu.h"
#include "ram.h"

void compute() {
    int data[8];
    read(data);

    int sum = 0;
    for (int i = 0; i < 8; ++i) {
        sum += data[i];
    }

    std::cout << "The sum = " << sum << std::endl;

}