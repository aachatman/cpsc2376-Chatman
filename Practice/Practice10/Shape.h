#pragma once

#include <memory>

// Define M_PI if it's not already defined
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Base class Shape with a pure virtual method to get the area
class Shape {
public:
    virtual double getArea() const = 0;
    virtual ~Shape() = default;  // Virtual destructor for polymorphic deletion
};

// Derived class Rectangle
class Rectangle : public Shape {
public:
    Rectangle(double width, double height);
    double getArea() const override;

private:
    double width_;
    double height_;
};

// Derived class Circle
class Circle : public Shape {
public:
    Circle(double radius);
    double getArea() const override;

private:
    double radius_;
};
