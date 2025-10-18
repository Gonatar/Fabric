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
    
    void enter();
    int getInput(int min, int max);

public:
    void run();
};

#endif