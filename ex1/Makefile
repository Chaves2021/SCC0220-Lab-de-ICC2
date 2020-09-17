CC=gcc
BINARY=./bin/ex
SRC= ./src/main.c ./src/file_manager.c ./src/watch.c ./src/array.c
INCLUDES= ./includes/
OPTIONS=-Wall -g #-Werror
TEST=teste.in
FILENAME=./casos/data/numberlist5000.dat

all:
	@$(CC) $(SRC) -o $(BINARY) -I$(INCLUDES) $(OPTIONS)
run:
	@$(BINARY) $(FILENAME)
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
	@zip -r trab.zip $(SRC) Makefile
clean:
	@rm trab.zip
	@rm $(BINARY)
