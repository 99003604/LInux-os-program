all: assignment2Gpipe assignment2Gpipe1 assignment2Gpipe2

assignment2Gpipe: assignment2Gpipe.c sol2g.h
	gcc -o assignment2Gpipe.out assignment2Gpipe.c -lrt
	
assignment2Gpipe1: assignment2Gpipe1.c sol2g.h
	gcc -o assignment2Gpipe1.out assignment2Gpipe1.c -lrt

assignment2Gpipe2: assignment2Gpipe2.c sol2g.h
	gcc -o assignment2Gpipe2.out assignment2Gpipe2.c -lrt
	
runassignment2Gpipe:
	./assignment2Gpipe.out

runassignment2Gpipe1:
	./assignment2Gpipe1.out

runassignment2Gpipe2:
	./assignment2Gpipe2.out

clean:
	rm -rf *.out *.o