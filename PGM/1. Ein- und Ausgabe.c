//Aufgabe 1
#include <stdio.h>

int main(int argc, char* argv[]) {
    printf("Hello World!\n");
    return 0;
}

//Aufgabe 2
#include <stdio.h>
int main()
{
    printf("Hello World!\n");
    return 0;
}

//Aufgabe 3
#include <stdio.h>
int main()
{
    printf("Hello World!\n");
    return 0;
}

//Aufgabe 4
#include <stdio.h>
int main()
{
    printf("String: %s \n", "Das ist eine Zeichenkette");
    printf("Ganze Zahl: %i \n", 42);
    printf("Fliesskommazahl: %f \n", 3.1415);
    printf("Fliesskommazahl mit Formatangabe: %08.2f\n", 3.1415);
    return 0;
}

//Aufgabe 5
#include <stdio.h>

int main(int argc, char *argv[]) {
    int a, b, c;
    scanf("%i %i %i\n", &a, &b, &c);
    printf("Zahl 3: %4i\n", c);
    printf("Zahl 2: %4i\n", b);
    printf("Zahl 1: %4i\n", a);
    return 0;
}

//Aufgabe 6
#include <stdio.h>

int main(int argc, char *argv[]) {
    int a;
    float b;
    char c;
    scanf ("%d %f %c", &a, &b, &c);
    printf("Ganzzahlen    : %.10i\n", a);
    printf("Gleitkommazahl: %.5f\n", b);
    printf("Zeichen       : %c\n", c);
    return 0;
}

