#pragma once

#include <shape.h>

class Triangle : public Shape {

    double a = 0;
    double b = 0;
    double c = 0;

public:

    Triangle(const double inA, const double inB, const double inC)
        : a(inA), b(inB), c(inC) {}

    double square() override;

    BoundingBoxDimension dimension() override;

    std::string type() override;

};