gcc -c count_vowels.c
gcc -c master.c
gcc -o main count_vowels.o master.o
./main