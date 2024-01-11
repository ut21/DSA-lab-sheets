rm *o
rm *exe
gcc -c setC.c
gcc -c quiz.c
gcc -o setC_exe setC.o quiz.o
./setC_exe