# Compiler and flags
CC      := gcc
CFLAGS  := -Wall -Wextra -std=c99
# Raylib flags
LDFLAGS := $(shell pkg-config --libs --cflags raylib)

# Directories
SRC_DIR := src
BUILD_DIR := build

# Find all .c files in src/
SRCS := $(wildcard $(SRC_DIR)/*.c)
# Replace src/ with build/ and .c with .o for object files
OBJS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

# Output executable name
TARGET := the_sim

# Default target
all: $(BUILD_DIR) $(TARGET)

# Link the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# Compile .c to .o, output to build/
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@

# Ensure build/ directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean
