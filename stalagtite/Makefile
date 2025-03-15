CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = stalagtite
PREFIX = /usr/local
BINDIR = $(PREFIX)/bin

all:$(TARGET)

clean:$(TARGET)
	rm $(TARGET)

$(TARGET): stalagtite.c
	$(CC) $(CFLAGS) -o $(TARGET) stalagtite.c

install: $(TARGET)
	install -Dm755 $(TARGET) $(DESTDIR)$(BINDIR)/$(TARGET)
	@echo "Installed $(TARGET) to $(DESTDIR)$(BINDIR)/"

uninstall:
	rm -f $(DESTDIR)$(BINDIR)/$(TARGET)
	@echo "Uninstalled $(TARGET) from $(DESTDIR)$(BINDIR)/"
