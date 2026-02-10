#include <iostream>

bool isSubstring(const char* text, const char* word) {
    int stPos = 0;

    while (*(text + stPos) != '\0') {
      
        bool match = true;
        int i = 0;
      
        while (*(word + i) != '\0') {
            if (*(text + stPos + i) == '\0'
                    || *(word + i) != *(text + stPos + i)) {
                match = false;
                break;
            }
            ++i;
        }
      
        if (match) {
            return true;
        }
        ++stPos;
    }
    return false;
}

int main() {

    const char* a = "Hello world!";
    const char* b = "wor";
    const char* c = "banana";

    std::cout << isSubstring(a, b) << " - " << isSubstring(a, c) << std::endl;

    return 0;
}
