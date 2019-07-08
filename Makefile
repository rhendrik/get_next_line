COMPILE = gcc -Wall -Werror -Wextra -g -o 
SRC = $(wildcard *.c)

comp:
	$(COMPILE) $(SRC) libft.a

tidy:
	rm -rf exe

compm: tidy
	$(COMPILE) $(SRC) libft.a
