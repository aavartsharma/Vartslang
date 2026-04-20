all: compile

compile:
	gcc -Iinclude main.c src/*.c -o vartslang.out
	ls src/*.c
	echo "compilation compeleted"

