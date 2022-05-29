
#########################
# DO NOT EDIT THIS FILE #
#########################

# But please, feel free to inspect the targets and design for your own learning.

#
CC := g++
CFLAGS := -Wall -pedantic -g -c -std=c++17
LINKFLAGS := -Wall -pedantic -g -std=c++17


#
BIN_NAME := main
BIN := ./$(BIN_NAME)


#
default:	help


#
help:
	@echo "***** Makefile Menu *****"
	@echo
	@echo "make build         ==> Build source files"
	@echo
	@echo "make run           ==> Run the hash table tui"


#
build:	$(BIN)
.PHONY: build


#
run:	$(BIN)
		$(BIN)
.PHONY: run


#
$(BIN):	main.o Item.o SnackBar.o
	$(CC) $(LINKFLAGS) $^ -o $@


#
main.o:	main.cpp
	$(CC) $(CFLAGS) $< -o $@


#
SnackBar.o: SnackBar.cpp
	$(CC) $(CFLAGS) $< -o $@


#
Item.o:	Item.cpp 
	$(CC) $(CFLAGS) $< -o $@


#
clean:
	-rm *.o
	-rm $(BIN)
.PHONY: clean