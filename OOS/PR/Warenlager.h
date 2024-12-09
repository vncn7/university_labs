#include "Ware.h"
#include<vector>
using namespace std;

class Warenlager {
// Instanzvariablen
int kapazitaet;
vector<Ware*> lager;
// Konstruktor
public:
Warenlager(int);
// Methoden
Warenlager& lagere(Ware*);
Warenlager& entferne(Ware*); // muss NICHT implementiert werden
void listeBestand() const;
Ware* operator[](int) const;
int belegteLagerplaetze();
};