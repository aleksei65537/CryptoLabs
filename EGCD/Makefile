all: EGCD.o main.o
	g++ EGCD.o main.o -o EGCD -O2

EGCD.o:
	g++ -c EGCD.cpp -O2

main.o:
	g++ -c main.cpp -O2

clean:
	rm *.o
