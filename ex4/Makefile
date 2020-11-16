CC=gcc
BINARY=./bin/ex
SRC= ./src/main.c ./src/merge_sort.c ./src/insertion_sort.c ./src/bubble_sort.c ./src/watch.c ./src/file_manager.c
INCLUDES= ./includes/
OPTIONS=-Wall -g -lm -Werror
TEST=casos/1.in
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
	@valgrind --leak-check=yes $(BINARY) < $(TEST)
fsanitize:
	@$(CC) $(OPTIONS) $(SRC) -fsanitize=address -o $(BINARY) -I$(INCLUDES) -DDEBUG
	@$(BINARY) < $(TEST)
zip:
	@zip -r trab.zip $(SRC) $(INCLUDES) ./bin/ Makefile 'Lab de ICC2 ex4.pdf'
plot:
		gnuplot "plotdata" -p
clean:
	@rm trab.zip
	@rm $(BINARY)
