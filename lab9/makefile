driver: driver.o hash.o
	gcc driver.o hash.o -o driver

hash.o: hash.c hash.h
	gcc -c hash.c

driver.o: driver.c hash.h
	gcc -c driver.c