# Compiler
CC = g++
CFLAGS = -Iinclude -g

# Folders
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
BIN_DIR = bin

# Files 
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))
EXEC = $(BIN_DIR)/program

# Linker Flags
LDFLAGS = -lncurses

# Body
all: $(EXEC)

$(EXEC): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC) $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean project
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

