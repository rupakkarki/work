#include <iostream>
#include <string>

class Exercise {
private:
    std::string name;
    std::string description;
    std::string musclesWorked;
    std::string equipment;

public:
    Exercise(const std::string& name, const std::string& description, const std::string& musclesWorked, const std::string& equipment)
        : name(name), description(description), musclesWorked(musclesWorked), equipment(equipment) {}

    void display() const {
        std::cout << "Exercise: " << name << std::endl;
        std::cout << "Description: " << description << std::endl;
        std::cout << "Muscles Worked: " << musclesWorked << std::endl;
        std::cout << "Equipment: " << equipment << std::endl;
    }
};

class FitnessApp {
public:
    void showLatPulldown() const {
        Exercise latPulldown(
            "Lat Pulldown",
            "Sit at a lat pulldown machine and grasp the bar with a wide overhand grip. Pull the bar down to your chest, squeezing your shoulder blades together. Slowly return to the starting position.",
            "Latissimus Dorsi, Biceps, Shoulders",
            "Lat Pulldown Machine"
        );
        latPulldown.display();
    }
};

int main() {
    FitnessApp app;
    app.showLatPulldown();
    return 0;
}
