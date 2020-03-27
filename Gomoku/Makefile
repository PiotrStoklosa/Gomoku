gomoku: gomoku.o main.o
	gcc -std=c11 -Wall -Wextra -Werror gomoku.o main.o -o gomoku `pkg-config gtk+-3.0 --libs`

gomoku.o: gomoku.c gomoku.h
	gcc `pkg-config gtk+-3.0 --cflags` -std=c11 -Wall -Wextra -Werror -c gomoku.c -o gomoku.o

main.o: main.c gomoku.h
	gcc `pkg-config gtk+-3.0 --cflags` -std=c11 -Wall -Wextra -Werror -c main.c -o main.o

.PHONY : clean
clean:
	rm gomoku *.o
