#include <iostream>
#include <memory>
#include <vector>

// Observer Interface
class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(float grade) = 0;
};

// Concrete Observer: Averager
class Averager : public Observer {
private:
    float totalGrades = 0;
    int gradeCount = 0;

public:
    void update(float grade) override {
        totalGrades += grade;
        gradeCount++;
        std::cout << "New Average: " << totalGrades / gradeCount << std::endl;
    }
};

// Concrete Observer: Notifier
class Notifier : public Observer {
public:
    void update(float grade) override {
        if (grade < 60) {
            std::cout << "Email sent to student@example.com\n";
        }
    }
};

// GradeBook (Subject)
class GradeBook {
private:
    std::vector<std::shared_ptr<Observer>> observers;
    float grade;

public:
    void addObserver(std::shared_ptr<Observer> observer) {
        observers.push_back(observer);
    }

    void setGrade(float newGrade) {
        grade = newGrade;
        for (auto& observer : observers) {
            observer->update(grade);
        }
    }
};

int main() {
    GradeBook gradeBook;

    // Create observers
    std::shared_ptr<Averager> averager = std::make_shared<Averager>();
    std::shared_ptr<Notifier> notifier = std::make_shared<Notifier>();

    // Register observers
    gradeBook.addObserver(averager);
    gradeBook.addObserver(notifier);

    float newGrade;
    while (true) {
        std::cout << "Enter a new grade: ";
        std::cin >> newGrade;
        gradeBook.setGrade(newGrade);
    }

    return 0;
}
