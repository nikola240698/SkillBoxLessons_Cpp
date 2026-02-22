#include <iostream>
#include <fstream>
#include <cstring>

int main() {

    std::string path = "D:\\Projects\\Cpp\\skillBoxLessons\\words.txt";

    std::cout << "--- Program for counting the number of words in a text file ----" << std::endl;
    std::cout << "Current file path: " << std::endl;
    std::cout << path << std::endl;

    std::ifstream dictonary;
    dictonary.open(path);

    std::string text;
    std::string word;

    std::cout << "Input the word to search: ";
    std::cin >> word;

    int count = 0;
    while (!dictonary.eof()) {
        dictonary >> text;
        if (text == word) {
            ++count;
        }
    }

    std::cout << "The word \"" << word << "\" appears " << count << " times in the file";

    return 0;
}
