CROSS_COMPILE ?= gcc
all: super_array.o link_int.o main.o
	$(CROSS_COMPILE) -o main.out $^
clean:
	rm -fr *.o *.out
