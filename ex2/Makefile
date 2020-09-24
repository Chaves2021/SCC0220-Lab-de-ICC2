CC=gcc
BINARY=./bin/ex
SRC= ./src/main.c ./src/searches.c
INCLUDES= ./includes/
OPTIONS=-Wall -g #-Werror
TEST=teste.in

all:
	@$(CC) $(SRC) -o $(BINARY) -I$(INCLUDES) $(OPTIONS)
run:
	@$(BINARY)
debug:
	@$(CC) $(SRC) -o $(BINARY) -I$(INCLUDES) $(OPTIONS) -DDEBUG
test:
	@$(BINARY) < $(TEST)
valgrind:
	@$(CC) $(OPTIONS) $(SRC) -o $(BINARY)
	@valgrind --leak-check=yes $(BINARY)
fsanitize:
	@$(CC) $(OPTIONS) $(SRC) -fsanitize=address -o $(BINARY)
	@$(BINARY) < $(TEST)
zip:
	@zip -r trab.zip $(SRC) $(INCLUDES) ./bin/ Makefile 
clean:
	@rm trab.zip
	@rm $(BINARY)
