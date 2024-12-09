//Aufgabe 0

#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    short int count;
    int array[10];
    double sum = 0;
    int i;

    cout << "Anzahl eingeben: " << endl;
    cin >> count;

if (count > 10) //Nur Zahlen bis maximal 10 akzeptiert
{
    count = 10;
}

for (i = 0; i < count; i++) //Eingabe Zahlen
{
    cout << "Zahl eingeben: " << endl;
    cin >> array[i];
}

for (i = 0; i < count; i++) //Ausgabe eingegebener Zahlen + Aufsummieren
{
    cout << "Zahl[" << i << "]: " << array[i] << endl;
    sum += static_cast< double >(array[i]); //Typenumwandlung
}

cout << "Durchschnitt: " << (sum / i ) << endl; //Berechnung und Ausgabe Durchschnitt
return 0;
}
