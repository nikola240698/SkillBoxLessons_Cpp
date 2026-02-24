#include <iostream>
#include <fstream>
#include <cstring>

int main() {

    char buffer[20];
    std::ifstream stream;
    std::string path;

    std::cout << "--- Program for reading text files ---" << std::endl;
    std::cout << std::endl;

    while (true) {
        std::cout << "Input the file path -> ";
        std::cin >> path;

        stream.open(path, std::ios::binary);

        if (stream.is_open()) {
            std::cout << "File opened successfully!" << std::endl;
            std::cout << "Reading..." << std::endl;
            std::cout << std::endl;
           
          while (!stream.eof()) {
                stream.read(buffer, sizeof(buffer) - 1);
                buffer[19] = 0;
                std::cout << buffer;
            }
            std::cout << std::endl;
            break;
        }
        std::cout << "Incorrect file path!" << std::endl << "Try again." << std::endl;
    }

    std::cout << std::endl;
    std::cout << "File reading completed!" << std::endl;

    return 0;
}
