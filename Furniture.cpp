#include "Furniture.h"

Furniture::Furniture() 
    : FabricItem(), type("Unknown"), height(0), width(0), depth(0), 
      color("Unknown"), material("Unknown"), cost(0) {
    cout << "Furniture default constructor called" << endl;
}

Furniture::Furniture(const string& name, const string& type, int height, int width, int depth,
                     const string& color, const string& material, int cost)
    : FabricItem(name), type(type), height(height), width(width), depth(depth),
      color(color), material(material), cost(cost) {
    cout << "Furniture parameterized constructor called for: " << name << endl;
}

Furniture::Furniture(const Furniture& other)
    : FabricItem(other), type(other.type), height(other.height), width(other.width),
      depth(other.depth), color(other.color), material(other.material), cost(other.cost) {
    cout << "Furniture copy constructor called from: " << other.name << endl;
}

Furniture::~Furniture() {
    cout << "Furniture destructor called for: " << name << endl;
}

void Furniture::displayInfo() const {
    cout << "Furniture Info:" << endl;
    cout << "  Name: " << name << endl;
    cout << "  Type: " << type << endl;
    cout << "  Dimensions: " << height << "x" << width << "x" << depth << " cm" << endl;
    cout << "  Color: " << color << endl;
    cout << "  Material: " << material << endl;
    cout << "  Cost: " << cost << " rub" << endl;
}

FabricItem* Furniture::clone() const {
    return new Furniture(*this);
}

string Furniture::getType() const { return type; }
int Furniture::getHeight() const { return height; }
int Furniture::getWidth() const { return width; }
int Furniture::getDepth() const { return depth; }
string Furniture::getColor() const { return color; }
string Furniture::getMaterial() const { return material; }
int Furniture::getCost() const { return cost; }

void Furniture::setType(const string& type) { this->type = type; }
void Furniture::setDimensions(int h, int w, int d) { 
    height = h; 
    width = w; 
    depth = d; 
}
void Furniture::setColor(const string& color) { this->color = color; }
void Furniture::setMaterial(const string& material) { this->material = material; }
void Furniture::setCost(int cost) { this->cost = cost; }