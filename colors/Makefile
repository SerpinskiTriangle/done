CC = gcc
TARGET = colors
CFLAGS = -lm

all:$(TARGET)

$(TARGET):colors.c
	$(CC) -o  $(TARGET) colors.c $(CFLAGS)

clean:$(TARGET)
	rm -f $(TARGET)

run:$(TARGET)
	./$(TARGET)
.PHONY: all
