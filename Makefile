rijndael: rijndael.o
	g++ -std=c++14 -g -Wall -o rijndael rijndael.o

rijndael.o: rijndael.cc
	g++ -c rijndael.cc

debug:
	g++ -std=c++14 -g3 rijndael.cc -o rijndael_debug

clean:
	rm *.o rijndael rijndael_debug