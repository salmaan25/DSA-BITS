driver: driver.o cd.o
	gcc driver.o cd.o -o driver

cd.o: cd.c cd.h
	gcc -c cd.c

driver.o: driver.c cd.h
	gcc -c driver.c