GCC = g++
FLAGS = -ansi -pedantic -lpthread

team.out: *.o
	$(GCC) -o team.out *.o $(FLAGS)

*.o: *.cpp *.h
	$(GCC) -c -g  *.cpp $(FLAGS)
	
clean:
	rm -f *.o team.out


