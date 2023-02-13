#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class Model {
public:
    Model() : score(0), health(100) {}

    void add_to_inventory(string item) {
        inventory.push_back(item);
    }

    int get_score() {
        return score;
    }

    int get_health() {
        return health;
    }

    vector<string> get_inventory() {
        return inventory;
    }

    void update_score(int new_score) {
        score = new_score;
    }

    void update_health(int new_health) {
        health = new_health;
    }

private:
    int score;
    int health;
    vector<string> inventory;
};

class PlayerModel : public Model {
public:
    PlayerModel(string name) : Model(), name(name), level(1), experience(0) {}

    void set_name(string new_name) {
        name = new_name;
    }

    string get_name() {
        return name;
    }

    int get_level() {
        return level;
    }

    int get_experience() {
        return experience;
    }

    void add_experience(int new_experience) {
        experience += new_experience;
        if (experience >= 100) {
            level++;
            experience -= 100;
        }
    }

private:
    string name;
    int level;
    int experience;
};

class View {
public:
    void display_menu() {
        cout << "What would you like to do?" << endl;
        cout << "1. Explore the forest" << endl;
        cout << "2. View your stats" << endl;
        cout << "3. Quit" << endl;
    }

    void display_score(int score) {
        cout << "Your current score is: " << score << endl;
    }

    void display_health(int health) {
        cout << "Your current health is: " << health << endl;
    }

    void display_inventory(vector<string> inventory) {
        cout << "Your current inventory is: ";
        for (string item : inventory) {
            cout << item << " ";
        }
        cout << endl;
    }

    void display_result(bool win, string item) {
        if (win) {
            cout << "Congratulations, you won the encounter!" << endl;
            cout << "You found a " << item << "." << endl;
        }
        else {
            cout << "Sorry, you lost the encounter." << endl;
            cout << "You lost 10 health points." << endl;
        }
    }
};

class Controller {
public:
    Controller() : model(), view() {}

    void play_game() {
        while (true) {
            view.display_menu();
            int choice;
            cin >> choice;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid choice. Please try again and enter a number." << endl;
            }
            else {
                if (choice == 1) {
                    bool win = rand() % 2 == 0;
                    string item;
                    if (win) {
                        item = "Apple";
                        model.update_score(model.get_score() + 10);
                        model.add_to_inventory(item);
                    }
                    else {
                        item = "";
                        model.update_health(model.get_health() - 10);
                    }
                    view.display_result(win, item);
                }
                else if (choice == 2) {
                    view.display_score(model.get_score());
                    view.display_health(model.get_health());
                    view.display_inventory(model.get_inventory());
                }
                else if (choice == 3) {
                    break;
                }
                else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
        }
    }

private:
    Model model;
    View view;
};



int main() {
    srand(time(0));
    Controller controller;
    controller.play_game();
    return 0;
}

