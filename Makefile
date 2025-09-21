# ================================
# Makefile for ROLL_NO-OS-A01 Project
# ================================

# Compiler
CC = gcc

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INC_DIR = include

# Files
TARGET = $(BIN_DIR)/main

# Find all source files (*.c)
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Convert each .c into its corresponding .o inside obj/
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Compiler Flags
CFLAGS = -I$(INC_DIR) -Wall

# Default target
all: $(TARGET)

# Link object files into final executable
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJS) -o $(TARGET)
	@echo "Build successful! Executable created: $(TARGET)"

# Compile each .c file to .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean all compiled files
clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET)
	@echo "Cleanup done!"

# Run the program
run: all
	./$(TARGET)
