#include <iostream>
#include <limits>

int inputNum(const int &lBor, const int &rBor) {
    while(true)
    {
        int value;
        std::cin >> value;
        if (std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cerr << "Incorrect data" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (value < lBor || value > rBor) {
            std::cout << "Incorrect coordinates" << std::endl;
        } else {
            return value;
        }
    }
}

void inputMap(int arr[][5]) {

    std::cout << "Input the terrain height map" << std::endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << "pos" << i << j << ": ";
            arr[i][j] = inputNum(0, 10);
        }
    }

}

void showArr(int arr[][5]) {

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

}

void createWorld(int world[][5][10], const int map[][5]) {

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 10; k++) {
                if (k > map[i][j]) {
                    world[i][j][k] = 0;
                } else {
                    world[i][j][k] = 1;
                }
            }

        }
    }
}

void sliceMap(const int world[][5][10], int slice[][5],const int cut) {

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (world[i][j][cut]) {
                slice[i][j] = 1;
            } else {
                slice[i][j] = 0;
            }
        }

    }
    showArr(slice);
}

int main() {

    int world[5][5][10];
    int mapHeight[5][5];
    
    int slice[5][5];

    std::cout << "Program for displaying a slice of the cubic world" << std::endl;
    std::cout << std::endl;

    inputMap(mapHeight);
    createWorld(world, mapHeight);

    showArr(mapHeight);

    while (true) {
        std::cout << "Input the cutting height: ";
        int cutLevel = inputNum(-1, 9);
        if (cutLevel == -1) break;

        sliceMap(world, slice, cutLevel);

        std::cout << std::endl;
    }

    return 0;
}
