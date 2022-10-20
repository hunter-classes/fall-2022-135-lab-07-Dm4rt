main: main.o utility.o
	g++ -o main main.o utility.o

main.o: main.cpp utility.h

utility.o: utility.cpp utility.h

clean:
	rm -f main.o utility.o

