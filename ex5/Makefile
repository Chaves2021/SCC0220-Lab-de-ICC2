UTIL=Moves.c pokebox.c PokeDex.c pokemon.c poketype.c savemanager.c SpriteManager.c util.c
MAIN=main.c
BINARY=pokemon

all:
	gcc -Wall -g $(MAIN) $(UTIL) -o $(BINARY)

run:
	./$(BINARY)

debug:
	gcc -DDEBUG -Wall $(MAIN) $(UTIL) -o $(BINARY)

valgrind:
	#valgrind --tool=memcheck --leak-check=yes  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)
	valgrind --leak-check=yes ./$(BINARY)

clean:
	@rm *.o

zip:
	zip -r trab.zip *.c *.h data Makefile
