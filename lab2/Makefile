all: main.o vigenere.o
	g++ main.o vigenere.o -O2 -o vigenere

main.o:
	g++ -c main.cpp -O2

vigenere.o:
	g++ -c vigenere.cpp -O2

clean:
	rm *.o
