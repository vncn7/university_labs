//Aufgabe 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char *argv[]) {
    int x;
    scanf("%d", &x);
    for (int i=0; i<x; i++) {
        printf("*");
    }
    
    return 0;
}

//Aufgabe 2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char *argv[]) {
        int x;
    scanf("%d", &x);
    for (int i=0; i<x; i++) {
        if(i%2==0)
            printf("*");
        else
            printf("_");
    }
    
    return 0;
}

//Aufgabe 3
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char *argv[]) {
    int zeilen, spalten;
    scanf("%d %d", &zeilen, &spalten);
    for (int i=0; i<zeilen; i++) {
        for(int j=0; j<spalten; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}

//Aufgabe 4
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char *argv[]) {
    int zeilen, spalten;
    scanf("%d %d", &zeilen, &spalten);
    for (int i=0; i<zeilen; i++) {
        for(int j=0; j<spalten; j++) {            
            if (i==0 || j==0 || i==zeilen-1 || j==spalten-1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}

//Aufgabe 5
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char *argv[]) {
    int zeilen, spalten, k=-1;
    scanf("%d %d", &zeilen, &spalten);
    for (int i=0; i<zeilen; i++) {
            for(int j=0; j<spalten; j++) {
                if(k==-1)
                    if (j%2!=0 ){
                        printf("-");
                        }
                    else {
                    printf("+");
                        }
                else {
                    if (j%2==0 ){
                        printf("-");
                        }
                    else {
                    printf("+");
                        }
                     }   
                }
        printf("\n");
        k=k*-1;
    }
    return 0;
}

//Aufgabe 6
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char *argv[]) {
    int grad;
    printf("Celsius\tFahrenheit\n");
    for(grad=-20; grad<=300; grad=grad+20) {
        printf("%7d\t %9d\n", grad, ((grad*9)/5)+32);
    }
    return 0;
}

//Aufgabe 7
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char *argv[]) {
    float fahrenheit;
    float celsius;
    printf("Fahrenheit\tCelsius\n");
    for(fahrenheit=-20; fahrenheit<=300; fahrenheit=fahrenheit+20) {
        celsius=5*(fahrenheit-32)/9;
        printf("%10.0f\t %6.2f\n", fahrenheit, celsius);
    }
    return 0;
}

//Aufgabe 8
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SPITZE 1
#define GUT 2
#define BEFRIEDIGEND 3
#define AUSREICHEND 4
#define DURCHGEFALLEN 5
#define JA 1
#define NEIN 0

int main(void) {
  unsigned int note, bestanden;
  do
  {
  printf("\nGeben Sie bitte eine Note (1-5) ein: ");
  scanf("%u", &note);
  }while (note<1 || note>5);
  if (note == SPITZE)
    bestanden = JA;
  else if (note == GUT)
    bestanden = JA;
  else if (note == BEFRIEDIGEND)
    bestanden = JA;
  else if (note == AUSREICHEND)
    bestanden = JA;
  else
    bestanden = NEIN;
  bestanden ? printf("\nOK!") : printf("\nNICHT bestanden");
  return 0;
}

//Aufgabe 9
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(int argc, char *argv[]) {
    int n, x=0;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {            
            if (i==0 || j==0 || i==n-1 || j==n-1)
            {
                printf("*");
            }
            else if ((j==x && i==x) || (j==n-(x+1) && i==x))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
        x++;
    }
    return 0;
}