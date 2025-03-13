CC = gcc
TARGET = termsize

all:$(TARGET)

$(TARGET):termsize.c
	$(CC) -o $(TARGET) termsize.c

clean:$(TARGET)
	rm -f $(TARGET)

run:$(TARGET)
	./$(TARGET)
.PHONY: all
