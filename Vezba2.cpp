//
// Created by Dragan on 17/08/2024.
//
#include <iostream>
#include <cstring>
using namespace std;

enum Size{mala, golema, familijarna};
char SizeText[3][8]={"small","large","family" };

class Pizza {
protected:
    char name[20];
    char ingredient[100];
    float basePrice;
    void copy_pizza(const Pizza& other) {
        strcpy(name, other.name);
        strcpy(ingredient, other.ingredient);
        basePrice = other.basePrice;
    }
public:
    Pizza() {
        strcpy(name, "pizza");
        strcpy(ingredient, "ingredients");
        basePrice = 0;
    }
    Pizza(char *name, char *ingredient, float basePrice) {
        strcpy(this->name, name);
        strcpy(this->ingredient, ingredient);
        this->basePrice = basePrice;
    }
    Pizza(const Pizza& other) {
        copy_pizza(other);
    }
    Pizza& operator=(const Pizza& other) {
        if (this != &other) {
            return *this;
        }
        copy_pizza(other);
        return *this;
    }
    friend ostream& operator<<(ostream& os, const Pizza& p);
    bool operator<(const Pizza& other) const {
        return this->basePrice < other.basePrice;
    }
    virtual float price() {
        return basePrice;
    }
    ~Pizza() {}
};
class FlatPizza: public Pizza {
protected:
    Size size;
    public:
    FlatPizza():Pizza() {
        this->size = mala;
    }
    FlatPizza(char *name, char *ingredient, float basePrice,Size size):Pizza(name,ingredient,basePrice) {
        this->size = size;
    }
    FlatPizza(const FlatPizza& other):Pizza(other) {
        this->size = other.size;
    }
    FlatPizza& operator=(const FlatPizza& other) {
        if (this != &other) {
            return *this;
        }
        Pizza::operator=(other);
        this->size = other.size;
        return *this;
    }
    float price() {
        switch (size) {
            case mala:
                return basePrice*1.1;
            case golema:
                return basePrice*1.2;
            case familijarna:
                return basePrice*1.3;
        }
        return basePrice;
    }
    char *getSize() {
        return SizeText[size];
    }
    ~FlatPizza(){}
};

int main() {
    cout << "Hello World!" << endl;

    return 0;
}