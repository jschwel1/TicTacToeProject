build : main.c ttt.h ttt.c AI.h AI.c
	gcc -g -Wall -o ttt main.c ttt.c AI.c
run : build
	./ttt
clean : build
	-rm ./ttt
