CFLAGS = -Wall -Wextra -Werror -std=c11

EXE = game

rebuild: clean all

all:
	gcc ${CFLAGS} -o ${EXE} game_of_life.c main.c -lncurses -I .

clean:
	rm -rf a.out game