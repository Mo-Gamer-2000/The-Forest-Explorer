#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <cstdlib>

using namespace std;

class Model
{
public:
    Model() : score(0), health(100), inventory() {}

    void add_points(int points) {
        score += points;
    }

    void take_damage(int damage) {
        health -= damage;
    }

    void add_to_inventory(std::string item) {
        inventory.push_back(item);
    }

    int get_score() {
        return score;
    }

    int get_health() {
        return health;
    }

    std::vector<std::string> get_inventory() {
        return inventory;
    }
private:
    int score;
    int health;
    std::vector<std::string> inventory;
};

class View
{
public:
private:
};

class Controller
{
public:
    void display_score(int score) {
        std::cout << "Your current score is: " << score << std::endl;
    }

    void display_health(int health) {
        std::cout << "Your current health is: " << health << std::endl;
    }

    void display_inventory(std::vector<std::string> inventory) {
        std::cout << "Your current inventory is: ";
        for (std::string item : inventory) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }

    void display_options() {
        std::cout << "What would you like to do?" << std::endl;
        std::cout << "1. Explore the forest" << std::endl;
        std::cout << "2. View your stats" << std::endl;
        std::cout << "3. Quit" << std::endl;
    }

    void display_encounter_result(bool win, std::string item) {
        if (win) {
            std::cout << "Congratulations, you won the encounter!" << std::endl;
            std::cout << "You found a " << item << "." << std::endl;
        }
        else {
            std::cout << "Sorry, you lost the encounter." << std::endl;
        }
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}