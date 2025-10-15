#include "Vehicle.h"

Vehicle::Vehicle() 
    : FabricItem(), brand("Unknown"), model("Unknown"), stateNumber("Unknown") {
    cout << "Vehicle default constructor called" << endl;
}

Vehicle::Vehicle(const string& name, const string& brand, const string& model, const string& stateNumber)
    : FabricItem(name), brand(brand), model(model), stateNumber(stateNumber) {
    cout << "Vehicle parameterized constructor called for: " << name << endl;
}


Vehicle::Vehicle(const Vehicle& other)
    : FabricItem(other), brand(other.brand), model(other.model), stateNumber(other.stateNumber) {
    cout << "Vehicle copy constructor called from: " << other.name << endl;
}

Vehicle::~Vehicle() {
    cout << "Vehicle destructor called for: " << name << endl;
}

void Vehicle::displayInfo() const {
    cout << "Vehicle Info:" << endl;
    cout << "  Name: " << name << endl;
    cout << "  Brand: " << brand << endl;
    cout << "  Model: " << model << endl;
    cout << "  State Number: " << stateNumber << endl;
}

void Vehicle::use() const {
    cout << "Using vehicle: " << brand << " " << model << " with license plate: " << stateNumber << endl;
}

string Vehicle::getBrand() const { return brand; };
string Vehicle::getModel() const { return model; };
string Vehicle::getStateNumber() const { return stateNumber; };

void Vehicle::setBrand(const string& brand) { this->brand = brand; };
void Vehicle::setModel(const string& model) { this->model = model; };
void Vehicle::setStateNumber(const string& stateNumber) { this->stateNumber = stateNumber; };