#pragma once
#include <string>
using namespace std;

class Ware {
// Instanzvariablen
const string name;
// Konstruktor
public:
Ware(string);
// Methoden
virtual string toString() const;
bool operator==(const Ware&) const;
};