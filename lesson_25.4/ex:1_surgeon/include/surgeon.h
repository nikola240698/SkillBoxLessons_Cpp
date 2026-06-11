#pragma once
#include <iostream>

struct Coordinates {
    double x;
    double y;
};

bool scalpel(const Coordinates &start, const Coordinates &end) {
    std::cout << "You have completed incision from ("
        << start.x << ";" << start.y << ") to ("
        << end.x << ";" << end.y << ")" << std::endl;
    return true;
}

void hemostat(const Coordinates &point) {
    std::cout << "You have installed the hemostat at the point ("
        << point.x << ";" << point.y << ")" << std::endl;
}

void tweezers(const Coordinates &point) {
    std::cout << "You used tweezers at the point ("
        << point.x << ";" << point.y << ")" << std::endl;
}

bool suture(const Coordinates &start, const Coordinates &end) {
    std::cout << "You put a suture from ("
        << start.x << ";" << start.y << ") to ("
        << end.x << ";" << end.y << ")" << std::endl;
    return true;
}

void comandList() {
    std::cout << "Select command:" << std::endl;
    std::cout << "1\t- scalpel" << std::endl;
    std::cout << "2\t- hemostat" << std::endl;
    std::cout << "3\t- tweezers" << std::endl;
    std::cout << "4\t- suture" << std::endl;
}
