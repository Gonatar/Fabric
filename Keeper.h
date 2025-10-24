#ifndef KEEPER_H
#define KEEPER_H

#include "FabricItem.h"
#include "Furniture.h"
#include "Worker.h"
#include "Vehicle.h"
#include "Exceptions.h"

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
    void removeItemByType(int index, const string& type);

    void displayAll() const;
    void displayByType(const string& type) const;

    void find(const string& name) const;

    int getCount() const;
    int getCountByType(const string& type) const;

    void Save(const string& filename) const;
    void Load(const string& filename);

    FabricItem* operator[](int index);
};

#endif // KEEPER_H