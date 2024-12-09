//Aufgabe 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char* argv[]) {
    int i1, i2, i3;
    scanf("%d %d %d", &i1, &i2, &i3);
    printf("Ganze Zahlen: %d, %d, %d \n", i1, i2, i3);

    float f;
    scanf("%f", &f);
    printf("Fliesskommazahl mit Formatangabe: %.2f \n", f);

    char s[100];
    scanf("%s", s);
    printf("Zeichenkette: %s \n", s);
    return 0;
}

//Aufgabe 2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(int argc, char *argv[])
{
    float fahrenheit;
    scanf("%f", &fahrenheit);
    printf("%.1f Grad Fahrenheit = %.1f Grad Celsius", fahrenheit, (5*(fahrenheit -32))/9);
    return 0;
}

//Aufgabe 3
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
    int masse, groesse;
    float bmi;
    scanf("%i %i", &masse, &groesse);
    bmi = (masse*0.001)/(pow((groesse*0.01), 2));
    printf("Der BMI liegt bei: %.2f!", bmi);
    return 0;
}

//Aufgabe 4
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
    int masse, groesse;
    float bmi;
    scanf("%i %i", &masse, &groesse);
    bmi = (masse*0.001)/(pow((groesse*0.01), 2));
    if(bmi < 18.4) {
        printf ("Untergewicht %.1f", bmi);
    }
    if(18.4 < bmi && bmi < 24.9) {
        printf ("Normalgewicht %.1f", bmi);
    }
    if(bmi >= 24.9) {
        printf ("Uebergewicht %.1f", bmi);
    }
    return 0;
}

//Aufgabe 5
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{   
    char x;
    int m, V;
    float r, e, phi = 0.8, w;

    scanf("%s %d %d %f", &x, &m, &V, &e);
    if (x == 'm')
    {
        r = 0.7;
    }
    else if (x == 'w')
    {
        r = 0.6;
    }
    else if (x == 'k')
    {
        r = 0.8;
    }
    w = (V*(e/100)*phi)/(m*r);
    printf("%0.2f Promille", w);
    return 0;
}

//Aufgabe 6
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
  printf("Geben Sie bitte eine Note (1-5) ein: ");
  scanf("%u", &note);

    switch (note)
    {
      case SPITZE:
      case GUT:
      case BEFRIEDIGEND:
      case AUSREICHEND:
        bestanden = JA;
        break;
    default:
        bestanden = NEIN;
    }
  bestanden ? printf("\nOK!") :  printf("\nNICHT bestanden");
  return 0;
}

