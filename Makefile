CC = gcc
CFLAGS = -Wall -Wextra
TEST_LIBS = -lcheck

all: test_selection_sort

selection_sort.o: selection_sort.c selection_sort.h
	$(CC) $(CFLAGS) -c selection_sort.c

test_selection_sort: test_selection_sort.c selection_sort.o
	$(CC) $(CFLAGS) test_selection_sort.c selection_sort.o -o test_selection_sort $(TEST_LIBS)

test: test_selection_sort
	./test_selection_sort
