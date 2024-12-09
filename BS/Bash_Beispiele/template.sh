#!/bin/sh

#######################################################################
# Template for any Shell Script
# Usage:
#   template.sh [--help]
# The option --help shows the help and exits
#
# Author: Your name, Your affiliation, HS-Esslingen
# Date: Date-of-the-last-edit
#######################################################################

function show_help {
    echo "Usage: template.sh [-h|--help]"
    echo ""
    echo "Some explanation about this script..."
    echo ""
    echo "  -h|--help: Show this help and quit"
    echo "           : all options are explained"
    echo ""
}

# Go through all the parameters passed and check for arguments
# Here WITHOUT getopt or getopts, since we allow long option names (--help)
# Better use getopts (safer for optional parameters...)
while test $# -gt 0 ; do
    case "$1" in
    -h|--help)
        show_help
        exit
        ;;
    esac
    shift
done

# Best practice: set variables in the option parsing, then
# act HERE accordingly... (with proper error checking, e.g. have
# mutually exlusive options been passed, are files available, etc.)

