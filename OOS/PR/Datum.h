#pragma once
#include<string>
using namespace std;

class Datum
{
// Instanzvariablen
int tag, monat, jahr;
// Konstruktor
public:
Datum(int tag, int monat, int jahr);
// Methoden
string toString();
bool operator<(Datum);
static Datum heute();
};