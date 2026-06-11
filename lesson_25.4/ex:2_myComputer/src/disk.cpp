#include "disk.h"
#include "ram.h"
#include <fstream>

void save() {
    int data[8];
    read(data);
    std::ofstream file("data.txt");
    for (int i = 0; i < 8; ++i) {
        file << data[i] << std::endl;
    }
    file.close();
}

void load() {
    int data[8];
    std::ifstream file;
    file.open("data.txt");
    if (file.is_open()) {
        for (int i = 0; i < 8; ++i) {
            file >> data[i];
        }
        file.close();
        write(data);
    } else {
        std::cout << "File doesn't exist!" << std::endl;
    }
}