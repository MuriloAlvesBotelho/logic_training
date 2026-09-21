CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -pedantic
TARGET = estoque.exe
SRCS = main.c produto.c simples.c dupla.c circular.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	del /f /q *.o $(TARGET)