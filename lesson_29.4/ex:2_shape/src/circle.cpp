#include "circle.h"
#include <numbers>

double Circle::square() {
    return std::numbers::pi * radius * radius;
}

BoundingBoxDimension Circle::dimension() {
    BoundingBoxDimension rectangle;
    rectangle.width = radius * 2;
    rectangle.height = radius * 2;
    return rectangle;
}

std::string Circle::type() {
    return "Circle";
}
