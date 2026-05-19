#include <iostream>
#include <limits>
#include <string>
#include <vector>

// список комнат
enum RoomType {
    BEDROOM,
    KITCHEN,
    BATHROOM,
    CHILDREN,
    LIVING
};

// структура комнаты
struct Room {
    RoomType type;      // тип комнаты по списку
    double area;        // площадь комнаты
};

// структура этажа
struct Floor {
    int roomCo;                 // количество комнат
    double ceilingHeight;       // высота потолка в комнате
    std::vector<Room> rooms;    // список комнат
};

// тип постройки
enum BuildingType {
    HOUSE,
    GARAGE,
    SHED,
    BATHHOUSE
};

// структура постройки
struct Building {
    BuildingType type;          // тип постройки по списку
    double area;                // площадь постройки
    // для дома
    int floorCount;             // количество этажей
    std::vector<Floor> floors;  // вектор этажей
    // для печных зданий
    bool hasStove;              // наличие печи
    bool hasPipe;               // наличие трубы
};

// структура участка
struct Plot {
    int number;                         // номер участка
    std::vector<Building> buildings;    // строения на участке
};

// структура поселка
struct Village {
    std::vector<Plot> plots;        // вектор участков в поселке
};


// функция проверки целочисленных вводимых значений
int inputInt(const int lBord = -100, const int rBord = 100) {
    int number;
    while (true) {
        std::cin >> number;
        if (std::cin.fail() || std::cin.peek() != '\n'
                || number < lBord || number > rBord) {
            std::cerr << "Incorrect data" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            return number;
        }
    }
}

// функция проверки вещественных вводимых значений
double inputDouble() {
    double number;
    while (true) {
        std::cin >> number;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cerr << "Incorrect data" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            return number;
        }
    }
}

// функция ввода площади здания с проверкой вводимых значений
double buildArea () {
    std::cout << "Intput the area of the building: ";
    return inputDouble();
}

// функция создания комнаты на этаже
void createRoom(Floor &floor, const int &roomCo) {
    // вводим тип комнаты
    std::cout << "Select room type \"" << roomCo << "\":" << std::endl;
    std::cout << "BEDROOM - 1" << std::endl;
    std::cout << "KITCHEN - 2" << std::endl;
    std::cout << "BATHROOM - 3" << std::endl;
    std::cout << "CHILDREN - 4" << std::endl;
    std::cout << "LIVING - 5" << std::endl;

    int roomType = inputInt(1, 5);

    // вводим площадь комнаты
    std::cout << "Input the area of the room: ";
    double roomArea = inputDouble();

    // заполняем вектор "комнаты"
    if (roomType == BEDROOM) {
        floor.rooms.push_back({BEDROOM, roomArea});
    } else if (roomType == KITCHEN) {
        floor.rooms.push_back({BATHROOM, roomArea});
    } else if (roomType == BATHROOM) {
        floor.rooms.push_back({KITCHEN, roomArea});
    } else if (roomType == CHILDREN) {
        floor.rooms.push_back({CHILDREN, roomArea});
    } else if (roomType == LIVING) {
        floor.rooms.push_back({LIVING, roomArea});
    }

}


// функция создания этажа в доме
void createFloor(Building &house, const int &floorCo, const double &houseArea) {
    // создаем "этаж"
    Floor floor;

    // вводим количество комнат
    std::cout << "Input the number of rooms in the " << floorCo + 1 << " floor: ";
    floor.roomCo = inputInt();

    // вводим высоту потолка на этаже
    std::cout << "Input the ceil height of the floor: ";
    floor.ceilingHeight = inputDouble();

    // определяем тип и размер комнат на этаже
    for (int i = 0; i < floor.roomCo; i++) {
        createRoom(floor, i);

        // проверяем введенную площадь комнат по сравнению с домом
        double areaTmp = 0;
        int counter = -1;
        do {
            ++counter;
            areaTmp += floor.rooms[counter].area;
        } while (counter < i);
        if (areaTmp > houseArea) {
            std::cout << "The area of the rooms is larger than the area of the house!" << std::endl;
            std::cout << "Try again from the beginning:" << std::endl << std::endl;
            // очищаем ранее заполненный вектор и начинаем цикл с начала
            floor.rooms.clear();
            i = -1;
        }
    }

    // добавляем этаж в созданный дом
    house.floors.push_back(floor);
}


// функция создания дома на участке
void buildHouse(std::vector<Plot> &plots, int &plotCo) {
    // Создаем переменную "дом"
    Building house;
    // вводим его тип
    house.type = HOUSE;

    // просим ввести площадь постройки
    std::cout << "You have chosen HOUSE" << std::endl;
    house.area = buildArea();

    // просим ввести количество этажей в доме
    std::cout << "Input the number of floors in the house: ";
    house.floorCount = inputInt();

    // заполняем этажи комнатами
    for (int i = 0; i < house.floorCount; i++) {
        createFloor(house, i, house.area);
    }

    // узнаем о наличии трубы и печи в доме
    std::cout << "Is there a stove with a chimney in the house? (1/0): ";
    int stove = inputInt(0, 1);

    // устанавливаем "галочку"
    if (stove) {
        house.hasStove = true;
        house.hasPipe = true;
    }

    // "добавляем" введенный дом в участок
    plots[plotCo].buildings.push_back(house);
}

// функция создания гаража
void buildGarage(std::vector<Plot> &plots, const int plotCo) {
    std::cout << "You have chosen GARAGE" << std::endl;

    // создаем "гараж"
    Building garage;
    garage.type = GARAGE;

    // вводим площадь гаража
    garage.area = buildArea();

    // заполняем не нужные поля
    garage.floorCount = 0;
    garage.hasPipe = false;
    garage.hasStove = false;

    // "добавляем" введенный гараж в участок
    plots[plotCo].buildings.push_back(garage);
}

// функция создания сарая
void buildShed(std::vector<Plot> &plots, const int &plotCo) {
    std::cout << "You have chosen SHED" << std::endl;

    // создаем "сарай"
    Building shed;
    shed.type = SHED;

    // вводим площадь сарая
    shed.area = buildArea();

    // заполняем не нужные поля
    shed.floorCount = 0;
    shed.hasPipe = false;
    shed.hasStove = false;

    // "добавляем" введенный сарай в участок
    plots[plotCo].buildings.push_back(shed);
}

// функция создания бани
void buildBathhouse(std::vector<Plot> &plots, const int plotCo) {
    std::cout << "You have chosen BATHHOUSE" << std::endl;

    // создаем "баню"
    Building bathHouse;
    bathHouse.type = BATHHOUSE;

    // вводим площадь бани
    bathHouse.area = buildArea();

    // заполняем не нужные поля
    bathHouse.floorCount = 0;

    // узнаем о наличии трубы и печи в доме
    std::cout << "Is there a stove with a chimney in the bathhouse? (1/0): ";
    int stove = inputInt(0, 1);

    // устанавливаем "галочку"
    if (stove) {
        bathHouse.hasStove = true;
        bathHouse.hasPipe = true;
    }

    // "добавляем" введенную баню в участок
    plots[plotCo].buildings.push_back(bathHouse);
}


// функция выбора создания постройки на участке
void createBuilding(std::vector<Plot> &plots, const int &buildType, int &plotCo) {
    if (buildType == 1) {
        buildHouse(plots, plotCo);
    } else if (buildType == 2) {
        buildGarage(plots, plotCo);
    } else if (buildType == 3) {
        buildShed(plots, plotCo);
    } else if (buildType == 4) {
        buildBathhouse(plots, plotCo);
    }
}

// функция создания участков в поселке
void createPlots(Village &village) {
    // просим ввести количество участков
    std::cout << "Input the amount of plots: ";
    int plotNumber;
    std::cin >> plotNumber;

    // создаем вектор участков
    std::vector<Plot> plots(plotNumber);

    for (int i = 0; i < plots.size(); i++) {
        std::cout << "Input the plot[" << i << "] number :";
        std::cin >> plots[i].number;

        std::cout << "Intput the number of buildings on the " << plots[i].number << " plots:";
        int buildingsCo = 0;
        std::cin >> buildingsCo;

        for (int j = 0; j < buildingsCo; j++) {
            while (true) {
                std::cout << "Input the type of the " << j << " building: " << std::endl;
                std::cout << "1 - HOUSE \n2 - GARAGE \n3 - SHED \n4 - BATHHOUSE" << std::endl;
                int buildType;
                std::cin >> buildType;
                if (buildType > 0 && buildType < 5) {
                    createBuilding(plots, buildType, i);
                    break;
                }
                std::cout << "Incorrect data! Try again" << std::endl;
            }
        }

        // добавляем участки в поселок
        village.plots.push_back(plots[i]);
    }
}


int main() {

    std::cout << "A program for filling in data about a village" << std::endl << std::endl;

    // создаем поселок
    Village village;

    // начинаем создавать участок
    createPlots(village);

    std::cout << "That's all. The Village was created successfully." << std::endl;

    return 0;
}





