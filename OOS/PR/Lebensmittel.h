#include "Ware.h"
#include "Datum.h"
using namespace std;

class Lebensmittel : public Ware {
// Instanzvariablen
Datum mhd;
// Konstruktor
public:
Lebensmittel(string, Datum);
// Methoden
Datum getMHD();
string toString() const override;
};