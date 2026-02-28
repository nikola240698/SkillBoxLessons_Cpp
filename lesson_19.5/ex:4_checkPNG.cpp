#include <iostream>
#include <string>
#include <fstream>

bool check_Extension(const std::string &str) {

    std::string extension = str.substr(str.length() - 4);

    if (extension == ".png" || extension == ".PNG") {
        return true;
    }
  
    return false;
}

bool check_Title(const char buffer[]) {

    bool valid = false;

    valid = buffer[0] == '-119' ? true : false;
    valid = buffer[1] == 'P'? true : false;
    valid = buffer[2] == 'N'? true : false;
    valid = buffer[3] == 'G'? true : false;

    return valid;
}


int main() {

    std::string path;

    std::cout << "---- Program for checking true PNG file -----" << std::endl;
    std::cout << std::endl;

    std::cout << "Input the path of the PNG file:" << std::endl;
    std::cout << "-> ";
    std::cin >> path;

    if (path.size() < 5 || check_Extension(path)) {
        std::ifstream extension;

        extension.open(path, std::ios::binary);

        if (extension.is_open()) {
            char buffer[5];

            extension.read(buffer, sizeof(buffer));
            buffer[4] = 0;
            extension.close();

            if (check_Title(buffer)) {
                std::cout << "The file is PNG" << std::endl;
                return 0;
            }
        } else {
            std::cout << "Invalid path of the file." << std::endl;
            return -1;
        }
    }

    std::cout << "This file is not a PNG!" << std::endl;

    return 0;
}
