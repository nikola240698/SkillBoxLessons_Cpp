#include "triangle.h"
#include <cmath>

double Triangle::square() {

    double p = (a + b +c) / 2;

    return sqrt(p * (p - a) * (p - b) * (p - c));
}

BoundingBoxDimension Triangle::dimension() {
    BoundingBoxDimension rectangle;

    double p = (a + b +c) / 2;

    double squareSide = a * b * c / (4 * sqrt(p * (p - a) * (p - b) * (p - c)));

    rectangle.width = 2 * squareSide;
    rectangle.height = 2 * squareSide;
    return rectangle;
}

std::string Triangle::type() {
    return "Triangle";
}
