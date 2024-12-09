#include <iostream>
#include <string>
#include <vector>
#include <exception>

using namespace std;

// Eigene Exceptionklasse "MyException"
// abgeleitet von exception
class MyException : public exception
{
protected:
    string filename;
    int linenumber;
    string description;

public:
    MyException(string filename, int linenumber, string description)
        : filename(filename), linenumber(linenumber), description(description)
    {
    }

    const char *what() const throw()
    {
        return description.c_str();
    }

    string getFilename() const
    {
        return filename;
    }

    int getLineNumber() const
    {
        return linenumber;
    }
};

// Eigene Exceptionklasse "ElefantMeetsMouse"
// abgeleitet von MyException
class ElefantMeetsMouse : public MyException
{
public:
    ElefantMeetsMouse(string filename, int linenumber, string description)
        : MyException(filename, linenumber, description)
    {
    }

    const char *what() const throw()
    {
        return description.c_str();
    }
};

// Klasse der Tiere
class Animal
{
    // Name des Tiers
    string _name;

public:
    // Konstruktor
    Animal()
    {
        cout << "Bitte Namen des Tieres eingeben: ";
        cin >> _name;
    }
    // virtuelle print-Funktion
    virtual void print(bool nl) const
    {
        cout << _name;
        if (nl)
        {
            cout << endl;
        }
    }
    virtual Animal *clone() const = 0;
};

// Klasse "Elefant"
// abgeleitet von Animal
class Elefant : public Animal
{
public:
    void print(bool nl) const override
    {
        Animal::print(nl);
    }
    Animal *clone() const override
    {
        return new Elefant(*this);
    }
};

// Klasse "Tiger"
// abgeleitet von Animal
class Tiger : public Animal
{
public:
    void print(bool nl) const override
    {
        Animal::print(nl);
    }
    Animal *clone() const override
    {
        return new Tiger(*this);
    }
};

// Klasse "Mouse"
// abgeleitet von Animal
class Mouse : public Animal
{
public:
    void print(bool nl) const override
    {
        Animal::print(nl);
    }
    Animal *clone() const override
    {
        return new Mouse(*this);
    }
};

class Zoo
{
    // Name des Zoos
    string _name;
    // Die Tiere werden in einem Vektor gespeichert
    vector<Animal *> animals;

public:
    // Konstruktor
    Zoo()
    {
        // Name zuweisen
        cout << "Bitte Name des Zoos eingeben: ";
        cin >> _name;
        // Wenn der String kuerzer als 4 Zeichen ist,
        // dann MyException werfen
        if (_name.length() < 4)
        {
            throw MyException(__FILE__, __LINE__+14, "Zooname zu kurz");
        }
        // Ansonsten, den 5. Buchstaben des Namens gross machen
        _name.at(4) = toupper(_name.at(4));
    }

    // Ein Tier dem Zoo hinzufuegen
    void add_animal(const Animal &animal)
    {
        // Wenn ein Elefant nach einer Maus eingefuegt wird, oder anders herum
        // dann Ausnahme werfen
        if (!animals.empty() && ((dynamic_cast<const Mouse *>(&animal) != nullptr && dynamic_cast<const Elefant *>(animals.back()) != nullptr) ||
                                 (dynamic_cast<const Elefant *>(&animal) != nullptr && dynamic_cast<const Mouse *>(animals.back()) != nullptr)))
        {
            throw MyException(__FILE__, __LINE__+19, "Elefant trifft auf Maus");
        }
        // sonst Tier hinzufuegen
        animals.push_back(animal.clone());
    }
    // Alle Zootiere ausgeben
    void print() const
    {
        for (const auto &animal : animals)
        {
            animal->print(true);
        }
    }
};

int main(int argc, char *argv[])
{
    char choice;
    string name;

    // Ausnahmepruefung aktivieren
    try
    {
        Zoo zoo;
        do
        {
            cout << endl
                 << "Bitte Tierart auswaehlen:" << endl;
            cout << "1 = Elefant" << endl;
            cout << "2 = Tiger" << endl;
            cout << "3 = Maus" << endl;
            cout << "e = Ende mit Eingabe" << endl;
            cout << "Eingabe: ";
            cin >> choice;
            switch (choice)
            {
            case '1':
            {
                Elefant elefant = Elefant();
                zoo.add_animal(elefant);
                break;
            }
            case '2':
            {
                Tiger tiger = Tiger();
                zoo.add_animal(tiger);
                break;
            }
            case '3':
            {
                Mouse mouse = Mouse();
                zoo.add_animal(mouse);
                break;
            }
            case 'e':
                break;
            default:
                // Einen String als Ausnahme werfen
                throw string("Fehlerhafte Eingabe!");
            }

            cout << endl;
            zoo.print();
        } while (choice != 'e');
    }
    // Ausnahmen auffangen
    // Speziellste Ausnahme auffangen und ausgeben

    // MyException auffangen und ausgeben
    catch (const ElefantMeetsMouse &e)
    {
        cout << "Fehler: '" << e.what() << "' aufgetreten in Datei " << e.getFilename() << ", Zeile: " << e.getLineNumber() << "." << endl;
    }
    catch (const MyException &e)
    {
        cout << "Fehler '" << e.what() << "' aufgetreten in Datei " << e.getFilename() << ", Zeile: " << e.getLineNumber() << "." << endl;
    }

    // Alle anderen Standardausnahmen auffangen und ausgeben
    catch (const exception &e)
    {
        cout << "Standardausnahme: " << e.what() << endl;
    }

    // Alle Strings auffangen und ausgeben
    catch (const string &s)
    {
        cout << s << endl;
    }

    // Alle anderen Ausnahmen auffangen
    catch (...)
    {
        cout << "Unknown exception" << endl;
    }
    return 0;
}