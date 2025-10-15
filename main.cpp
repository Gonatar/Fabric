#include "Furniture.h"
#include "Worker.h"
#include "Vehicle.h"

using namespace std;

int main() {
    cout << "=== Testing Fabric Classes ===" << endl;
    
    cout << "\n1. Creating Furniture:" << endl;
    Furniture chair("Office Chair", "Chair", 100, 50, 50, "Black", "Leather", 5000);
    chair.displayInfo();
    
    cout << "\n2. Creating Worker:" << endl;
    Worker manager("John Doe", "John A. Doe", "Manager", 50000, "Moscow", "+79991234567");
    manager.displayInfo();
    
    cout << "\n3. Creating Vehicle:" << endl;
    Vehicle car("Company Car", "Toyota", "Camry", "A123BC");
    car.displayInfo();
    
    cout << "\n=== Testing polymorphism ===" << endl;
    FabricItem* items[] = { &chair, &manager, &car };
    
    for (int i = 0; i < 3; i++) {
        cout << "\nItem " << i+1 << ":" << endl;
        items[i]->displayInfo();
        items[i]->use();
    }
    
    cout << "\n=== Destructors will be called automatically ===" << endl;
    return 0;
}