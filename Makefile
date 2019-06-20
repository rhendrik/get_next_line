COMPILE = gcc -Wall -Werror -Wextra -o exe
SRC = $(wildcard *.c)

comp:
	$(COMPILE) $(SRC) libft.a

tidy:
	rm -rf exe

compm: tidy
	$(COMPILE) $(SRC) libft.a
