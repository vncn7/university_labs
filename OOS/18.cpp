#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// Klasse für alle Personen, die Medien ausleihen können aus Aufgabe 10
class Person
{
    // Name der Person
    string name;
    // Dauer in Tagen, die die Person ein Medium ausleihen darf
    // wird von den abgelieteten Klassen festgelegt
    int ausleihdauer;

public:
    // Standardkonstruktor
    Person(string name, int dauer = 0) : name(name), ausleihdauer(dauer) {}
    // den Namen zurückliefern
    string getName() const
    {
        return name;
    }
    // die Ausliehdauer zurückliefern
    int getAusleihdauer() const
    {
        return ausleihdauer;
    }
    // die Person auf der Konsole ausgeben
    void print() const
    {
        cout << name;
    }
};

// Klasse Dozent als Spezialisierung von Person aus Aufgabe 10
class Dozent : public Person
{
    // Prüfernummer des Dozenten
    int prfrNr;

public:
    // Standardkonstruktor
    Dozent(string name, int prfrNr) : Person(name, 90), prfrNr(prfrNr) {}
    // Dozenten auf der Konsole ausgeben
    void print() const
    {
        Person::print();
        cout << "prfrNr" << prfrNr << endl;
    }
};

// Klasse Student als Spezialisierung von Person aus Aufgabe 10
class Student : public Person
{
    // Matrikelnummer des Studenten/der Studentin
    int matNr;

public:
    // Standardkonstruktor
    Student(string name, int matNr) : Person(name, 30), matNr(matNr) {}
    // Student auf der Konsole ausgeben
    void print() const
    {
        Person::print();
        cout << "matNr" << matNr;
    }
};

// Klasse Datum aus Aufgabe 9
class Datum
{
    // Elemente eines Datums
    int tag, monat, jahr;

public:
    // Standardkonstruktor
    Datum(int t = 0, int m = 0, int j = 0) : tag(t), monat(m), jahr(j) {}
    // Konvertierkonstruktor für String
    Datum(const string &s)
    {
        char c;
        stringstream ss(s);
        ss >> tag >> c >> monat >> c >> jahr; // Extrahieren des Datums aus einem String
    }
    // Konvertierkonstruktor für C-String
    Datum(const char *c) : Datum(string(c)) {} // Konstruktordelegation mit Konvertierung des C-Strings

    // Operator + addiert eine Anzahl von Tagen zum Datum hinzu
    Datum operator+(int tage)
    {
        int absDate = tag + monat * 30 + jahr * 360;
        absDate += tage;
        int j = absDate / 360;
        absDate = absDate % 360;
        int m = absDate / 30;
        absDate = absDate % 30;
        int t = absDate;

        return Datum(t, m, j);
    }
    // Ausgabeoperator <<, Ausgabe in dem Format tt.mm.jjjj
    friend ostream &operator<<(ostream &os, const Datum &d)
    {
        os << d.tag << "." << d.monat << "." << d.jahr;
        return os;
    }
};

class Medium
{

protected:
    // Titel des Mediums
    const string titel;
    // Verlag, der das Medium herausgibt
    const string verlag;
    // Jahr, in dem das Medium veröffentlicht wurde
    const int jahr;
    // ausgeliehen am
    Datum von;
    // ausgeliehen bis
    Datum bis;
    // ausgeliehen von
    Person *ausleiher;

public:
    // Konstruktor
    Medium(string _titel = "", string _verlag = "", int _jahr = 0) : titel(_titel), verlag(_verlag), jahr(_jahr), ausleiher(new Person("-")) {} // Ausleiher default -
    virtual ~Medium() {}
    // Titel zurückliefern
    string getTitel() const
    {
        return titel;
    }
    // Ausleiher zurückliefern
    Person *getAusleiher() const
    {
        return ausleiher;
    }
    // das Medium "ausleihen", d.h. Person p, von und bis eintragen
    void ausleihen(Person &_person, Datum _von, Datum _bis)
    {
        ausleiher = &_person;
        von = _von;
        bis = _bis;
    }
    // Medium in der Konsole ausgeben
    virtual void print() const {}
    virtual Medium *clone() const = 0;
};

// Klasse für die Bücher als Spezialisierung von Medium
class Buch : public Medium
{
    // Autor(en) des Buches
    string autor;

public:
    // Standardkonstruktor
    Buch(string _autor = "", string _titel = "", string _verlag = "", int _jahr = 0) : Medium(_titel, _verlag, _jahr), autor(_autor) {} // Konstruktordelegierung
    // das Buch auf der Konsole ausgeben
    void print() const override
    {
        cout << "Autor:         " << autor << endl;
        cout << "Titel:         " << titel << endl;
        cout << "Verlag:        " << verlag << endl;
        cout << "Jahr:          " << jahr << endl;
        if (ausleiher->getName() == "-")
            cout << "Ausleiher:     " << ausleiher->getName() << endl;
        else
            cout << "Ausleiher:     " << ausleiher->getName() << " von: " << von << " bis: " << bis << endl;
        cout << endl;
    }

    Medium *clone() const override
    {
        return new Buch(*this);
    }
};

// Klasse für die DVDs als Spezialisierung von Medium
class DVD : public Medium
{
    // Abspieldauer der DVD
    const int dauer;

public:
    // Standardkonstruktor
    DVD(string _titel = "", string _verlag = "", int _jahr = 0, int _dauer = 0) : Medium(_titel, _verlag, _jahr), dauer(_dauer) {} // Konstruktordelegierung

    // die DVD auf der Konsole ausgeben
    void print() const
    {
        cout << "Titel:         " << titel << endl;
        cout << "Verlag:        " << verlag << endl;
        cout << "Jahr:          " << jahr << endl;

        if (ausleiher->getName() == "-")
            cout << "Ausleiher:     " << ausleiher->getName() << endl;
        else
            cout << "Ausleiher:     " << ausleiher->getName() << " von: " << von << " bis: " << bis << endl;
        cout << "Dauer:         " << dauer << endl;
        cout << endl;
    }
    Medium *clone() const override
    {
        return new DVD(*this);
    }
};

// Die Klasse Bibliothek verweist auf alle Medien (Bücher und DVDs),
// die von Personen (Studierende und Dozenten) ausgeliehen werden
// können.
class Bibliothek
{
    // maximale Anzahl der Medien im Katalog
    const unsigned int maxAnz;
    // Der Medienkatalog
    vector<Medium *> medien;

public:
    // Standardkonstruktor
    Bibliothek(int maxAnz = 1000) : maxAnz(maxAnz) {}

    // Kopie einer DVD oder eines Buches in den Katalog der Bibliothek eintragen
    // Die maximale Anzahl an Medien darf nicht überschritten werden
    void mediumBeschaffen(Medium &medium)
    {
        if (medien.size() < maxAnz)
        {
            Medium *newmedium = medium.clone(); // Medium kopieren und mittels push_back hinzufügen
            medien.push_back(newmedium);
        }
        else
        {
            cout << "Kein Platz mehr!\n"
                 << endl;
        }
    }
    // alle Medien auf der Konsole ausgeben,
    // die im Titel das Suchwort enthalten
    void mediumSuchen(string suchwort)
    {
        cout << endl;
        cout << "Suche nach "
             << "\"" << suchwort << "\""
             << " Ergebnis:" << endl;
        cout << "---------------------------------------" << endl;
        cout << endl;
        for (size_t i = 0; i < medien.size(); i++) // Iterieren durch alle Medien
        {
            if (medien[i]->getTitel().find(suchwort) != string::npos)
            {
                cout << "Medium " << i << ":" << endl;
                medien[i]->print();
            }
        }
        cout << "---------------------------------------" << endl;
    }

    // im Medium mit der Nummer nr, die Person p als Ausleiher
    // eintragen mit von-Datum d und bis-Datum d+p.ausleihdauer
    void mediumAusleihen(int nr, Person &p, Datum d)
    {
        medien[nr]->ausleihen(p, d, d + p.getAusleihdauer());
    }

    // alle Medien in der Konsole ausgeben
    void print() const
    {
        cout << endl;
        cout << "Bibliothekskatalog:" << endl;
        cout << "---------------------------------------" << endl;
        cout << endl;
        for (size_t i = 0; i < medien.size(); i++) // Iterieren durch die Medien
        {
            if (i < medien.size())
            {
                cout << "Medium " << i << ":" << endl;
                medien[i]->print();
            }
        }
        cout << "---------------------------------------" << endl;
    }
};

// hier Konstruktor und Methoden

int main(int argc, char *argv[])
{
    // Umlaute etc. in der Konsole zulassen
    setlocale(LC_ALL, "");
    // Bibliothek mit 100 Plätzen initialisieren
    Bibliothek bib(100);
    // Bücher und DVDs erstellen
    Buch b1("U. Breymann", "C++ - Eine Enführung", "Hanser", 2016);
    Buch b2("U. Breymann", "Der C++ Programmierer", "Hanser", 2017);
    Buch b3("Rainer Grimm", "C++20, Get the details", "Leanpub", 2021);
    Buch b4("Bartłomiej Filipek", "C++17 in detail", "Leanbub", 2018);
    Buch b5("Timothy Gallwey", "The Inner Game of Tennis", "Pan", 2015);
    Buch b6("Brad Gilbert", "Winning Ugly – Mentale Kriegsführung im Tennis", "riva", 2021);
    DVD d1("Das Wunder von Bern", "Senator Filmverleih", 1984, 118);
    DVD d2("Ganz nah dabei - Raumgestaltung in Kitas / für 0- bis 3-Jährige", "Cornelsen", 2013, 58);
    // Ein Buch und eine DVD ausgeben
    b1.print();
    d1.print();
    // Kopien der Bücher und DVDs (Medien) in die Bibliothek
    // einfügen
    bib.mediumBeschaffen(b1);
    bib.mediumBeschaffen(b2);
    bib.mediumBeschaffen(b3);
    bib.mediumBeschaffen(b4);
    bib.mediumBeschaffen(b5);
    bib.mediumBeschaffen(b6);
    bib.mediumBeschaffen(d1);
    bib.mediumBeschaffen(d2);
    // Bestand der Bibliothek ausgeben
    bib.print();
    // Personen anlegen
    Student p1("Peter", 12345678);
    Student p2("Lisa", 87654321);
    Dozent p3("Prof Miller", 4711);
    // Suchen im Bibliotheksbestand durchführen
    bib.mediumSuchen("C++");
    bib.mediumSuchen("Tennis");
    bib.mediumSuchen("Kita");
    // Medien ausleihen
    bib.mediumAusleihen(1, p1, "4.5.2023");
    bib.mediumAusleihen(7, p2, "25.05.2023");
    bib.mediumAusleihen(4, p3, "12.10.2023");
    // Bestand der Bibliothek ausgeben
    bib.print();
}
