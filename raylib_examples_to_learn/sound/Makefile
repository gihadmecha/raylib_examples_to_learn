
executable_file = sound
c_file = /home/gihad/Documents/examples_to_learn/sound/sound.c
raylib_directory = /home/gihad/Documents/installed_libraries

all:
	gcc -o $(executable_file) $(c_file) -Wall -std=c99 -D_DEFAULT_SOURCE -Wno-missing-braces -s -O1 -D_DEFAULT_SOURCE -I/usr/local/include -isystem. -isystem$(raylib_directory)/raylib/src -isystem$(raylib_directory)/raylib/release/include -isystem$(raylib_directory)/raylib/src/external -L. -L/usr/local/lib -L$(raylib_directory)/raylib/src -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -DPLATFORM_DESKTOP

	
	./$(executable_file)
	rm $(executable_file)


