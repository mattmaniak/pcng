APPNAME=pcng
CC=g++
CFLAGS=-Wall -Wextra
SRCDIR=src
STD=c++11

all:
	$(CC) $(CFLAGS) -std=$(STD) $(SRCDIR)/$(APPNAME).cpp -o $(APPNAME).app
