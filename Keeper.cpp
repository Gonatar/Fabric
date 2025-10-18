#include "Keeper.h"

Keeper::Keeper() : capacity(10), count(0){
    items = new FabricItem* [capacity];
    cout << "Keeper default constructor called" << endl;
}

Keeper::Keeper(const Keeper& other) 
    : capacity(other.capacity), count(other.count) {
    items = new FabricItem*[capacity];
    for (int i = 0; i < count; i++) 
    {
        items[i] = other.items[i]->clone();
    }
    cout << "LibraryManager copy constructor called" << endl;
}

Keeper:: ~Keeper(){
    for (int i = 0; i < count; i++) {
        delete items[i];
    }
    delete[] items;
    cout << "Keeper destructor called " << endl;
}

void Keeper::domExpansion() {
    capacity *= 2;
    FabricItem** newItems = new FabricItem*[capacity];
    
    for (int i = 0; i < count; i++) {
        newItems[i] = items[i];
    }
    
    delete[] items;
    items = newItems;
    cout << "Storage expanded to " << capacity << " items" << endl;
}

void Keeper::addItem(FabricItem* item) {
    if (count >= capacity) {
        domExpansion();
    }
    
    items[count] = item;
    count++;
    cout << "Item added to library. Total items: " << count << endl;
}

void Keeper::removeItem(int index) {
    if (index < 0 || index >= count) {
        throw out_of_range("Invalid index: " + to_string(index));
    }
    
    delete items[index];

    for (int i = index; i < count - 1; i++) {
        items[i] = items[i + 1];
    }
    
    count--;
    cout << "Item at index " << index << " removed. Total items: " << count << endl;
}

void Keeper::display() const {
    if (count == 0) {
        cout << "Library is empty." << endl;
        return;
    }
    
    cout << "\n=== LIBRARY CONTENTS (" << count << " items) ===" << endl;
    for (int i = 0; i < count; i++) {
        cout << "\nItem #" << (i + 1) << ":" << endl;
        items[i]->displayInfo();
    }
}

void Keeper::find(const string& name) const {
    bool found = false;
    cout << "\nSearch results for '" << name << "':" << endl;
    
    for (int i = 0; i < count; i++) {
        if (items[i]->getName().find(name) != string::npos) {
            items[i]->displayInfo();
            found = true;
        }
    }
    
    if (!found) {
        cout << "No items found with title containing '" << name << "'" << endl;
    }
}

int Keeper::getCount() const {
    return count;
}

FabricItem* Keeper::operator[](int index) {
    if (index < 0 || index >= count) {
        throw out_of_range("Index out of range");
    }
    return items[index];
}