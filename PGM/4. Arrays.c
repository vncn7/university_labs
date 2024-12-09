//Aufgabe 1
#include <stdio.h>
#define ARR_DIM 4 //Array Dimension

int main(int argc, char *argv[]) {
    double input[ARR_DIM];
    double min_input;               
    int min_index, i;
    for (i = 0; i < ARR_DIM; i++) //Schleife zum Einlesen der Werte
    {
        scanf("%lf", &input[i]);
    }
    min_input = input[0]; 
    min_index = 0; 
    
    for (i = 1; i < ARR_DIM; i++) //Schleife für Länge des Arrays
    {
        if (input[i] < min_input) //Abfrage zum Bestimmen des Minimus
        {
            min_input = input[i]; //Minimum-Wert setzen
            min_index = i; //Minimum-Index setzen
        }
    }
    printf("Kleinste Zahl: %.1lf an Index %d", input[min_index], min_index);
    
    return 0;
}

//Aufgabe 2
#include <stdio.h>
#define ARR_DIM 40

int main(int argc, char *argv[]) {
    char string[ARR_DIM]; 
    int anzahl = 0 ;     
    scanf("%s", string); 
    
    for (int i = 0; string[i] !=0 ; i++) //Schleife für Länge des Strings
    {
        if (string[i]>='a' && string[i]<='z') //Abfrage ob Kleinbuchstabe a bis z
        {
            anzahl++; //Zählen 
        }
    }
    printf("%d Kleinbuchstaben", anzahl);
    anzahl = 0;
    return 0;
}

//Aufgabe 3
#include <stdio.h>
#define ARR_DIM 40

int main(int argc, char *argv[]) {
    char string[ARR_DIM]; 
    int anzahl = 0 ;     
    scanf("%s", string); 
    
    for (int i = 0; string[i] !=0 ; i++) //Schleife für Länge des Strings
    {
        if (string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u' ||
            string[i] == 'A' || string[i] == 'E' || string[i] == 'I' || string[i] == 'O' || string[i] == 'U') //Abfrage ob Vokal
        {
            anzahl++; 
        }
    }
    printf("%d Vokale", anzahl);
    anzahl = 0;
    return 0;
}

//Aufgabe 4
#include <stdio.h>
#define ARR_DIM 40

int main(int argc, char *argv[]) {
    char str[ARR_DIM]; 
    char vowel;     
    scanf(" %c %s", &vowel, str);
    
    for (int i = 0; str[i] !=0 ; i++) //Schleife für Länge des strings
    {
        if (str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' 
         || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U') //Abfrage ob Vokal
            {
                str[i] = vowel; //Ersetze Vokal
            }
    }
    printf("%s", str);
    return 0;
}

//Aufgabe 5
#include <stdio.h>
#define ARR_DIM 40

int main(int argc, char *argv[]) {
    char string[ARR_DIM];   
    scanf("%s", string); 
    
    for (int i = 0; string[i] !=0 ; i++) 
    {
        if (string[i]>='a' && string[i]<='z') //Abfrage ob Kleinbuchstabe
        {
            string[i]=string[i]-32;     //ascii-tabelle + 32
        }
        else if (string[i]>='A' && string[i]<='Z') //Abfrage ob Großbuchstabe
        {
            string[i]=string[i]+32;     //ascii-tabelle + 32
        } 
    }
    printf("%s", string);
    return 0;
}

//Aufgabe 6
#include <stdio.h>
#define ARR_DIM 40

int main(int argc, char *argv[]) {
    char string[ARR_DIM];
    char string_short[ARR_DIM] = {0}; //Initialisiere zweites Array nur mit Nullen
    int first, last, i = 0, j = 0;   
    scanf("%s %d %d", string, &first, &last); 
    printf("%s %d-%d: ", string, first, last);

    while (string[i] != 0)  //Schleife für Länge des eingegebenen Strings
    {
        if (i >= first && i <= last) //Abfrage ob der Buchstabe sich im eingegebenen Bereich befindet
        {
            string_short[j] = string[i]; //Schreibe einzelne Buchstaben in Array 2
            j++; //Zähler Index Array 2
        }
        i++; //Zähler Index Array 1

    }
    printf("%s", string_short);  
    return 0;
}

//Aufgabe 7
#include <stdio.h>
#define ARR_DIM 40

int main(int argc, char *argv[]) {
    char string[ARR_DIM];
    char string_reverse[ARR_DIM] = {0}; //Initialisiere zweiter Array nur mit Nullen
    int i = 0, j = -1; //setze Zähler -1 damit das nullte Feld auch mitgezählt wird ist
    scanf("%s", string); 

    for (i = 0; string[i] !=0 ; i++) //Schleife für Länge des Strings
        {
            j++; //Zähle die Länge des eingegebenen Strings
        }
    for (i = 0; string[i] !=0 ; i++, j--) //Schleife für Länge des Strings
        {
            string_reverse[j] = string[i]; // i zählt hoch j zählt runter
        }
    printf("%s", string_reverse);   
return 0;
}

//Aufgabe 8
#include <stdio.h>
#define ARR_DIM 11

int main(int argc, char *argv[]) {
    int noten[ARR_DIM] = {0};
    int i;
    double durchschnitt = 0;

    for (i = 0; i < 10; i++) //Schleife zum Einlesen
    {
        scanf("%d", &noten[i]);
        if (noten[i] > 6 || noten[i] < 1) //Abbruch der Schleife
        {
            if (i == 0) // Falls die erste eingegebene Note nicht zulässig ist wird direkt abgebrochen
            {
                break;  
            }
            else
            {
            durchschnitt = durchschnitt/i; //Ausrechnen des Durchschnitts mit folgendem Abbruch
                break;
            } 
        }
    durchschnitt = durchschnitt + noten[i]; //Addition der Noten
    }
    printf("Durchschnitt (N=%d): %.2lf",i, durchschnitt); //Ausgabe
    return 0;
}

//Aufgabe 9
#include <stdio.h>
#define ARR_DIM1 11

int main(int argc, char *argv[]) {
    int n, m, i;
    scanf("%d %d", &n, &m);

    for (i = 1; i < 201; i++) 
    {
        if (i%n == 0 && i%m == 0) 
        {
            printf("fizzbuzz\n");
        }
        else
        {
            if (i%n == 0)
            {
            printf("fizz\n");
            }
            else if (i%m == 0)
            {
            printf("buzz\n");
            }
            else
            {
            printf("%d\n", i);
            }
        }
    }
    return 0;
}