// Aufgabe 1
#include <stdio.h>

int potenz_iter(int a, int b, int n) 
{
    int erg = 1; //Setze Ergebnis auf 1
    while(n != 0) // Führe Berechnung durch solange n nicht 0 ist
    {
        erg = erg * (a + b); //Berechnung
        n--; // Zähle n herunter
    }
    return erg; //Rückgabe des berechneten Wertes
}

int main(int argc, char *argv[]) {
    int a, b, n;
    scanf("%d %d %d", &a, &b, &n);
    printf("%d", potenz_iter(a, b, n)); //Ausgabe und Übermittlung der Parameter an die Funktion
    return 0;
}


// Aufgabe 2
#include <stdio.h>

int potenz_rekursive(int a, int b, int n) 
{
	if (n == 0) //Abbruchbedingung
		return 1; 
	else
		return potenz_rekursive(a, b , n-1) * (a + b); //Rückgabe a und b;  n wird heruntergezählt
}

int main(int argc, char *argv[]) {
    int a, b, n;
    scanf("%d %d %d", &a, &b, &n);
    printf("%d", potenz_rekursive(a, b, n)); //Ausgabe und Übermittlung der Parameter an die Funktion
    return 0;
}

// Aufgabe 3
#include <stdio.h>
int input() //Eingabefunktion
    {
        int n;
        scanf("%d", &n);
        return n;
    }
int faculty(int n)
    {
        while (n != 0) //solange n nicht 0 ist
        {
            return (n * faculty(n-1)); // rekursive Berechnung, n wird runtergezählt
        }
        return 1; //Abbruch der Funktion
    }

int main(int argc, char *argv[]) {
    printf("%d! = %d", input(),faculty(input())); //Ausgabe Rückgabewerte der beiden Funktionen
    return 0;
}

// Aufgabe 4
#include <stdio.h>

int main(int argc, char *argv[]) {
    double y = 0;
    double a, x, n;
    scanf("%lf %lf %lf", &a, &x, &n);
    for(int i = 1; i <= n; i++ ) //Schleife für i kleiner gleich n
    {
        y = (y + (a + 2 * i * x)); //aufsummieren der einzelnen REihen
    }
    printf("%.1lf", y);
    return 0;
}

// Aufgabe 5
#include <stdio.h>
double reihe(double a, double x, double n)
{
    if (n == 0) //Abbruchbedingung
        return 0;
    else
        return reihe(a, x, n-1) + (a + 2 * x * n); //REkursive Berechnung der Reihen
}
int main(int argc, char *argv[]) {
    double a, x, n;
    scanf("%lf %lf %lf", &a, &x, &n);
    printf("%.1lf", reihe(a, x, n));
    return 0;
}

// Aufgabe 6
#include <stdio.h>
char getFirstCapitalLetter(char * string, int i) 
{
    if (string[i] == '\0') //Abbruchbedingung
        return ' ';
    if (string[i]>='A' && string[i]<='Z') //Abfrage ob Großbuchstabe
        return string[i];
    return getFirstCapitalLetter(string, i+1); // rekursives aufrufen der funktion, index wird jeweils um 1 erhöht
}

int main(int argc, char *argv[]) 
{
    char string[40] = {0} ;
    int i = 0;
    scanf("%s", string);
    printf("%c", getFirstCapitalLetter(string, i));
    return 0;
}

// Aufgabe 7
#include <stdio.h>

int isPrime(int number, int i) 
{
    if(number == i) //Abfrage ob Zahl (durch sich selbst) teilbar ist, i wird hochgezählt und startet bei zwei
        return 1;
    if(number % i == 0 || number == 1) //Keine Primzahl, wenn restlos teilbar + Außnahmefall 1
        return 0;
    else
        return isPrime(number, i + 1);
}

int main(int argc, char *argv[]) {
    int i = 2; // i wird auf zwei gesetzt, da es unnötig wäre durch 1 zu teilen
    int number;
    scanf("%d", &number);
    printf("%d", isPrime(number, i));
    return 0;
}

