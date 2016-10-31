build : main.c ttt.h ttt.c
	gcc -g -Wall -o ttt main.c 
run : build
	./ttt
clean : build
	-rm ./ttt
