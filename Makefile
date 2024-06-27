CFLAGS =gcc -Werror -Wextra -Wall
V = -std=c11

all: 
	$(CFLAGS) $(V) pong.c -o pong