# GREB
Greb is a Command-Line Tool for searching text within text files. It is inspired by GREP

# Highlights
Recursive - Greb is able to search recursively through large directories
Fast - Greb can search quickly through many files
Portable - Greb has no external dependencies


# Installation
git clone https://github.com/thompsonslee/GREB
cd GREB && sudo ./build.sh

# Instructions
The standard format for greb is: grep [options][string][file_path]

You can modify grep's behaviour by using these flags
-r: Recursive search(search through all files in a subdirectory)
-n: Show line numbers alongside matches
-t: Display the time it took for the command to finish
