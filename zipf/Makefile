CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = zipf
PREFIX = /usr/local
BINDIR = $(PREFIX)/bin

all:$(TARGET)

clean:$(TARGET)
	rm $(TARGET) -f

$(TARGET): zipf.c sort.c
	$(CC) $(CFLAGS) -o $(TARGET) zipf.c sort.c

install: $(TARGET)
	install -Dm755 $(TARGET) $(DESTDIR)$(BINDIR)/$(TARGET)
	@echo "Installed $(TARGET) to $(DESTDIR)$(BINDIR)/"
	rm $(TARGET) -f	

uninstall:
	rm -f $(DESTDIR)$(BINDIR)/$(TARGET)
	@echo "Uninstalled $(TARGET) from $(DESTDIR)$(BINDIR)/"
