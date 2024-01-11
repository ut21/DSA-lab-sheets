rm *o
rm *exe
gcc -c count_consonants.c
gcc -c master.c
gcc -o run_exe count_consonants.o master.o
./run_exe