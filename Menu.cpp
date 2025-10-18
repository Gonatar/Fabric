#include "Menu.h"

void Menu::run() {
    int choice;
    
    do {
        system("cls");
        displayMainMenu();
        choice = getInput(0, 6);
        
        switch (choice) {
            case 1: FurnitureOper(); break;
            case 2: WorkerOper(); break;
            case 3: VehicleOper(); break;
            case 4: SearchOper(); break;
            case 5: FileOper(); break;
            case 6: library.display(); break;
            case 0: cout << "Sayonara!" << endl; break;
        }
        
        if (choice != 0) {
            enter();
        }
    } while (choice != 0);
}

void Menu::displayMainMenu() {
    cout << "=== FABRIC MENU ===" << endl;
    cout << "Items in library: " << library.getCount() << endl;
    cout << "1. Manage Furniture" << endl;
    cout << "2. Manage Workers" << endl;
    cout << "3. Manage Vehicles" << endl;
    cout << "4. Search Library" << endl;
    cout << "5. File Operations" << endl;
    cout << "6. View All Items" << endl;
    cout << "0. Exit" << endl;
    cout << "Choose an option: ";
}

void Menu::FurnitureOper() {
    system("cls");
    cout << "=== FURNITURE MANAGEMENT ===" << endl;
    cout << "1. Add New Furniture" << endl;
    cout << "2. Remove Furniture" << endl;
    cout << "3. View All Furnitures" << endl;
    cout << "0. Back to Main Menu" << endl;
    
    int choice = getInput(0, 3);
    
    switch (choice) {
        case 1: {
            string name, type, color, material;
            int height, width, depth, cost;
            
            cout << "Enter Furniture name: ";
            getline(cin, name);
            cout << "Enter type: ";
            getline(cin, type);
            cout << "Enter dimensions: ";
            cin >> height;
            cin.ignore();
            cin >> width;
            cin.ignore();
            cin >> depth;
            cin.ignore();
            cout << "Enter color: ";
            getline(cin, color);
            cout << "Enter cost: ";
            cin >> cost;
            cin.ignore();
            cout << "Enter material: ";
            getline(cin, material);
            
            Furniture* newFurniture = new Furniture(name, type, height, width, depth, color, material, cost);
            library.addItem(newFurniture);
            break;
        }
        case 2: {
            if (library.getCount() == 0) {
                cout << "Library is empty!" << endl;
                break;
            }
            
            library.display();
            cout << "Enter item number to remove: ";
            int index = getInput(1, library.getCount()) - 1;
            
            try {
                library.removeItem(index);
                cout << "Item removed successfully!" << endl;
            } catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
            }
            break;
        }
        case 3:
            library.display();
            break;
    }
}

void Menu::WorkerOper() {
    system("cls");
    cout << "=== WORKER MANAGEMENT ===" << endl;
    cout << "1. Add New Worker" << endl;
    cout << "2. Remove Worker" << endl;
    cout << "3. View All Workers" << endl;
    cout << "0. Back to Main Menu" << endl;
    
    int choice = getInput(0, 3);
    
    switch (choice) {
        case 1: {
            string name, post, address, phoneNumber;
            int salary;
            
            cout << "Enter Worker name: ";
            getline(cin, name);
            cout << "Enter post: ";
            getline(cin, post);
            cout << "Enter salary: ";
            cin >> salary;
            cin.ignore();
            cout << "Enter address: ";
            getline(cin, address);
            cout << "Enter phone number: ";
            getline(cin, phoneNumber);
            
            Worker* newWorker = new Worker(name,  post, salary, address, phoneNumber);
            library.addItem(newWorker);
            break;
        }
        case 2: {
            if (library.getCount() == 0) {
                cout << "Library is empty!" << endl;
                break;
            }
            
            library.display();
            cout << "Enter item number to remove: ";
            int index = getInput(1, library.getCount()) - 1;
            
            try {
                library.removeItem(index);
                cout << "Item removed successfully!" << endl;
            } catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
            }
            break;
        }
        case 3:
            library.display();
            break;
    }
}

void Menu::VehicleOper() {
    system("cls");
    cout << "=== VEHICLE MANAGEMENT ===" << endl;
    cout << "1. Add New Vehicle" << endl;
    cout << "2. Remove Vehicle" << endl;
    cout << "3. View All Vehicles" << endl;
    cout << "0. Back to Main Menu" << endl;
    
    int choice = getInput(0, 3);
    
    switch (choice) {
        case 1: {
            string name, brand, model, stateNumber;
            
            cout << "Enter Vehicle name: ";
            getline(cin, name);
            cout << "Enter brand: ";
            getline(cin, brand);
            cout << "Enter model: ";
            getline(cin, model);
            cout << "Enter state number: ";
            getline(cin, stateNumber);
            
            Vehicle* newVehicle = new Vehicle(name, brand, model, stateNumber);
            library.addItem(newVehicle);
            break;
        }
        case 2: {
            if (library.getCount() == 0) {
                cout << "Library is empty!" << endl;
                break;
            }
            
            library.display();
            cout << "Enter item number to remove: ";
            int index = getInput(1, library.getCount()) - 1;
            
            try {
                library.removeItem(index);
                cout << "Item removed successfully!" << endl;
            } catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
            }
            break;
        }
        case 3:
            break;
    }
}

void Menu::SearchOper() {
}

void Menu::FileOper() {

}

void Menu::enter() {
    cout << "\nPress Enter to continue...";
    cin.get();
}

int Menu::getInput(int min, int max) {
    int input;
    while (true) {
        cin >> input;
        if (cin.fail() || input < min || input > max) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number between " 
                      << min << " and " << max << ": ";
        } else {
            cin.ignore();
            break;
        }
    }
    return input;
}