vowel : count_vowels_exe
	./count_vowels_exe
count_vowels_exe : count_vowels.o master.o
	gcc -o count_vowels_exe count_vowels.o master.o
count_vowels.o : count_vowels.c
	gcc -c count_vowels.c
master.o : master.c
	gcc -c master.c
clean :
	rm -f *.o
	rm count_vowels_exe
