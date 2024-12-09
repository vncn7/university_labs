//Aufgabe 6
// Sie schreiben nur die Funktion, keine Ausgabe!
int stringlength(char test[]) { 
int i = 0;
while (test[i] != 0) //Schleife bis Ende des Strings
{
    i++; //Zähler
}
return i; //Rückgabe der lokalen Variabel i
}

//Aufgabe 7
// Sie schreiben nur die Funktion, keine Ausgabe!
double triangleArea(double g, double h) {
    return g * h / 2; //Rückgabe Grundseite * Höhe / 2
}

//Aufgabe 8
// Sie schreiben nur die Funktion, keine Ausgabe!
double bmi(int weight, int height) {
    return weight / ((height * 0.01) * (height * 0.01)); //Ausrechnen BMI mit anschließender Rückgabe
}

//Aufgabe 9
// Sie schreiben nur die Funktion, keine Ausgabe!
double celsius(int fahrenheit) {
    return (double)5/9 * (fahrenheit-32);
}

//Aufgabe 10 
// Sie schreiben nur die Funktion, keine Ausgabe!
int prime(int number) {
    int counter = 0;
    for (int i = 1; i <= number; i++) //Schleife für eingegebene 
    {
        if (number % i == 0) //Testen ib Zahl restlos teilbar ist
        {
            counter++; //Counter wie oft die Zahl ohne Rest teilbar ist
        }
    }
    if (counter == 2) //Wenn Counter "nur" zwei ist, liegt eine Primzahl vor und 1 wird zurückgegeben
    {
        return 1;
    }
    else
    return 0;
}

//Aufgabe 11
// Sie schreiben nur die Funktion, keine Ausgabe!
int weekday(int d, int m, int y) {
    return (d+=m<3?y--:y-2,23*m/9+d+4+y/4-y/100+y/400)%7; //Wikipedia Copy Paste
}