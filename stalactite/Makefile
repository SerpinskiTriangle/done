CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = stalactite
PREFIX = /usr/local
BINDIR = $(PREFIX)/bin

all:$(TARGET)

clean:$(TARGET)
	rm $(TARGET) -f

$(TARGET): stalactite.c
	$(CC) $(CFLAGS) -o $(TARGET) stalactite.c

install: $(TARGET)
	install -Dm755 $(TARGET) $(DESTDIR)$(BINDIR)/$(TARGET)
	@echo "Installed $(TARGET) to $(DESTDIR)$(BINDIR)/"

uninstall:
	rm -f $(DESTDIR)$(BINDIR)/$(TARGET)
	@echo "Uninstalled $(TARGET) from $(DESTDIR)$(BINDIR)/"
