CC=gcc
CFLAGS=-c -Wall

all: unity

unity:
    $(MAKE) -C unity all

clean:
    rm *.o

