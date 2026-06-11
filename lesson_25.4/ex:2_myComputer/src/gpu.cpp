#include "gpu.h"
#include "ram.h"

void showBuffer() {
    int data[8];
    read(data);
    for (int i = 0; i < 8; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}