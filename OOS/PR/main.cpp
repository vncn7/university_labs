#include"Warenlager.h"
#include"Datum.h"
#include"Lebensmittel.h"

void entferneAbgelaufeneWaren(Warenlager &lager);
int main() {
Warenlager regal(100);
regal.lagere(new Ware("Spielzeugauto"));
regal.lagere(new Lebensmittel("Joghurt", Datum(1, 12, 2021)));
regal.lagere(new Ware("Fussball"));
regal.lagere(new Ware("Teller"));
regal.lagere(new Lebensmittel("Milch", Datum(1, 1, 2022)));
regal.lagere(new Lebensmittel("Butter", Datum(31, 5, 2022)));
regal.listeBestand();
entferneAbgelaufeneWaren(regal);
return 0;
}
void entferneAbgelaufeneWaren(Warenlager &lager) {
Ware* ware;
for (int i = 0; i < lager.belegteLagerplaetze(); i++)
{
ware = lager[i];
Lebensmittel *lebensmittel = dynamic_cast<Lebensmittel *>(ware);
if (lebensmittel != nullptr)
{
Datum mhd = lebensmittel->getMHD();
if (mhd < Datum::heute())
{
lager.entferne(lebensmittel);
}
}
}
}