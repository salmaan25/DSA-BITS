all:graph.o extras.o driver.o
	gcc driver.o graph.o extras.o -o p2 -g

driver.o: driver.c 
	gcc -c driver.c -g
	
graph.o: graph.c graph.h
	gcc -c graph.c -g

extras.o: extras.c extras.h
	gcc -c extras.c -g
clean:
	rm -f extras.o graph.o driver.o
