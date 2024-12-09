// Aufgabe 1
int minimum(int * numbers, int i) {
    int min = *numbers; // Minimum wird auf ersten Wert des Arrays gesetzt
    for (int j = 0; j < i; j++) //Schleife für Länge des Arrays
    {
        if (min > *(numbers+j)) //Abfrage ob Array an der folgenden Stelle kleiner als minimum
        {
            min = *(numbers+j); //Setzen des neuen Minimums
        }
    }
    return min; //Rückgabe
}

// Aufgabe 2
void toUpper(char * arr) {
    for (int i = 0; *(arr+i) !=0 ; i++)
    {
        if (*(arr+i)>='a' && *(arr+i)<='z') //Abfrage ob Kleinbuchstabe
        {
            *(arr+i) = *(arr+i)-32; //Ändern zu Großbuchstabe
        }
    }
}

// Aufgabe 3
void ownStrcpy(char * ptr1, char * ptr2) {
    for (int i = 0; *(ptr2+i) !=0 ; i++)  
    {
       *(ptr1+i) = *(ptr2+i); 
    }
}

// Aufgabe 4
void append(char * buffer, char * string) {
    int length = 0;
    for (int i = 0; *(buffer+i) !=0 ; i++) //Schleife für Länge des Strings
        {
            length++; //Zähle die Länge des eingegebenen Strings
        }
    for (int i = 0; *(string+i) != 0 ; i++) //Schleife für Länge des zweiten Strings
        {
            *(buffer+(length+i)) = *(string+i); //Schreibe Buchsteben an die Stelle +1 nach Ende des ersten Strings
        }
}

// Aufgabe 5
#define PI 3.1415
void sphere(int radius, double * volume, double * surface) {
    *surface = 4 * PI * (radius*radius);
    *volume = ((double)4/(double)3) * PI * (radius*radius*radius);
}
