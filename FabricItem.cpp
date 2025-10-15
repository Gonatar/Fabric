#include "FabricItem.h"

FabricItem::FabricItem() : name("Unknown") {
    cout << "FabricItem default constructor called" << endl;
}

FabricItem::FabricItem(const string& name) : name(name) {
    cout << "FabricItem parameterized constructor called for: " << name << endl;
}

FabricItem::FabricItem(const FabricItem& other) : name(other.name) {
    cout << "FabricItem copy constructor called from: " << other.name << endl;
}

FabricItem:: ~FabricItem(){
    cout << "FabricItem destructor called " << name << endl;
}

string FabricItem::getName() const {
    return name;
}

void FabricItem::setName(const string& name) {
    this->name = name;
}
