all: super_array.o link_int.o main.o
	gcc -o main.out main.o link_int.o super_array.o
clean:
	rm -fr *.o *.out
