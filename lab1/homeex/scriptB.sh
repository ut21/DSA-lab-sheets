rm *o
rm *exe
gcc -c setB.c
gcc -c quiz.c
gcc -o setB_exe setB.o quiz.o
./setB_exe