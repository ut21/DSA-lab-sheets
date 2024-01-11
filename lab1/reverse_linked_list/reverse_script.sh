gcc -c reverse.c
gcc -c printList.c
gcc -c driver_file.c
gcc -o reverse_my_list reverse.o printList.o driver_file.o
./reverse_my_list