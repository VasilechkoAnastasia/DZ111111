#include <iostream>
#include <string>
using namespace std;

class Transport {
protected:
    string name;
    double weight; 
    double fuel; 

public:
    Transport(string name, double weight, double fuel)
        : name(name), weight(weight), fuel(fuel) {}

    virtual ~Transport() {}

    virtual double calculCost(double distance, double fuelPrice) = 0;

    virtual void Print() {
        cout << "Name: " << name << "\n"
            << "Weight: " << weight << " kg\n"
            << "Fuel consumption: " << fuel << " liters/100km\n";
    }
};

class Car : public Transport {
public:
    Car(string name, double weight, double fuel)
        : Transport(name, weight, fuel) {}

    double calculCost(double distance, double fuelPrice) override {
        return (distance / 100.0) * fuel * fuelPrice;
    }

    void Print() override {
        cout << "Car:\n";
        Transport::Print();
    }
};

class Airplane : public Transport {
public:
    Airplane(string name, double weight, double fuel)
        : Transport(name, weight, fuel) {}

    double calculCost(double distance, double fuelPrice) override {
        return (distance / 100.0) * fuel * fuelPrice * 2.0;
    }

    void Print() override {
        cout << "Airplane:\n";
        Transport::Print();
    }
};

class Ship : public Transport {
public:
    Ship(string name, double weight, double fuel)
        : Transport(name, weight, fuel) {}

    double calculCost(double distance, double fuelPrice) override {
        return (distance / 100.0) * fuel * fuelPrice * 0.8;
    }

    void Print() override {
        cout << "Ship:\n";
        Transport::Print();
    }
};

class Truck : public Transport {
public:
    Truck(string name, double weight, double fuel)
        : Transport(name, weight, fuel) {}

    double calculCost(double distance, double fuelPrice) override {
        return (distance / 100.0) * fuel * fuelPrice * 1.5;
    }

    void Print() override {
        cout << "Truck:\n";
        Transport::Print();
    }
};

int main() {
    Transport* transport[] = {
        new Car("Sedan", 1400, 8.5),
        new Airplane("Boeing 747", 40000, 250),
        new Ship("Cargo Ship", 100000, 50),
        new Truck("Volvo Truck", 8000, 30)
    };

    double distance = 1000; 
    double fuelPrice = 1.5; 

    for (int i = 0; i < 4; i++) {
        transport[i]->Print();
        cout << "Cost for " << distance << " km: "
             << transport[i]->calculCost(distance, fuelPrice) << " USD\n\n";
        delete transport[i]; 
    }
}