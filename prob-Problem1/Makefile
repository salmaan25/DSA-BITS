all:tree.o extras.o driver.o
	gcc driver.o tree.o extras.o -o p1 -g

tree.o: tree.h tree.c
	gcc -c tree.c -g

extras.o: extras.h extras.c
	gcc -c extras.c -g

driver.o: driver.c
	gcc -c driver.c -g

clean:
	rm -f extras.o tree.o driver.o
