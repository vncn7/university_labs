// Aufgabe 1
#include <stdio.h>

// Deaklaration Datentyp
typedef struct bruch
{
    double zaehler;
    double nenner;
} bruch;

// Funktion Multiplizieren
void multiply(bruch *mult_res, bruch *b1, bruch *b2)
{
    mult_res->zaehler = b1->zaehler * b2->zaehler;
    mult_res->nenner = b1->nenner * b2->nenner;
}

// Funktion Dividieren
void divide(bruch *div_res, bruch *b1, bruch *b2)
{
    div_res->zaehler = b1->zaehler * b2->nenner;
    div_res->nenner = b1->nenner * b2->zaehler;
}

int main(int argc, char *argv[])
{
    // Deklaration Brüche
    bruch b1;
    bruch b2;
    // Deklaration der Lösungen
    bruch mult_res;
    bruch div_res;

    scanf("%lf/%lf", &b1.zaehler, &b1.nenner);
    scanf("%lf/%lf", &b2.zaehler, &b2.nenner);

    // Funktionsaufruf
    multiply(&mult_res, &b1, &b2);
    divide(&div_res, &b1, &b2);

    // Ausgabe
    printf("(%.1lf/%.1lf)*(%.1lf/%.1lf)=(%.1lf/%.1lf)\n", b1.zaehler, b1.nenner, b2.zaehler, b2.nenner, mult_res.zaehler, mult_res.nenner);
    printf("(%.1lf/%.1lf)/(%.1lf/%.1lf)=(%.1lf/%.1lf)\n", b1.zaehler, b1.nenner, b2.zaehler, b2.nenner, div_res.zaehler, div_res.nenner);

    return 0;
}

// Aufgabe 2
#include <stdio.h>
#include <string.h>
#define MAX 20

// Deaklaration Datentyp
typedef struct customer
{
  char lastName[MAX];
  char firstName[MAX];
  unsigned int number;
}customer; 


int main(int argc, char* argv[]) 
{
// Deaklaration first customer
customer first;

// Einfügen der Daten
strcpy(first.lastName, "Maurer");
strcpy(first.firstName,"Hans");
first.number = 1;

// Deklaration second customer
customer second; 

// Einlesen und Ausgeben der Attribute
scanf("%d %s %s", &second.number, second.firstName, second.lastName);
printf("%d: %s %s\n", first.number, first.firstName, first.lastName);
printf("%d: %s %s", second.number, second.firstName, second.lastName);

return 0;
}

// Aufgabe 3 

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int n, i, j, tmp;
    int *arr;

    scanf("%d", &n);                      // Eingabe der Anzahl der einzugebende Zahlen
    arr = (int *)malloc(n * sizeof(int)); // arr mit Größe der eingegebenen Zahl n * Int-Größe
    if (arr == NULL)                      // Speicherüberprüfung
        exit(-1);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]); // Einlesen der zu sortierenden Zahlen
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++) // Geht alle Einträge außer des Starteintrags durch und vergleicht diese mit dem Starteintrag
        {
            if (arr[i] > arr[j])
            {
                tmp = arr[i];    // Zwischenspeichern des zu ersetzenden array-Eintrags
                arr[i] = arr[j]; // Überschreiben des arr Eintrags mit dem kleinsten ermittelten Eintrag
                arr[j] = tmp;    // Austausch der Einträge
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%3d: %3d", (i + 1), arr[i]); // Formartierte Ausgabe der sortierten Zahlen
    }
    free(arr);
    arr = NULL; // Speicher freimachen
    return 0;
}

// Aufgabe 4
// Typendefinition
typedef struct numberItem
{
    int number;              
    struct numberItem *next; // Pointer auf das nächste Element der Liste
} numberItem;

numberItem *root = NULL; // Anker - NULL -> Liste ist leer

// Funktion Einfügen
void appendNumberItem(numberItem **root, int number)
{
    numberItem *new = (numberItem *)malloc(sizeof(numberItem)); // Speicherallokation für die Struktur
    if (new == NULL)
        exit(-1); // Abfrage ob Speicher verfügbar

    new->number = number; // Übergebene Werte initialisieren

    if (*root == NULL) // Abfrage ob Liste noch leer ist
    {
        new->next = NULL; // Der Next-Pointer des Elements zeigt auf NULL (Ende der Liste)
        *root = new;      // Der Anker zeigt nun auf das neue Element
    }
    else // Es existiert bereits ein Listenelement
    {
        numberItem *ptr = *root;  // Pointer wird auf das erste Element gesetzt
        while (ptr->next != NULL) // Durch die Liste gehen
        {
            ptr = ptr->next;
        }
        ptr->next = new;  // Der Next-Pointer des vorherigen Elements zeigt nun auf das neue (letzte) Listenelement
        new->next = NULL; // Next-Pointer zeigt auf das neue Ende der Liste
    }
}

// Funktion Ausgeben
void printList(numberItem *root)
{
    numberItem *ptr = root; // Pointer wird zum Start der while-Schleife auf den Ankerpoiunter gesetzt
    while (ptr != NULL)     // Solange Pointer nicht auf NULL zeigt
    {
        printf("%d\n", ptr->number);
        ptr = ptr->next; // Pointer wird auf den jeweiligen Next-Pointer gesetzt
    }
}

// Funktion Leeren
void clearList(numberItem *root)
{
    numberItem *ptr = root;            // Pointer wird auf den Ankerpointer gesetzt
    while (root != NULL) // Wiederhole bis Anker auf NULL zeigt
    {
        ptr = ptr->next; // Pointer wird auf Next-Pointer gesetzt
        free(root);      // Listenelement 1 wird entfernt
        root = ptr;      // Anker zeigt nun auf Listenelement 2
    }
}

// Aufgabe 5
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20

// Deklaration Struktur
typedef struct customer
{
    int number;
    char firstName[MAX];
    char lastName[MAX];
    struct customer *next;
} customer;

// Funktion Kunde anlegen
customer *createCustomer(int number, char *firstName, char *lastName)
{
    customer *new_customer = (customer *)malloc(sizeof(customer));

    // Attribute einfügen
    new_customer->number = number;
    strcpy(new_customer->firstName, firstName);
    strcpy(new_customer->lastName, lastName);

    new_customer->next = NULL; // Next-Pointer wird (vorerst) auf NULL gesetzt
    return new_customer;       // Rückgabe eines Pointers auf die Struktur
}

// Funktion Kunde in Liste einsortieren
void addCustomer(customer *root, customer *new_customer)
{
    customer *ptr = root;
    while (ptr->next != NULL && ptr->next->number < new_customer->number) // Schleife läuft durch die Liste bis die Kundennummer vom Next-Pointer kleiner ist, als die des einzusortierenden Kundens
    {
        ptr = ptr->next;
    }
    new_customer->next = ptr->next; // next-pointer von ptr wird next-pointer von new_customer 
    ptr->next = new_customer; // new_customer wird nächster Eintrag nach ptr
}

// Funktion Kunden zählen
unsigned int customerCount(struct customer *root)
{
    customer *ptr = root;
    unsigned int count = 0; 
    while (ptr != NULL)
    {
        ptr = ptr->next;
        count++;
    }
    return count; 
}

// Funktion Ausgabe
void printList(customer *root)
{
    customer *ptr = root; 
    while (ptr != NULL)
    {
        printf("%d: %s %s\n", ptr->number, ptr->firstName, ptr->lastName);
        ptr = ptr->next;
    }
}

// Funktion Liste löschen
void clearList(customer *root)
{
    customer *ptr = root;
    customer *tmp;
    while (ptr != NULL)
    {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}

int main(int argc, char *argv[])
{
    struct customer *root = NULL;
    root = createCustomer(1, "Hans", "Maurer");
    addCustomer(root, createCustomer(3, "Tatjana", "Roth"));
    addCustomer(root, createCustomer(2, "Anna-Maria", "Schmidt"));
    printf("Momentan sind %u Kunden erfasst.\n", customerCount(root));
    printList(root);
    clearList(root);
    root = NULL;
    printf("Momentan sind %u Kunden erfasst.\n", customerCount(root));
    printList(root);
    return 0;
}