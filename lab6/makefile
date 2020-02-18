exe: driver.o test.o
	gcc -o exe driver.o test.o

test.o: test.c test.h
	gcc -c test.c

driver.o: driver.c test.h
	gcc -c driver.c