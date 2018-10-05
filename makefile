CFLAGS = -O
CC = g++

volimage: volimage.o
	$(CC) $(CFLAGS) -o volimage volimage.o --std=c++11

volimage.o: volimage.h volimage.cpp
	$(CC) $(CFLAGS) -c volimage.cpp --std=c++11

run:
	./volimage

clean:
	rm -f core *.o
