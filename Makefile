194xmake: src/194x.cpp
	g++ -o 194x src/*.cpp `sdl2-config --cflags --libs` -lSDL2_image -lSDL2_mixer

clean:
	rm -f 194x
