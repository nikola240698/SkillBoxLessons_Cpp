#pragma once

#include <string>
#include <iostream>


struct BoundingBoxDimension {

    double width = 0;
    double height = 0;

};


class Shape {

public:

    virtual double square() = 0;

    virtual BoundingBoxDimension dimension() = 0;

    virtual std::string type() = 0;

    void printParams(Shape* shape);

};
