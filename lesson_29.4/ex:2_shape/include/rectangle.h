#pragma once

#include <shape.h>

class Rectangle : public Shape {
    
    double width = 0;
    double height = 0;
    
public:
    
    Rectangle(const double inWidth, const double inHeight)
        : width(inWidth), height(inHeight) {}
    
    double square() override;
    
    BoundingBoxDimension dimension() override;
    
    std::string type() override;
    
};