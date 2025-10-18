#ifndef VEHICLE_H
#define VEHICLE_H

#include "FabricItem.h"

class Vehicle: public FabricItem{
    private:
    string brand;
    string model;
    string stateNumber;

    public:
    Vehicle();
    Vehicle(const string& name, const string& brand, const string& model, const string& stateNumber);
    Vehicle(const Vehicle& other);
    
    virtual ~Vehicle();
    
    virtual void displayInfo() const override;
    virtual void use() const override;
    virtual FabricItem* clone() const override;
    
    string getBrand() const;
    string getModel() const;
    string getStateNumber() const;

    void setBrand(const string& brand);
    void setModel(const string& model);
    void setStateNumber(const string& stateNumber);
};

#endif // VEHICLE_H