AR = ar
CC = gcc
PREFIX = .
INCLUDES = -I./src -I../include
LIBS =	-L../lib -L./build -llist -lterminalutil
CFLAGS = -O3 -w $(INCLUDES) $(LIBS)
LIB_NAME = terminalwindow
OUTPUT = lib$(LIB_NAME).a

SRCS = src/terminal_window.c \
		src/terminal_point.c	\
		src/terminal_block.c	\
		src/terminal_text.c	


OBJS = $(SRCS:.c=.o)

all: build

install: all
	copy  .\build\$(OUTPUT) $(PREFIX)\install\lib
	copy  .\src\*.h $(PREFIX)\install\include

build: $(OBJS)
	$(AR) rcs build/$(OUTPUT) $^

%.o: %.c
	$(CC) $< $(CFLAGS) -c -o $@

test: all
	$(CC) example/test.c  -l$(LIB_NAME) $(CFLAGS) -o test.exe
test2: all
	$(CC) example/test2.c  -l$(LIB_NAME) $(CFLAGS) -o test2.exe
test3: all
	$(CC) example/test3.c  -l$(LIB_NAME) $(CFLAGS) -o test3.exe
test4: all
	$(CC) example/test4.c  -l$(LIB_NAME) $(CFLAGS) -o test4.exe
clean:
	del .\build\*.a
	del .\src\*.o
	
# del $(PREFIX)\install\lib\$(OUTPUT)
# del $(PREFIX)\install\include\*.h


.PHONY: clean install uninstal



