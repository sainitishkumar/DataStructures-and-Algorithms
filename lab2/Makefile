output: sort.o isort.o ssort.o qsort.o
	g++ -o sort sort.o isort.o ssort.o qsort.o 

sort.o:sort.cpp
	g++ -c sort.cpp

isort.o:isort.cpp
	g++ -c isort.cpp

ssort.o:ssort.cpp
	g++ -c ssort.cpp

qsort.o:qsort.cpp
	g++ -c qsort.cpp
	
clean:
	rm *.o sort