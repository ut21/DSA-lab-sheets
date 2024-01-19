gcc -c cycledetection.c
gcc -c main.c
gcc -o cycle_exe main.o cycledetection.o 
./cycle_exe