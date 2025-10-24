#ifndef FABRICITEM_H
#define FABRICITEM_H

#include <iostream>
#include <string>
#include <typeinfo>
#include <fstream>
using namespace std;

class FabricItem {
    protected:
    string name;

    public:
    FabricItem();
    FabricItem(const string& name);
    FabricItem(const FabricItem& other);

    virtual ~FabricItem();

    virtual void displayInfo() const = 0;

    string getName() const;
    void setName(const string& name);
    virtual FabricItem* clone() const = 0;
};

#endif