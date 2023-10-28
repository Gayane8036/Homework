CC = g++
CFLAGS = -Wall

all: copy_bytes

copy_bytes: copy_bytes.cpp
    $(CC) $(CFLAGS) -o copy_bytes copy_bytes.cpp

clean:
    rm -f copy_bytes
