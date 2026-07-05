#pragma once

#include <shape.h>

class Circle : public Shape {

    double radius = 0;

public:

    Circle(const double inRadius) : radius(inRadius) {}

    double square() override;

    BoundingBoxDimension dimension() override;

    std::string type() override;

};