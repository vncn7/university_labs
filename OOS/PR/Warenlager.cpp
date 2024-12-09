#include"Warenlager.h"
#include<iostream>

Warenlager::Warenlager(int kap) : kap(kap) {}
// Methoden
Warenlager& Warenlager::lagere(Ware *ware)
{
if (lager.size() < kap)
{
lager.push_back(ware);
}
else
{
cout << “Lager voll” << endl;
}
return *this;
}
void Warenlager::listeBestand() const
{
cout << "Lager mit " << kap << " Plaetzen:" << endl;
for (int i = 0; i < lager.size(); i++)
cout << lager[i]->toString() << endl;
}
Ware *Warenlager::operator[](int index) const
{
return lager[index];
}
int Warenlager::belegteLagerplaetze()
{
return lager.size();
};