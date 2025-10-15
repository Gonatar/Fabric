#ifndef FURNITURE_H
#define FURNITURE_H

#include "FabricItem.h"

class Furniture: public FabricItem{
    private:
    string type;
    int height;
    int width;
    int depth;
    string color;
    string material;
    int cost;

    public:
    Furniture();
    Furniture(const string& name, const string& type, int height, int width, int depth, 
              const string& color, const string& material, int cost);
    Furniture(const Furniture& other);
    
    virtual ~Furniture();
    
    virtual void displayInfo() const override;
    virtual void use() const override;
    
    string getType() const;
    int getHeight() const;
    int getWidth() const;
    int getDepth() const;
    string getColor() const;
    string getMaterial() const;
    int getCost() const;

    void setType(const string& type);
    void setDimensions(int height, int width, int depth);
    void setColor(const string& color);
    void setMaterial(const string& material);
    void setCost(int cost);
};

#endif // FURNITURE_H