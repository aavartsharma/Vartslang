all: compile

compile:
	gcc main.c src/*.c -o vartslang.out
	ls src/*.c
	echo "compilation compeleted"

