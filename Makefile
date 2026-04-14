all: compile

compile:
	gcc main.c src/*.c -o vartslang
	ls src/*.c
	echo "compilation compeleted"

