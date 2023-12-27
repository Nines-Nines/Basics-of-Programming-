#include <iostream>
using namespace std;
class Animal {//Parent class
public:
    Animal(const string& name) : name(name), orientation(0),hunger(100), happiness(0) {}

    void feedMeat() {//functions for interacting with the animals
        if (orientation==0){
            if (hunger <=10) hunger = 0;
            else hunger -=  10;

            if (happiness >= 95) happiness = 100;
            else happiness += 5;
        }else{
            if (happiness <= 10) happiness = 0;
            else happiness -= 10;
        }

    }

    void feedGrass() {//functions for interacting with the animals
        if (orientation==1){
            if (hunger <=10) hunger = 0;
            else hunger -=  10;

            if (happiness >= 95) happiness = 100;
            else happiness += 5;
        }else{
            if (happiness <= 10) happiness = 0;
            else happiness -= 10;
        }

    }

    void pet(){
        if (happiness >= 85) happiness = 100;
        else happiness += 15;


        if (hunger >= 95) hunger = 100;
        else hunger += 5;
    }

    void displayStatus() const {
        cout << name << endl << "Hunger: " << hunger << endl <<"Happiness: " << happiness << endl;
    }

    virtual void makeSound() const = 0;
    virtual void DontEat() const=0;
    virtual void Eat() const=0;

public:
    string name;
    int hunger;
    int happiness;
    bool orientation;
};

class Lion : public Animal
{
public:
    Lion(const string& name) : Animal(name) {}

    void DontEat() const override {
        cout << "I'm Lion, I won't eat grass!!" << endl;
    }

    void Eat() const override {
        cout << "I'm Lion, this meat was tasty" << endl;
    }

    void makeSound() const override {
        cout << name << " - ""Hi, I'm Alex""" << endl;
    }
};

class Zebra : public Animal
{
public:
    Zebra(const string& name) : Animal(name) {}

    void DontEat() const override{
        cout << "I'm ZEBRA, I won't eat meat!!" << endl;
    }

    void Eat() const override {
        cout << "I'm Zebra, this grass was tasty" << endl;
    }

    void makeSound() const override {
        cout << name << " Hi there!!" << endl;
    }
};

class Behemoth : public Animal
{
public:
    Behemoth(const string& name) : Animal(name) {}

    void DontEat() const override{
        cout << "I'm Behemoth, I won't eat grass!!" << endl;
    }

    void Eat() const override {
        cout << "I'm Behemoth, this meat was tasty" << endl;
    }

    void makeSound() const override {
        cout << name << " - Did you see the Melman?" << endl;
    }
};

class Girafe : public Animal
{
public:
    Girafe(const string& name) : Animal(name) {}

    void DontEat() const override{
        cout << "I'm Girafe, I won't eat meat!!" << endl;
    }

    void Eat() const override {
        cout << "I'm Girafe, this grass was tasty" << endl;
    }

    void makeSound() const override
    {
        cout << name << " - What time is it??" << endl;
    }
};

int main()
{
    Lion lion("Alex");
    Zebra zebra("Marti");
    Behemoth behemoth("Gloria");
    Girafe girafe("Melman");

    while (true) {
        cout << "Welcome to the Zoo! \nChoose an animal to interact with \n1 - Lion \n2 - Zebra \n3 - Behemoth \n4 - Girafe \n0 - Exit \n";
        int choice;
        cin >> choice;

        if (choice == 0) {
            break;
        }

        Animal* selectedAnimal = nullptr;

        switch (choice) {
            case 1:
                selectedAnimal = &lion;
                break;
            case 2:
                selectedAnimal = &zebra;
                selectedAnimal->orientation=1;
                break;
            case 3:
                selectedAnimal = &behemoth;
                break;
            case 4:
                selectedAnimal = &girafe;
                selectedAnimal->orientation=1;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
                continue;
        }

        cout << "You chose to interact with " <<selectedAnimal ->name << endl;
        selectedAnimal->displayStatus();
        selectedAnimal->makeSound();

        cout << "What would you like to do? (0 - Feed Grass, 1 - Feed Meat, 2 - Pet): ";
        int action;
        cin >> action;

        if (action == 1) {
            selectedAnimal->feedMeat();
            if(selectedAnimal->orientation==0){
                selectedAnimal->Eat();
            }else{
                selectedAnimal->DontEat();
            }
        } else if (action == 2) {
            selectedAnimal->pet();
        } else if (action == 0){
            selectedAnimal->feedGrass();
            if(selectedAnimal->orientation==1){
                selectedAnimal->Eat();
            }else{
                selectedAnimal->DontEat();
            }
        } else {
            cout << "Invalid action. Try again." << endl;
        }

        selectedAnimal->displayStatus();
    }

    return 0;
}
