all: assignment2Eser assignment2Ecli

assignment2Eser: assignment2Eser.c sol2e.h
	gcc -o assignment2Eser.out assignment2Eser.c -lrt
	
assignment2Ecli: assignment2Ecli.c sol2e.h
	gcc -o assignment2Ecli.out assignment2Ecli.c -lrt
	
runassignment2Ecli:
	./assignment2Ecli.out

runassignment2Eser:
	./assignment2Eser.out

clean:
	rm -rf *.out *.o