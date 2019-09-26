gcc -g -o ll linked-list.c
valgrind --leak-check=yes --track-origins=yes ./ll
