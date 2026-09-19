# Makefile for Movie Studio Optimization System
# Author: Mohammad Razin Masud

CC      = gcc
CFLAGS  = -Wall -Wextra -std=c99 -O2
TARGET  = movie_studio_optimizer
SRC     = movie_studio_optimizer.c

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) *.o

# Help message
help:
	@echo "Available targets:"
	@echo "  make        - Compile the program"
	@echo "  make run    - Compile and run the program"
	@echo "  make clean  - Remove compiled binary"
	@echo "  make help   - Show this help"
