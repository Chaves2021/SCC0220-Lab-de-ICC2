CC=gcc
BINARY=./bin/ex
SRC= ./src/main.c ./src/searches.c
INCLUDES= ./includes/
OPTIONS=-Wall -g -lm -Werror
TEST=casos/1.in

all:
	@$(CC) $(SRC) -o $(BINARY) -I$(INCLUDES) $(OPTIONS)
run:
	@$(BINARY)
debug:
	@$(CC) $(SRC) -o $(BINARY) -I$(INCLUDES) $(OPTIONS) -DDEBUG
test:
	@$(BINARY) < $(TEST)
valgrind:
	@$(CC) $(OPTIONS) $(SRC) -o $(BINARY) -I$(INCLUDES)
	@valgrind --leak-check=yes $(BINARY) < $(TEST)
fsanitize:
	@$(CC) $(OPTIONS) $(SRC) -fsanitize=address -o $(BINARY)
	@$(BINARY) < $(TEST)
zip:
	@zip -r trab.zip $(SRC) $(INCLUDES) ./bin/ Makefile 'Relatório 2 - Lab de ICC2.pdf'
clean:
	@rm trab.zip
	@rm $(BINARY)
