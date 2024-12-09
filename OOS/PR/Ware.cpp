#include "Ware.h"

// Konstruktor
Ware::Ware(string name) : name(name){};
// Methoden
string Ware::toString() const { return name; }
bool Ware::operator==(const Ware &ware) const {
return (this->name == ware.name);
}