CFLAGS = -c -Wall -std=c++11 -g
LFLAGS = -Wall -g

all: bollinger

bollinger: main.o Strategy.o Performance.o Data.o
	g++ ${LFLAGS} main.o Strategy.o Performance.o Data.o -o bollinger

main.o: main.cpp Performance.h
	g++ ${CFLAGS} main.cpp -o main.o

Strategy.o: Strategy.cpp Strategy.h
	g++ ${CFLAGS} Strategy.cpp -o Strategy.o

Performance.o: Performance.cpp Performance.h Strategy.o
	g++ ${CFLAGS} Performance.cpp -o Performance.o

Data.o: Data.cpp Data.h
	g++ ${CFLAGS} Data.cpp -o Data.o

clean:
	rm -rf *.o bollinger