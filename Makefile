all: rapidJSON_wrapper.o
	g++ -c rapidJSON_interface.cpp
	gcc -c rapidJSON_wrapper.c
	g++ -o rapidJSON_wrapper rapidJSON_wrapper.o rapidJSON_interface.o

clean: rapidJSON_wrapper.o
	rm *.o rapidJSON_wrapper
