#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <sstream>
#include <iomanip> // For controlling output precision
#include "Shape.h"  // Include the Shape header

// Function to print all areas with a precision of 4 decimal places
void printAllAreas(const std::vector<std::unique_ptr<Shape>>& shapes) {
    for (const auto& shape : shapes) {
        std::cout << "Area: " << std::fixed << std::setprecision(4) << shape->getArea() << std::endl;
    }
}

// Function to read shapes from a file and create appropriate objects
std::vector<std::unique_ptr<Shape>> readShapesFromFile(const std::string& filename) {
    std::vector<std::unique_ptr<Shape>> shapes;
    std::ifstream file(filename);
    std::string shapeType;

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return shapes;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        iss >> shapeType;

        if (shapeType == "rectangle") {
            double width, height;
            if (iss >> width >> height) {
                shapes.push_back(std::make_unique<Rectangle>(width, height));
            }
        } else if (shapeType == "circle") {
            double radius;
            if (iss >> radius) {
                shapes.push_back(std::make_unique<Circle>(radius));
            }
        }
    }

    file.close();
    return shapes;
}

int main() {
    const std::string filename = "shapes.txt"; // The input file containing shapes

    // Read shapes from the file and store them in a vector
    std::vector<std::unique_ptr<Shape>> shapes = readShapesFromFile(filename);

    // Print the area of all shapes with the specified format
    printAllAreas(shapes);

    return 0;
}
