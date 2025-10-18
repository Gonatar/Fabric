#ifndef KEEPER_H
#define KEEPER_H

#include "FabricItem.h"
#include "Furniture.h"
#include "Worker.h"
#include "Vehicle.h"

class Keeper{
    private:
    FabricItem** items;
    int capacity;
    int count;

    void domExpansion();

    public:
    Keeper();
    Keeper(const Keeper& other);
    ~Keeper();

    void addItem(FabricItem* item);
    void removeItem(int index);
    void display() const;
    void find(const string& name) const;
    int getCount() const;

    void Save(const string& filename) const;
    void Load(const string& filename) const;

    FabricItem* operator[](int index);
};

#endif // KEEPER_H