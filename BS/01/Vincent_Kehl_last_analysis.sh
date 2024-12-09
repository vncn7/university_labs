#!/bin/bash					

#################################################
# Solution "Labor 1 Betriebssysteme" # SS23 TIB	#
#################################################
# Usage:					#
# last_analysis.sh				#
# 	-h, --help:	Show help		#
# 	-r, --runtime:	Show uptime of reboots	#
# 	-u, --user:	Show number of logins	#
#################################################
# Authors: Güney Öszcan, Vincent Kehl		#
# Tested on: Ubuntu 22.04.2; Fedora 37		#
#################################################	

function show_help {
    	echo "Usage: last_analysis.sh [-h|--help] [-r|--runtime] [-u|--user]"
	echo "Display system uptime and login information."
	echo ""
    	echo "Options:"
    	echo "  -r,--runtime: Displays the uptime of reboots"
    	echo "  -u,--user: Displays the number of logins"
    	echo "  -h,--help: Displays this help message"
    	echo ""
}

# Default-Option
option="runtime" 

# Abfrage der Parameter
while [[ $# -gt 0 ]]; do
	case "$1" in
	-h|--help)
		show_help
		exit
		;;
	-r|--runtime)
		option="runtime"
		;;
	-u|--user)
		option="user"
		;;
	esac
	shift
done

# RUNTIME
if [[ $option == "runtime" ]]; then
	# Speichern der Ausgabe in einer Textdatei
	last | grep -E '^reboot' | cut -c 23- > tmp 
	# Ausgabe der ersten Zeile, Auschneiden des Kernsels und "still running", 1. und 9.- Spalte, Leerzeichen als Trenner
	grep 'still running' tmp | cut -d ' ' -f 1,8-
	
	# Start der While-Schleife
	while read line; do 
		# Speichere das erste Feld 'KErnel' in Variable
    		kernel=$(echo $line | awk '{print $1}') 
		# Berechnung und Speicherung der Zeit in Tagen
				# Zeit wird extrahiert und in der Variabel time gespeichert, hierzu wird die Länge des Strings auf 2-2 gesetzt um die Klammern zu entfernen.
				# Variabel time wird an dem Symbol ":" in ein Array zerlegt und dann separat in die Varabeln hour und minute gespeichert und besser damit rechnen zu können.
				# Berechnung und Ausgabe mit Speicherung in der Variablen days.
   		days=$(echo $line | awk '{ 
        		time = substr($NF, 2, length($NF)-2) 	
        		split(time, array, ":")
        			hour = array[1]
        			minute = array[2]
        			total_minutes = hour * 60 + minute
        			days = int(total_minutes / (60*24))
        			printf("%d days", days)}') 
		# Ausgabe der Variabel Kernel und der Variabel days. Anschließendes Ende des Schleife
		echo "$kernel $days"; done < tmp
fi

# USER
if [[ $option == "user" ]]; then
    	# Speichern der User in einer TMP-Datei
	last | grep -v 'reboot' | grep -v 'wtmp' | sort -u > tmp

    	# Zählen und Ausgeben der Anzahl von Logins pro User
    	for user in $(awk '{print $1}' tmp | sort -u); do
    		count=$(grep -c $user tmp) 
    		echo "$count $user"; done < tmp 
fi
# Löschen der TMP-Datei
rm tmp
exit 


