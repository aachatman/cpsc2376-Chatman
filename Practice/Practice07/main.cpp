#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>

// Base Class: Employee
class Employee {
protected:
    std::string name;
    int id;

public:
    Employee(std::string name, int id) : name(name), id(id) {}

    virtual double calculateSalary() const = 0;  // Pure virtual function
    virtual void displayInfo() const {
        std::cout << "ID: " << id << ", Name: " << name;
    }

    virtual ~Employee() = default;  // Virtual destructor for proper cleanup
};

// Derived Class: SalariedEmployee
class SalariedEmployee : public Employee {
private:
    double monthlySalary;

public:
    SalariedEmployee(std::string name, int id, double monthlySalary)
        : Employee(name, id), monthlySalary(monthlySalary) {}

    double calculateSalary() const override {
        return monthlySalary;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << ", Type: Salaried, Monthly Salary: $" << monthlySalary << std::endl;
    }
};

// Derived Class: HourlyEmployee
class HourlyEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;

public:
    HourlyEmployee(std::string name, int id, double hourlyRate, int hoursWorked)
        : Employee(name, id), hourlyRate(hourlyRate), hoursWorked(hoursWorked) {}

    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << ", Type: Hourly, Hours Worked: " << hoursWorked
                  << ", Hourly Rate: $" << hourlyRate
                  << ", Salary: $" << calculateSalary() << std::endl;
    }
};

// Derived Class: CommissionEmployee
class CommissionEmployee : public Employee {
private:
    double baseSalary;
    double salesAmount;
    double commissionRate;

public:
    CommissionEmployee(std::string name, int id, double baseSalary, double salesAmount, double commissionRate)
        : Employee(name, id), baseSalary(baseSalary), salesAmount(salesAmount), commissionRate(commissionRate) {}

    double calculateSalary() const override {
        return baseSalary + (salesAmount * commissionRate);
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << ", Type: Commission, Base Salary: $" << baseSalary
                  << ", Sales: $" << salesAmount
                  << ", Commission Rate: " << commissionRate * 100 << "%"
                  << ", Salary: $" << calculateSalary() << std::endl;
    }
};

// Function to read employees from a file
void readEmployeesFromFile(const std::string& filename, std::vector<std::unique_ptr<Employee>>& employees) {
    std::ifstream file(filename);
    std::string type, name;
    int id;
    double salaryDetails[3];  // Will store salary-related details based on the employee type

    if (file.is_open()) {
        while (file >> type >> id) {
            std::getline(file, name);  // To read the full name (including spaces)
            if (name.empty()) continue; // Skip if name is empty after reading

            if (type == "Salaried") {
                if (!(file >> salaryDetails[0])) {
                    std::cerr << "Invalid data for Salaried Employee" << std::endl;
                    continue;
                }
                employees.push_back(std::make_unique<SalariedEmployee>(name, id, salaryDetails[0]));
            }
            else if (type == "Hourly") {
                if (!(file >> salaryDetails[0] >> salaryDetails[1])) {
                    std::cerr << "Invalid data for Hourly Employee" << std::endl;
                    continue;
                }
                employees.push_back(std::make_unique<HourlyEmployee>(name, id, salaryDetails[0], static_cast<int>(salaryDetails[1])));
            }
            else if (type == "Commission") {
                if (!(file >> salaryDetails[0] >> salaryDetails[1] >> salaryDetails[2])) {
                    std::cerr << "Invalid data for Commission Employee" << std::endl;
                    continue;
                }
                employees.push_back(std::make_unique<CommissionEmployee>(name, id, salaryDetails[0], salaryDetails[1], salaryDetails[2]));
            }
            else {
                std::cerr << "Unknown employee type: " << type << std::endl;
            }
        }
        file.close();
    } else {
        std::cerr << "Error opening file." << std::endl;
    }
}

int main() {
    std::vector<std::unique_ptr<Employee>> employees;

    // Read the employees from the file
    readEmployeesFromFile("employees.txt", employees);

    // Display information for all employees
    for (const auto& employee : employees) {
        employee->displayInfo();
    }

    // No need to manually free memory, smart pointers will do that automatically

    return 0;
}
