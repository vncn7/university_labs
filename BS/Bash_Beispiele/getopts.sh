#!/bin/bash

# Example on how ot use getopts to process parameters

# First of all a function definition to show the usage
function usage {
    echo "Usage: $0 [-s <45|90>] [-p <string>]" 1>&2
    exit 1
}


# The parameter to getopts show the show-name (-s) and whether there's
# a parameter to be expected from the option (then available in variable ${OPTARG}
while getopts ":s:p:ex:" o; do
    case "${o}" in
        s)
            sx=${OPTARG}
            # Check whether the value is in bounds
            ((sx == 45 || sx == 90)) || usage
            ;;
        p)
            px=${OPTARG}
            ;;
        x)
            xx=${OPTARG}
            echo "x ist $xx"
            ;;
        e)
            echo "e ist da"
            ;;
        *)
            usage
            ;;
    esac
done
shift $((OPTIND-1))

# If the options are not set, show usage
if [ -z "${sx}" ] || [ -z "${px}" ]; then
	usage
fi

echo "s = ${sx}"
echo "p = ${px}"
echo $extension
echo "${@: -1}"
