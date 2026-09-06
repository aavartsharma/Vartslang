all: compile

compile:
	mkdir -p builds
	gcc -Iinclude main.c src/*.c -o builds/vartc
	ls src/*.c
	echo "compilation compeleted"

	
