#include "rectangle.h"

double Rectangle::square() {
    return width*height;
}

BoundingBoxDimension Rectangle::dimension() {
    BoundingBoxDimension rectangle;
    rectangle.width = width;
    rectangle.height = height;
    return rectangle;
}

std::string Rectangle::type() {
    return "Rectangle";
}
