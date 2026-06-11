#include "ram.h"

static int buffer[8] = {0};

void write(const int data[]) {
    for (int i = 0; i < 8; ++i) {
        buffer[i] = data[i];
    }
}

void read(int data[]) {
    for (int i = 0; i < 8; ++i) {
        data[i] = buffer[i];
    }
}
