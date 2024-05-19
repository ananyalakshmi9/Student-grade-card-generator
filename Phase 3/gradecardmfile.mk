a.exe:main.o student.o
	gcc main.c student.c 
main.o:main.c student.h
	gcc -c main.c 
student.o:student.c student.h
	gcc -c student.c 
