SERVER = server
CLIENT = client

SERVER_C = server.c
CLIENT_C = client.c

SERVER_O = $(server.c=.o)
CLIENT_O = $(client.c=.o)

HDR = ./minitalk.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(SERVER_O) $(CLIENT_O)
	$(MAKE) $(SERVER)
	$(MAKE) $(CLIENT)
%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(SERVER_O) $(CLIENT_O) SERVER CLIENT

re: clean all

.PHONY: all clean re
