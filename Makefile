all:
	g++ -I src/include/SDL2 -L src/lib -o main main.cpp Tetris.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image