#include<stdio.h>
/*
=============================== 
|           1. Main-Funktion  | 
=============================== 
*/
int main(int argc, char *argv[]) 
{
    int pos_x = 0; // X-Koordinate
    int pos_y = 0; // Y-Koordinate
    char status; // Abbruchvariabel für das Einlesen; a = alive
    int n; // Anzahl der Generationen
    int grid_size = 20; // Große des Spielfelds
    int grid_new_gen[21][21]; // Spielfeld der Folgegenerationen 
    int grid_old_gen [21][21] = { // Spielfeld für aktuelle Generation; 0 = tote Zellen; 1 = lebende Zellen
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},};

/*
=============================== 
|       2. Eingabe der Werte  | 
=============================== 
*/
    scanf("%d", &n); // Einlesen Anzahl Generationen
    do
    {
        scanf("%c %d %d", &status, &pos_x, &pos_y); // Einlesen der Koordinaten einer lebenden Zelle
        if (status == 'a')
        {
            grid_old_gen[pos_x][pos_y] = 1; // Erzeugung einer lebenden Zelle auf dem Spielfeld
        }
    } while (status != 'e'); // Abbruchbedingung der Eingabe bei dem Buchstaben "e"

/*
=============================== 
|  3. Ausgabe des Spielfelds  | 
=============================== 
*/
    for (int i = 0; i <= n; i++) // Haupt-Schleife für die Anzahl der eingegebenen Generationen
    {
        printf("-- Generation: %d\n", i);
        for (pos_y = 0; pos_y < grid_size; pos_y++) // Schleife für Y-Koordinate
        {
            for (pos_x = 0; pos_x < grid_size; pos_x++) // Schleife für X-Koordinate
            {
                if (grid_old_gen[pos_x][pos_y] == 1) // Abfrage ob eine lebendige Zelle existiert
                {
                    printf("#"); // Ausgabe der lebenden Zellen mit dem char "#"
                }
                else
                {
                    printf("."); // Ausgabe der toten Zellen mit dem char "."
                }
            }
            printf("\n");
        }

/*
=============================== 
|  4. Funktion Zellencounter  |  
=============================== 
*/ 
    int count_cells(int x, int y)
        {
            return grid_old_gen[x+1][y+1] + grid_old_gen[x+1][y] + grid_old_gen[x+1][y-1] + grid_old_gen[x][y+1] + grid_old_gen[x][y-1] + grid_old_gen[x-1][y+1] + grid_old_gen[x-1][y] + grid_old_gen[x-1][y-1]; // Zählen, Summieren und anschließende Rückgabe der Anzahl der lebendigen Nachbarzellen 
        }

/*
=============================== 
|             5. Spielregeln  | 
=============================== 
*/
        for (pos_y = 0; pos_y < grid_size; pos_y++) // Schleife für Y-Koordinate
        {
            for (pos_x = 0; pos_x < grid_size; pos_x++) // Schleife für X-Koordinate
            {
                if (grid_old_gen[pos_x][pos_y] == 0) // Abfrage für tote Zellen
                {
                    if (count_cells(pos_x, pos_y) == 3) // Regel 1: Eine tote Zelle mit genau drei lebenden Nachbarn wird in der Folgegeneration „geboren“
                    {
                        grid_new_gen[pos_x][pos_y] = 1; // Generieren der neuen lebenden Zelle auf dem Spielfeld der Folgegeneration
                    }
                    else
                    {
                        grid_new_gen[pos_x][pos_y] = 0; // Generieren der restlichen toten Zellen auf dem Spielfeld der Folgegenertion
                    }  
                }
                else if (grid_old_gen[pos_x][pos_y] == 1) // Abfrage für lebende Zellen
                {
                    if (count_cells(pos_x, pos_y) < 2 || count_cells(pos_x, pos_y) > 3) // Regel 2 und 3: Eine lebende Zelle mit weniger als zwei lebenden Nachbarn stirbt in der Folgegeneration (an Einsamkeit). Eine lebende Zelle mit mehr als drei lebenden Nachbarn stirbt in der Folgegeneration (an Überbevölkerung).
                    {
                        grid_new_gen[pos_x][pos_y] = 0; // Generieren der neuen toten Zelle auf dem Spielfeld der Folgegeneration
                    }
                    else if (count_cells(pos_x, pos_y) == 2 || (count_cells(pos_x, pos_y) == 3)) // Regel 4: Eine lebende Zelle mit zwei oder drei lebenden Nachbarn bleibt in der Folgegeneration am Leben.
                    {
                        grid_new_gen[pos_x][pos_y] = 1; // Generieren der neuen lebenden Zelle auf dem Spielfeld der Folgegeneration
                    }
                }
            }
        }
/*
=============================== 
|     6. Generationenwechsel  | 
=============================== 
*/
        for (pos_y = 0; pos_y < grid_size; pos_y++) // Schleife für Y-Koordinate
        {
            for (pos_x = 0; pos_x < grid_size; pos_x++) // Schleife für X-Koordinate
            {
                grid_old_gen[pos_x][pos_y] = grid_new_gen[pos_x][pos_y]; // Das alte Spielfeld wird von dem der neuen Generation überschrieben, das Programm springt danach wieder zum Start der Haupt-Schleife und gibt das Spielfeld auf der Konsole aus
            }
        }
    } // Ende der Hauptschleife (finally)
    return 0;
} // Ende der Main-Funktion
