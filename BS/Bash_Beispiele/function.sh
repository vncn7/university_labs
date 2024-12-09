#!/bin/bash

function1 () {
	echo "Param1:" $1 " und Param2:" $2
	local myvar=5
	exit
}

# Call function1 with two parameters
function1 abc def

# Variable myvar is local to function1, so empty on the outside
echo "Myvar: " $myvar
