# Makefile for ccfat
PREFIX ?= /usr/local

all: ccfat

ccfat: ccfat.cpp
	g++ -o ccfat ccfat.cpp

install: ccfat
	install -Dm755 ccfat $(DESTDIR)$(PREFIX)/bin/ccfat

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/ccfat

clean:
	rm -f ccfat

.PHONY: all install uninstall clean
