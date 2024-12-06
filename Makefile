.SILENT:

# Compiler and Flags 
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIRS)

# Library-specific settings
LIB_NAME = libMathLib.a
LIB_DIR = bin/lib
LIB_SRC = src/*.c
LIB_OBJ = $(LIB_SRC:.c=.o)

# Include directories for the library
INCLUDE_DIRS = bin/include

# Test program settings
TEST_NAME = bin/test
TEST_SRC = test/main.c 
TEST_OBJ = $(TEST_SRC:.c=.o)

# Default target
all: $(LIB_DIR)/$(LIB_NAME) $(TEST_NAME)

# Rule to build the static library
$(LIB_DIR)/$(LIB_NAME): $(LIB_OBJ)
	mkdir -p $(INCLUDE_DIRS)            # Ensure include directory exists
	cp src/MathLib.h $(INCLUDE_DIRS)    # Copy header files to include directory
	mkdir -p $(LIB_DIR)                 # Ensure library directory exists
	ar rcs $@ $^                 		# Create static library from object files
	echo "Static library created: $@"

# Rule to build the test program
$(TEST_NAME): $(TEST_OBJ) $(LIB_DIR)/$(LIB_NAME)
	$(CC) $(CFLAGS) -o $@ $< -L$(LIB_DIR) -l$(LIB_NAME:lib%.a=%)
	echo "Test program created: $@"

# Compile library source files into object files
$(LIB_OBJ): $(LIB_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile test program source files into object files
$(TEST_OBJ): $(TEST_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up only object files
clean_obj:
	rm -f $(LIB_OBJ) $(TEST_OBJ)
	echo "Object files removed"

# Clean up
clean:
	rm -f $(LIB_OBJ) $(TEST_OBJ) $(LIB_DIR)/$(LIB_NAME) $(TEST_NAME) $(INCLUDE_DIRS)/*
	echo "Cleaned up"

# Run the test program
run: $(TEST_NAME)
	./$(TEST_NAME)