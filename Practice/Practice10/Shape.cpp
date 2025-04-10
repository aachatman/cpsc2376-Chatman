#include "Shape.h"
#include <cmath>

// Rectangle Constructor
Rectangle::Rectangle(double width, double height) : width_(width), height_(height) {}

// Rectangle getArea() method
double Rectangle::getArea() const {
    return width_ * height_;
}

// Circle Constructor
Circle::Circle(double radius) : radius_(radius) {}

// Circle getArea() method
double Circle::getArea() const {
    return M_PI * radius_ * radius_;
}
