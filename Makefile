CROSS_COMPILE ?= gcc

all: super_array_test


super_array_test: super_array.o link_int.o super_array_test.o
	$(CROSS_COMPILE) -o super_array_test.out $^

clean:
	rm -fr *.o *.out


