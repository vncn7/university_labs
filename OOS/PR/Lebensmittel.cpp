#include "Lebensmittel.h

Lebensmittel::Lebensmittel(string id, Datum mhd)
: Ware(id), mhd(mhd) {}
// Methoden
Datum Lebensmittel::getMHD() { return mhd; }
string Lebensmittel::toString() const
{
string result = Ware::toString();
result += ", MHD: " + const_cast<Datum&>(mhd).toString();
return result;
}