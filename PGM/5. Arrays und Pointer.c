//Aufgabe 11
#include <stdio.h>
int main(int argc, char *argv[]) {
    int value = 42;
    int * pointer = &value;
    printf("%d\n", *pointer);
    *pointer = 85;
    printf("%d\n", *pointer);
    ++*pointer;
    printf("%d\n", *pointer);
    return 0;
}

//Aufgabe 12
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(int argc, char *argv[]) {
    char Arr[40];
    char (*ptrArr)[40] = NULL;
    ptrArr = &Arr;
    scanf("%s", Arr);
    printf("%s", *ptrArr);
    return 0;
}

//Aufgabe 13
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char *argv[]) {
    int Arr[4];
    int sum = 0;
    int i;
    double average;
    
    for (i = 0; i < 4; i++)
    {
        scanf("%i", &Arr[i]);
        sum = sum + Arr[i]; //Summieren der Eingaben
    }
    average = ((double)sum / (double)i); //Typenkonvertierung und Ausrechnen des Durchschnitts

    printf("Summe: %d\nDurchschnitt: %lf", sum, average);
    return 0;
}

//Aufgabe 14
#include <stdio.h>

int main(int argc, char *argv[]) {
    int i;
    int * ptr; // Definition int-Pointer
    int ** ptrptr; //Definition int-Pointer auf einen int-pointer
    ptr = &i; //Zuweisen der Adresse von i auf den Pointer
    ptrptr = &ptr; //Zuweisen der Adresse des Pointers auf den anderen Pointer
    i = 1; 
    printf("%d\n", i);
    printf("%d\n", *ptr); //Ausgabe des Objekts des Pointers
    **ptrptr = 2; //Objekt des Pointers dessen Adresse der andere Pointer speichert wird auf 2 gesetzt
    printf("%d\n", i);

    return 0;
}

//Aufgabe 15
#include <stdio.h>

int main(int argc, char *argv[]) {
    int Arr[4];
    int i;
    int * ptr;
    for (i = 0; i < 4; i++)
    {
        scanf("%d", &Arr[i]);
    }
    ptr = &Arr[2]; //Pointer auf die Adresse des Arrays an der Stelle 2 setzenn
            for (i = 0; i < 4; i++)
    {
        printf("%d ", Arr[i]); //Ausgabe
    }
    printf("\n"); //Zeilensprung zwischen den zwei Ausgaben
    *ptr = 42; //Zuweisen des Objekts des Pointers auf 42
        for (i = 0; i < 4; i++)
    {
        printf("%d ", Arr[i]); //Ausgabe
    }
    return 0;
}