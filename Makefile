##
## Makefile for make in /home/peau_c/rendu/PSU/PSU_2015_minitalk
##
## Made by Clement Peau
## Login   <peau_c@epitech.net>
##
## Started on  Mon Feb  1 18:03:54 2016 Clement Peau
## Last update Fri Feb 19 17:53:13 2016 Clement Peau
##

CFLAGS=		-I./inc/ -W -Wall -Wextra

SRCBASIC=	basic/putnbr.c \
		basic/strlen.c \
		basic/my_puttable.c \
		basic/my_getnbr.c \

SRCCLIENT=	client/src/main.c \
		client/src/signals.c \

SRCSERVER=	server/src/main.c \

OBJBASIC=	$(SRCBASIC:.c=.o)

OBJCLIENT=	$(SRCCLIENT:.c=.o)

CC=		gcc -g

OBJSERVER=	$(SRCSERVER:.c=.o)

CLIENT=		client

SERVER=		server

main:		obj server client

obj:		$(OBJBASIC)

server:		$(OBJSERVER)
		gcc -o bin1 $(OBJSERVER) $(OBJBASIC)
		mv bin1 server/server

client:		$(OBJCLIENT)
		gcc -o bin2 $(OBJCLIENT) $(OBJBASIC)
		mv bin2 client/client

all:		main

clean:
		rm -rf -r $(OBJSERVER) $(OBJCLIENT) $(OBJBASIC)

fclean:		clean
		rm -rf -r client/client server/server

re:		fclean all
