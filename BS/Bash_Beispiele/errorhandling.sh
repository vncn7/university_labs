#!/bin/bash

# Abbrechen, wenn ein Fehler auftritt
# set -e

# Fehler auch im nicht letzten Glied der Pipe berücksichtigen
# set -o pipefail

# Dieses Kommando schlägt fekl
cd michgibtsnicht

echo "hier gehts weiter"

# Bei Pipes entscheidet das letzte Glied, ob es einen Fehler gab
# cd michgibtsnicht | echo 

# Fehlerausgaben können auch in andere Dateien umgeleitet werden
# cd michgibtsnicht 2> error.txt

# Fehlermeldungen können auch auf die Standardausgabe umgeleitet werden
# ls /bla > ls.txt 2>&1
# Kanäle: 0: Eingabe, 1: Ausgabe, 2: Fehler

echo "Rueckgabe: $?"

# $? geht schnell verloren! --> besser den Wert sichern 
err=$?

if [ "$err" !=  "0" ] ; then
	echo "ein Fehler ist aufgetreten $? <--> $err" 1>&2
fi


# Alternative zur nachträglichen Fehlerbehandlung durch $0
# ist das gleich in einer if-Auswertung einzubetten:

if cd michgibtsnicht; then
  echo "hier sollten wir gar nicht hin kommen"
else
  echo "Wechsel des Verzeichnisses nicht erfolgreich" 1>&2
  exit 1
fi
# Ob dies aber lesbarer ist, ist zu bezweifeln!

echo "alles bestens"
