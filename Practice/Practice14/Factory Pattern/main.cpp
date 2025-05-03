#include <iostream>
#include <memory>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

// Shape Base Class
class Shape {
public:
    virtual ~Shape() = default;
    virtual double area() const = 0;
};

// Concrete Shape Classes
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return M_PI * radius * radius;
    }
};

class Square : public Shape {
private:
    double side;
public:
    Square(double s) : side(s) {}
    double area() const override {
        return side * side;
    }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override {
        return width * height;
    }
};

// Shape Factory Class
class ShapeFactory {
public:
    static std::unique_ptr<Shape> createShape(const std::string& shapeType, const std::vector<double>& dimensions) {
        if (shapeType == "circle" && dimensions.size() == 1) {
            return std::make_unique<Circle>(dimensions[0]);
        }
        if (shapeType == "square" && dimensions.size() == 1) {
            return std::make_unique<Square>(dimensions[0]);
        }
        if (shapeType == "rectangle" && dimensions.size() == 2) {
            return std::make_unique<Rectangle>(dimensions[0], dimensions[1]);
        }
        return nullptr;
    }
};

// Function to read shapes from file
std::vector<std::unique_ptr<Shape>> readShapesFromFile(const std::string& filename) {
    std::vector<std::unique_ptr<Shape>> shapes;
    std::ifstream file(filename);
    
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return shapes;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string shapeType;
        ss >> shapeType;
        
        std::vector<double> dimensions;
        double dimension;
        while (ss >> dimension) {
            dimensions.push_back(dimension);
        }

        auto shape = ShapeFactory::createShape(shapeType, dimensions);
        if (shape) {
            shapes.push_back(std::move(shape));
        }
    }

    return shapes;
}

int main() {
    const std::string filename = "shapes.txt"; // Sample file: circle 5, square 4, rectangle 3 6
    std::vector<std::unique_ptr<Shape>> shapes = readShapesFromFile(filename);

    double totalArea = 0.0;
    for (const auto& shape : shapes) {
        totalArea += shape->area();
    }

    std::cout << "Total Area of Shapes: " << totalArea << std::endl;

    return 0;
}
