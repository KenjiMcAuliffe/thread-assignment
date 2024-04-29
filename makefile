CC=gcc
CFLAGS=-Iinclude -Wall -g
LDFLAGS=
EXEC=mssv

# Directories
SRC_DIR=src
INC_DIR=include
OBJ_DIR=obj
BIN_DIR=bin

# Final binary
TARGET=$(BIN_DIR)/$(EXEC)

# Automatically find all source files and corresponding object files
SRCS=$(wildcard $(SRC_DIR)/*.c)
OBJS=$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Default target
all: $(TARGET)

# Linking the target binary
$(TARGET): $(OBJS)
	mkdir -p $(BIN_DIR)
	$(CC) $(LDFLAGS) -o $@ $^

# Compiling source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -rf $(BIN_DIR) $(OBJ_DIR)

# Declare non-file targets
.PHONY: all clean
