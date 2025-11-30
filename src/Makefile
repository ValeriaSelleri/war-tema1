CC = gcc
CFLAGS = -Wall -Wextra -std=c11
SRC = main.c paises.c jogadores.c
OBJ = $(SRC:.c=.o)
TARGET = war

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

clean:
	rm -f $(OBJ) $(TARGET)
