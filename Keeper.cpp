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
    cout << "Keeper copy constructor called" << endl;
}

Keeper:: ~Keeper(){
    for (int i = 0; i < count; i++) {
        delete items[i];
    }
    delete[] items;
    cout << "Keeper destructor called " << endl;
}

void Keeper::domExpansion() {
    if (capacity > 999999) {
        throw MemoryException("Capacity too large: " + to_string(capacity));
    }
    
    capacity *= 2;
    FabricItem** newItems = nullptr;
    
    try {
        newItems = new FabricItem*[capacity];
    } catch (const bad_alloc& e) {
        throw MemoryException("Failed to allocate memory for expansion: " + string(e.what()));
    }
    
    for (int i = 0; i < count; i++) {
        newItems[i] = items[i];
    }
    
    delete[] items;
    items = newItems;
    cout << "Storage expanded to " << capacity << " items" << endl;
}

void Keeper::addItem(FabricItem* item) {
    if (item == nullptr) {
        throw KeeperException("Attempt to add null item");
    }
    
    if (count >= capacity) {
        try {
            domExpansion();
        } catch (const MemoryException& e) {
            throw KeeperException("Failed to add item - memory expansion failed: " + string(e.what()));
        }
    }
    
    items[count] = item;
    count++;
    cout << "Item added to library. Total items: " << count << endl;
}

void Keeper::removeItem(int index) {
    if (index < 0 || index >= count) {
        throw ItemNotFoundException("Invalid index: " + to_string(index) + ". Total items: " + to_string(count));
    }
    
    delete items[index];

    for (int i = index; i < count - 1; i++) {
        items[i] = items[i + 1];
    }
    
    count--;
    cout << "Item at index " << index << " removed. Total items: " << count << endl;
}

void Keeper::removeItemByType(int Tindex, const string& type) {
    if (Tindex < 0 || Tindex > count) {
        throw InvalidInputException("Index cannot be negative: " + to_string(Tindex));
    }
    
    int currentIndex = 0;
    for (int i = 0; i < count; i++) {
        if (string(typeid(*items[i]).name() + 1) == type) {
            currentIndex++;
            if (currentIndex == Tindex) {
                removeItem(i);
                return;
            }
        }
    }
    throw ItemNotFoundException("Index " + to_string(Tindex) + " not found for type: " + type);
}

void Keeper::displayAll() const {
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

void Keeper::displayByType(const string& type) const {
    if (count == 0) {
        throw ItemNotFoundException("Library is empty. No items to display.");
    }
    
    cout << "\n=== " << type << endl;
    bool found = false;
    
    for (int i = 0; i < count; i++) {
        if (string(typeid(*items[i]).name()).substr(1) == type) {
            items[i]->displayInfo();
            found = true;
         }
    }
    
    if (!found) {
        cout << "No " << type << " items found." << endl;
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

int Keeper::getCountByType(const string& type) const {
    int typeCount = 0;
    for (int i = 0; i < count; i++) {
        if (string(typeid(*items[i]).name() + 1) == type) {
            typeCount++;
        }
    }
    return typeCount;
}

void Keeper::Save(const string& filename) const {
    ofstream fout(filename);
    if (!fout) throw FileOperationException("Cannot open file for writing: " + filename);;
    
    for (int i = 0; i < count; i++) {
        string type = string(typeid(*items[i]).name() + 1);
        fout << "[" << type << "]" << endl;
        fout << items[i]->getName() << endl;
        
        if (type == "Furniture") {
            Furniture* f = dynamic_cast<Furniture*>(items[i]);
            fout << f->getType() << endl;
            fout << f->getHeight() << "," << f->getWidth() << "," << f->getDepth() << endl;
            fout << f->getColor() << endl;
            fout << f->getMaterial() << endl;
            fout << f->getCost() << endl;
        }
        else if (type == "Worker") {
            Worker* w = dynamic_cast<Worker*>(items[i]);
            fout << w->getPost() << endl;
            fout << w->getSalary() << endl;
            fout << w->getAddress() << endl;
            fout << w->getPhoneNumber() << endl;
        }
        else if (type == "Vehicle") {
            Vehicle* v = dynamic_cast<Vehicle*>(items[i]);
            fout << v->getBrand() << endl;
            fout << v->getModel() << endl;
            fout << v->getStateNumber() << endl;
        }
        fout << "---" << endl;
    }
    
    fout.close();
    cout << "Saved " << count << " items to " << filename << endl;
}

void Keeper::Load(const string& filename)  {
    ifstream fin(filename);
    if (!fin) throw FileOperationException("Cannot open file for reading: " + filename);
    
    for (int i = 0; i < count; i++) {
        delete items[i];
    }
    delete[] items;

    capacity = 10;
    count = 0;
    items = new FabricItem*[capacity];
    
    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;
        
        if (line[0] == '[') {
            string type = line.substr(1, line.size() - 2);
            
            getline(fin, line);
            string name = line;
            
            if (type == "Furniture") {
                string furnitureType, color, material;
                int height, width, depth, cost;
                
                getline(fin, furnitureType);
                
                getline(fin, line);
                sscanf(line.c_str(), "%d,%d,%d", &height, &width, &depth);
                
                getline(fin, color);
                getline(fin, material);
                getline(fin, line);
                cost = stoi(line);
                
                addItem(new Furniture(name, furnitureType, height, width, depth, color, material, cost));
            }
            else if (type == "Worker") {
                string post, address, phoneNumber;
                int salary;
                
                getline(fin, post);
                
                getline(fin, line);
                salary = stoi(line);
                
                getline(fin, address);
                getline(fin, phoneNumber);
                
                addItem(new Worker(name, post, salary, address, phoneNumber));
            }
            else if (type == "Vehicle") {
                string brand, model, stateNumber;
                
                getline(fin, brand);
                getline(fin, model);
                getline(fin, stateNumber);
                
                addItem(new Vehicle(name, brand, model, stateNumber));
            }
            
            getline(fin, line);
        }
    }
    
    fin.close();
    cout << "Loaded " << count << " items from " << filename << endl;
}

FabricItem* Keeper::operator[](int index) {
    if (index < 0 || index >= count) {
        throw ItemNotFoundException("Index " + to_string(index) + " out of range. Valid range: 0-" + to_string(count-1));
    }
    return items[index];
}