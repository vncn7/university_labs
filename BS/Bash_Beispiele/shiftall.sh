#!/bin/bash

if [ $# -lt 1 ]; then
	echo "Usage: $0 requires at least one parameter";
	exit 1
fi

echo "Args : $* ($#)"
shift $(($#-1)) 
echo "Letztes Argument: $1"
