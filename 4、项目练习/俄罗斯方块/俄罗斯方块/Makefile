
AR = ar
CC = gcc
PREFIX = .
INCLUDES = -I./include  
LIBS =	-L./lib -lterminalwindow -lterminalutil  -lpthread -llist -lwinmm -lgame
CFLAGS = -O3 -w $(INCLUDES) $(LIBS)

SRCS = main.c

OBJS = $(SRCS:.c=.o)

all: 
	$(CC) main.c -lgame $(CFLAGS) -o main.exe 
