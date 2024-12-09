#include"Datum.h"
#include<sstream>

// Konstruktor
Datum::Datum(int t, int m, int j) : tag(t), monat(m), jahr(j) {}
// Methoden
string Datum::toString() {
stringstream ss;
ss << tag << "." << monat << "." << jahr;
return ss.str();
}
bool Datum::operator<(Datum d) {
if (jahr < d.jahr || (jahr == d.jahr && monat < d.monat) || (jahr ==
d.jahr && monat == d.monat && tag < d.tag))
return true;
return false;
}
Datum Datum::heute() { return Datum(2, 2, 2022); }