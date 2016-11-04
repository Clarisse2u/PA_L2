Projet_PA:	test.cpp
		g++ *.cpp `sdl-config --cflags --libs` -o test -g


clean:
	rm test
