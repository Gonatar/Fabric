#ifndef MENU_H
#define MENU_H

#include "Keeper.h"

class Menu {
private:
    Keeper library;
    
    void displayMainMenu();
    void FurnitureOper();
    void WorkerOper(); 
    void VehicleOper();
    void SearchOper();
    void FileOper();
    void DeleteOper();
    void EditOper();
    void editFurniture(Furniture* furniture);
    void editWorker(Worker* worker);
    void editVehicle(Vehicle* vehicle);
    
    void enter();
    int getInput(int min, int max);

public:
    void run();
};

#endif