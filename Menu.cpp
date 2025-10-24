#include "Menu.h"

void Menu::run() {
    int choice;
    
    do {
        system("cls");
        displayMainMenu();
        choice = getInput(0, 8);
        
        switch (choice) {
            case 1: FurnitureOper(); break;
            case 2: WorkerOper(); break;
            case 3: VehicleOper(); break;
            case 4: SearchOper(); break;
            case 5: FileOper(); break;
            case 6: library.displayAll(); break;
            case 7: EditOper(); break;
            case 8: DeleteOper(); break;
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
    cout << "7. Edit Items" << endl;
    cout << "8. Delete Items" << endl;
    cout << "0. Exit" << endl;
    cout << "Choose an option: ";
}

void Menu::FurnitureOper() {
    system("cls");
    cout << "=== FURNITURE MANAGEMENT ===" << endl;
    cout << "1. Add New Furniture" << endl;
    cout << "2. Edit Furniture" << endl;
    cout << "3. Remove Furniture" << endl;
    cout << "4. View All Furnitures" << endl;
    cout << "0. Back to Main Menu" << endl;
    
    int choice = getInput(0, 4);
    
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
            try {
                library.addItem(newFurniture);
                cout << "Furniture added successfully!" << endl;
            } catch (const KeeperException& e) {
                cout << "Keeper error: " << e.what() << endl;
                delete newFurniture;
            } catch (const MemoryException& e) {
                cout << "Memory error: " << e.what() << endl;
            }
            break;
        }
        case 2: {
            int furnitureCount = library.getCountByType("Furniture");
            if (furnitureCount == 0) {
                cout << "No furniture items found!" << endl;
                break;
            }
            
            library.displayByType("Furniture");
            cout << "Enter furniture number to edit (1-" << furnitureCount << "): ";
            int index = getInput(1, furnitureCount);
            
            try {
                int currentIndex = 0;
                for (int i = 0; i < library.getCount(); i++) {
                    if (string(typeid(*library[i]).name()).substr(1) == "Furniture") {
                        currentIndex++;
                        if (currentIndex == index) {
                            editFurniture(static_cast<Furniture*>(library[i]));
                            break;
                        }
                    }
                }
                cout << "Furniture edited successfully!" << endl;
            } catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
            }
            break;
        }

        case 3: {
            int furnitureCount = library.getCountByType("Furniture");
            if (furnitureCount == 0) {
                cout << "No furniture items found!" << endl;
                break;
            }
            
            library.displayByType("Furniture");
            cout << "Enter furniture number to remove (1-" << furnitureCount << "): ";
            int index = getInput(1, furnitureCount);
            
            try {
                library.removeItemByType(index, "Furniture");
                cout << "Item removed successfully!" << endl;
            } catch (const ItemNotFoundException& e) {
                cout << "Error: " << e.what() << endl;
            } catch (const InvalidInputException& e) {
                cout << "Input error: " << e.what() << endl;
            } catch (const exception& e) {
                cout << "Unexpected error: " << e.what() << endl;
            }
            break;
        }
        case 4:
            library.displayByType("Furniture");
            break;
    }
}

void Menu::WorkerOper() {
    system("cls");
    cout << "=== WORKER MANAGEMENT ===" << endl;
    cout << "1. Add New Worker" << endl;
    cout << "2. Edit Worker" << endl;
    cout << "3. Remove Worker" << endl;
    cout << "4. View All Workers" << endl;
    cout << "0. Back to Main Menu" << endl;
    
    int choice = getInput(0, 4);
    
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
            try {
                library.addItem(newWorker);
                cout << "Worker added successfully!" << endl;
            } catch (const KeeperException& e) {
                cout << "Keeper error: " << e.what() << endl;
                delete newWorker;
            } catch (const MemoryException& e) {
                cout << "Memory error: " << e.what() << endl;
            }
            break;
        }
         case 2: {
            int workerCount = library.getCountByType("Worker");
            if (workerCount == 0) {
                cout << "No worker items found!" << endl;
                break;
            }
            
            library.displayByType("Worker");
            cout << "Enter worker number to edit (1-" << workerCount << "): ";
            int index = getInput(1, workerCount);
            
            try {
                int currentIndex = 0;
                for (int i = 0; i < library.getCount(); i++) {
                    if (string(typeid(*library[i]).name()).substr(1) == "Worker") {
                        currentIndex++;
                        if (currentIndex == index) {
                            editWorker(static_cast<Worker*>(library[i]));
                            break;
                        }
                    }
                }
                cout << "Worker edited successfully!" << endl;
            } catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
            }
            break;
        }
        case 3: {
            int WorkerCount = library.getCountByType("Worker");
            if (WorkerCount == 0) {
                cout << "No worker items found!" << endl;
                break;
            }
            
            library.displayByType("Worker");
            cout << "Enter Worker number to remove (1-" << WorkerCount << "): ";
            int index = getInput(1, WorkerCount);
            
            try {
                library.removeItemByType(index, "Worker");
                cout << "Item removed successfully!" << endl;
            } catch (const ItemNotFoundException& e) {
                cout << "Error: " << e.what() << endl;
            } catch (const InvalidInputException& e) {
                cout << "Input error: " << e.what() << endl;
            } catch (const exception& e) {
                cout << "Unexpected error: " << e.what() << endl;
            }
            break;
        }
        case 4:
            library.displayByType("Worker");
            break;
    }
}

void Menu::VehicleOper() {
    system("cls");
    cout << "=== VEHICLE MANAGEMENT ===" << endl;
    cout << "1. Add New Vehicle" << endl;
    cout << "2. Edit Vehicle" << endl;
    cout << "3. Remove Vehicle" << endl;
    cout << "4. View All Vehicles" << endl;
    cout << "0. Back to Main Menu" << endl;
    
    int choice = getInput(0, 4);
    
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
            try {
                library.addItem(newVehicle);
                cout << "Vehicle added successfully!" << endl;
            } catch (const KeeperException& e) {
                cout << "Keeper error: " << e.what() << endl;
                delete newVehicle;
            } catch (const MemoryException& e) {
                cout << "Memory error: " << e.what() << endl;
            }
            break;
        }
        case 2: {
            int vehicleCount = library.getCountByType("Vehicle");
            if (vehicleCount == 0) {
                cout << "No vehicle items found!" << endl;
                break;
            }
            
            library.displayByType("Vehicle");
            cout << "Enter vehicle number to edit (1-" << vehicleCount << "): ";
            int index = getInput(1, vehicleCount);
            
            try {
                int currentIndex = 0;
                for (int i = 0; i < library.getCount(); i++) {
                    if (string(typeid(*library[i]).name()).substr(1) == "Vehicle") {
                        currentIndex++;
                        if (currentIndex == index) {
                            editVehicle(static_cast<Vehicle*>(library[i]));
                            break;
                        }
                    }
                }
                cout << "Vehicle edited successfully!" << endl;
            } catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
            }
            break;
        }
        case 3: {
            int VehicleCount = library.getCountByType("Vehicle");
            if (VehicleCount == 0) {
                cout << "No vehicle items found!" << endl;
                break;
            }
            
            library.displayByType("Vehicle");
            cout << "Enter Vehicle number to remove (1-" << VehicleCount << "): ";
            int index = getInput(1, VehicleCount);
            
            try {
                library.removeItemByType(index, "Vehicle");
                cout << "Item removed successfully!" << endl;
            } catch (const ItemNotFoundException& e) {
                cout << "Error: " << e.what() << endl;
            } catch (const InvalidInputException& e) {
                cout << "Input error: " << e.what() << endl;
            } catch (const exception& e) {
                cout << "Unexpected error: " << e.what() << endl;
            }
            break;
        }
        case 4:
            library.displayByType("Vehicle");
            break;
    }
}

void Menu::SearchOper() {
    system("cls");
    cout << "=== SEARCH IN LIBRARY ===" << endl;
    cout << "Enter search term: ";
    string term;
    getline(cin, term);
    
    if (term.empty()) {
        cout << "Search term cannot be empty!" << endl;
        return;
    }
    
    library.find(term);
}

void Menu::FileOper() {
    system("cls");
    cout << "=== FILE OPERATIONS ===" << endl;
    cout << "1. Save to file" << endl;
    cout << "2. Load from file" << endl;
    cout << "0. Back to Main Menu" << endl;
    
    int choice = getInput(0, 2);
    
    switch (choice) {
        case 1: {
            string filename = "SData.txt";
            
            try {
                library.Save(filename);
                cout << "Data saved successfully!" << endl;
            } catch (const FileOperationException& e) {
                cout << "File error: " << e.what() << endl;
            } catch (const exception& e) {
                cout << "Unexpected error: " << e.what() << endl;
            }
            break;
        }
        case 2: {
            string filename = "SData.txt";
            
            try {
                library.Load(filename);
                cout << "Data loaded successfully!" << endl;
            } catch (const FileOperationException& e) {
                cout << "File error: " << e.what() << endl;
            } catch (const MemoryException& e) {
                cout << "Memory error: " << e.what() << endl;
            } catch (const exception& e) {
                cout << "Unexpected error: " << e.what() << endl;
            }
            break;
        }
    }
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
            throw InvalidInputException("Expected number between " + to_string(min) + " and " + to_string(max) + ", but got: " + to_string(input));
        } else {
            cin.ignore();
            break;
        }
    }
    return input;
}

void Menu::DeleteOper(){
    int Count = library.getCount();
    if (Count == 0) {
        cout << "No item found!" << endl;
        return;
    }
            
    library.displayAll();
    cout << "Enter item number to remove (1-" << Count << "): ";
    int index = getInput(1, Count);
            
    try {
        library.removeItem(index-1);
        cout << "Item removed successfully!" << endl;
    } catch (const ItemNotFoundException& e) {
        cout << "Error: " << e.what() << endl;
    } catch (const InvalidInputException& e) {
        cout << "Input error: " << e.what() << endl;
    } catch (const exception& e) {
        cout << "Unexpected error: " << e.what() << endl;
    }
}

void Menu::EditOper() {
    int Count = library.getCount();
    if (Count == 0) {
        cout << "No items found!" << endl;
        return;
    }
    
    library.displayAll();
    cout << "Enter item number to edit (1-" << Count << "): ";
    int index = getInput(1, Count);
    
    FabricItem* item = library[index - 1];
    string type = string(typeid(*item).name()).substr(1);
    
    cout << "\n=== EDITING " << type << " ===" << endl;
    
    try {
        if (type == "Furniture") {
            editFurniture(static_cast<Furniture*>(item));
        } else if (type == "Worker") {
            editWorker(static_cast<Worker*>(item));
        } else if (type == "Vehicle") {
            editVehicle(static_cast<Vehicle*>(item));
        } else {
            throw runtime_error("Unknown type: " + type);
        }
        cout << type << " edited successfully!" << endl;
    } catch (const exception& e) {
        cout << "Error editing " << type << ": " << e.what() << endl;
    }
}

void Menu::editFurniture(Furniture* furniture) {
    string name, type, color, material;
    int height, width, depth, cost;
    
    cout << "=== EDITING FURNITURE ===" << endl;
    cout << "Current values:" << endl;
    furniture->displayInfo();
    cout << "-------------------" << endl;

    cout << "Enter new name (current: " << furniture->getName() << "): ";
    getline(cin, name);
    if (!name.empty()) furniture->setName(name);
    
    cout << "Enter new type (current: " << furniture->getType() << "): ";
    getline(cin, type);
    if (!type.empty()) furniture->setType(type);
    
    cout << "Enter new dimensions (current: " << furniture->getHeight() << "x" 
         << furniture->getWidth() << "x" << furniture->getDepth() << "): ";
    cin >> height >> width >> depth;
    cin.ignore();
    furniture->setDimensions(height, width, depth);
    
    cout << "Enter new color (current: " << furniture->getColor() << "): ";
    getline(cin, color);
    if (!color.empty()) furniture->setColor(color);
    
    cout << "Enter new cost (current: " << furniture->getCost() << "): ";
    cin >> cost;
    cin.ignore();
    furniture->setCost(cost);
    
    cout << "Enter new material (current: " << furniture->getMaterial() << "): ";
    getline(cin, material);
    if (!material.empty()) furniture->setMaterial(material);
}

void Menu::editWorker(Worker* worker) {
    string name, post, address, phoneNumber;
    int salary;
    
    cout << "=== EDITING WORKER ===" << endl;
    cout << "Current values:" << endl;
    worker->displayInfo();
    cout << "-------------------" << endl;

    cout << "Enter new name (current: " << worker->getName() << "): ";
    getline(cin, name);
    if (!name.empty()) worker->setName(name);
    
    cout << "Enter new post (current: " << worker->getPost() << "): ";
    getline(cin, post);
    if (!post.empty()) worker->setPost(post);
    
    cout << "Enter new salary (current: " << worker->getSalary() << "): ";
    cin >> salary;
    cin.ignore();
    worker->setSalary(salary);
    
    cout << "Enter new address (current: " << worker->getAddress() << "): ";
    getline(cin, address);
    if (!address.empty()) worker->setAddress(address);
    
    cout << "Enter new phone number (current: " << worker->getPhoneNumber() << "): ";
    getline(cin, phoneNumber);
    if (!phoneNumber.empty()) worker->setPhoneNumber(phoneNumber);
}

void Menu::editVehicle(Vehicle* vehicle) {
    string name, brand, model, stateNumber;
    
    cout << "=== EDITING VEHICLE ===" << endl;
    cout << "Current values:" << endl;
    vehicle->displayInfo();
    cout << "-------------------" << endl;

    cout << "Enter new name (current: " << vehicle->getName() << "): ";
    getline(cin, name);
    if (!name.empty()) vehicle->setName(name);
    
    cout << "Enter new brand (current: " << vehicle->getBrand() << "): ";
    getline(cin, brand);
    if (!brand.empty()) vehicle->setBrand(brand);
    
    cout << "Enter new model (current: " << vehicle->getModel() << "): ";
    getline(cin, model);
    if (!model.empty()) vehicle->setModel(model);

    cout << "Enter new state number (current: " << vehicle->getStateNumber() << "): ";
    getline(cin, stateNumber);
    if (!stateNumber.empty()) vehicle->setStateNumber(stateNumber);
}