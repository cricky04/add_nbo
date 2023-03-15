#Makefile
all: app

app: main.o
	gcc -o app main.o

main.o: main.c
	gcc -c -o main.o main.c

clean:
	rm -f *.o