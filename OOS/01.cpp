
#include <string>
#include <ctime>
#include <iostream>

using namespace std;

// Aufzählungstyp für wählbare Objekte
// STEIN - 0, SCHERE - 1, PAPIER - 2
enum class Object
{
    ROCK,
    SCISSORS,
    PAPER
};

// Aufzählungstyp für mögliche Spielausgänge
enum class Result
{
    PLAYER_ONE_WINS,
    PLAYER_TWO_WINS,
    DRAW
};

// Struktur für einen Spieler bestehend aus Name und Wahl des Spielers
struct Player
{
    string name;
    Object choice;
};

// Name des Spielers eingeben
string insert_name()
{

    // HIER programmieren:
    // Den Namen des Spielers von der Konsole einlesen und zurückgeben
    // Tip: für das Einlesen eines Strings gibt es eine bestimmte Funktion, siehe auch Vorlesung Folie "Eine Zeile als String einlesen"
    string name;
    cout << "Name des Spielers: ";
    cin.clear();
    getline(cin, name);
    return name;
}

Object determine_choice(string choice)
{
    if (choice.compare("CoderunnerTestWertStein") == 0)
    {
        return Object::ROCK;
    }
    else if (choice.compare("CoderunnerTestWertSchere") == 0)
    {
        //return Object::SCISSORS;
        return Object::ROCK;
    }
    else if (choice.compare("CoderunnerTestWertPapier") == 0)
    {
        //return Object::PAPER;
        return Object::ROCK;
    }
    else
    {
        // Den Computer zufällig waehlen lassen.
        // HIER beantworten Sie folgende Fragen:

        // Wie funktioniert die funktion rand?
        // --> Die Funktion rand generiert eine Folge von Pseudozufallszahlen, die durch einen Algorithmus erzeugt werden. Der Algorithmus verwendet einen Startwert, um die Zufallszahlensequenz zu initialisieren.

        // Was bewirkt die funktion srand?
        // --> Die Funktion srand wird verwendet, um den Startwert für die Funktion rand zu setzen.

        // Warum wird hier die Zeit (time) als Eingabe für die Funktion srand verwendet?
        // --> Damit das Programm bei jedem Ausführen andere Ergebnisse liefert und nicht vorhersehbar wird.
        // --> Die aktuelle Uhrzeit wird als Parameter übergeben und liefert somit einen zufälligen Startwert.

        // Warum wird hier modulo 3 verwendet?
        // --> Da hier lediglich die Werte 0, 1, 2 benötigt werden, welche n % 3 liefert.

        srand(static_cast<int>(time(nullptr)));
        int choice = rand() % 3;
        return static_cast<Object>(choice);
    }
}

// Die Wahl von Stein etc. als String zurückgeben lassen
string get_name(Object object)
{

    // HIER programmieren:
    // Abhängig vom vorliegenden Object einen entsprechenden String zurückgeben.
    // z.B: Wenn Object dem Wert Object::ROCK entspricht, dann String "Stein" zurückgeben
    if (object == Object::ROCK)
    {
        return "Stein";
    }
    else if (object == Object::SCISSORS)
    {
        return "Schere";
    }
    else if (object == Object::PAPER)
    {
        return "Papier";
    }
    else
    {
        return "";
    }
}

// Einen Text mit dem Namen des Spielers und seiner Wahl ausgeben
void print_choice(Player player)
{

    // HIER programmieren:
    // Auf der Konsole ausgeben, für welches Object sich der Spieler entschieden hat.
    // z.B.: "Computer hat das Object Schere gewählt"
    // TIP: Nutzen sie hierzu die Funktion get_name
    cout << player.name << " hat das Objekt " << get_name(player.choice) << " gewählt" << endl;
}

// Die Wahl des Spielers abfragen
Object chose()
{

    // HIER programmieren:
    // Die Wahl des Spielers von der Konsole einlesen und zurückgeben
    // Stellen sie sicher, dass es sich um eine gültige Wahl handelt!
    // TIP: Nutzen Sie dazu eine geeignete Schleife. Siehe auch Vorlesung Folie "Annehmende Schleifenanweisungen – Do"
    int input;
    cout << "Bitte Objektwahl eingeben (1 = Stein, 2 = Schere, 3 = Papier): ";
    do
    {
        cin >> input;
    } while (input < 1 || input > 3);

    if (input == 1)
    {
        return Object::ROCK;
    }
    else if (input == 2)
    {
        return Object::SCISSORS;
    }
    else
    {
        return Object::PAPER;
    }
}

Result determine_result(Player player_1, Player player_2)
{

    // HIER programmieren:
    // Vergleichen Sie die gewählten Objekte, ermitteln sie das Spielergebnis und geben sie es zurück.
    // TIP: Wenn Sie für den Vergleich mit ganzene Zahlen _rechnen_ wollen, dann nutzen sie den static_cast, siehe auch Vorlesung Folie "Casts in C++: Static_cast"
    if ((player_1.choice == Object::ROCK && player_2.choice == Object::SCISSORS) ||
        (player_1.choice == Object::PAPER && player_2.choice == Object::ROCK) ||
        (player_1.choice == Object::SCISSORS && player_2.choice == Object::PAPER))
    {
        return Result::PLAYER_ONE_WINS;
    }
    else if ((player_2.choice == Object::ROCK && player_1.choice == Object::SCISSORS) ||
             (player_2.choice == Object::PAPER && player_1.choice == Object::ROCK) ||
             (player_2.choice == Object::SCISSORS && player_1.choice == Object::PAPER))
    {
        return Result::PLAYER_TWO_WINS;
    }
    else
    {
        return Result::DRAW;
    }
}

void print_result(Player player_1, Player player_2)
{

    // HIER programmieren:
    // Ermitteln Sie zunächst das Spielergebnis. Nutzen sie dazu die Funktion determine_result.
    // Geben Sie anschließend auf der Konsole aus, wer gewonnen hat.
    // z.B: "Spieler Computer hat gewonnen" oder "Unentschieden"
    if (determine_result(player_1, player_2) == Result::PLAYER_ONE_WINS)
    {
        cout << "Spieler " << player_1.name << " hat gewonnen." << endl;
    }
    else if (determine_result(player_1, player_2) == Result::PLAYER_TWO_WINS)
    {
        cout << "Spieler " << player_2.name << " hat gewonnen." << endl;
    }
    else
    {
        cout << "Unentschieden" << endl;
    }
}

int main(int argc, char *argv[])
{
    Player player_1, player_2;
    player_1.name = "Computer";
    player_2.name = insert_name();
    player_1.choice = determine_choice(player_2.name); 
    cout << "Der Computer hat seine Wahl getroffen." << endl;
    player_2.choice = chose();
    print_choice(player_1);
    print_choice(player_2);
    print_result(player_1, player_2);

    return 0;
}