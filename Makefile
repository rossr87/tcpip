target: testapp.exe

testapp.exe: testapp.o graph.o
	gcc testapp.o graph.o -o testapp.exe

testapp.o: testapp.c
	gcc -c testapp.c -o testapp.o

graph.o: graph.c
	gcc -c graph.c -o graph.o
