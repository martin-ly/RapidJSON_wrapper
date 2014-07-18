it: rapidJSON_wrapper.o
	gcc -o rapidJSON_wrapper rapidJSON_wrapper.o

clean: rapidJSON_wrapper.o
	rm *.o rapidJSON_wrapper