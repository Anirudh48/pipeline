ABC.exe : main.o fact.o oddeven.o sumof2no.o
	gcc -o ABC.exe main.o fact.o oddeven.o sumof2no.o
main.o : main.c
	gcc -c main.c
fact.o : fact.c
	gcc -c fact.c
oddeven.o : oddeven.c
	gcc -c oddeven.c
sumof2no.o : sumof2no.c
	gcc -c sumof2no.c
.PHONY : clean 
clean : 
	rm -rf *.o
