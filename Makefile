all: compile

compile:
	gcc -Iinclude main.c src/*.c -o vartc
	ls src/*.c
	echo "compilation compeleted"

