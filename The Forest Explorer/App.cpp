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
private:
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}