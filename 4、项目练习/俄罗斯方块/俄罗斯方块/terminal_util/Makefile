
AR = ar
CC = gcc
PREFIX = .
INCLUDES = -I./src 
LIBS =	-L./lib -L./build 
CFLAGS = -O3 -Wall $(INCLUDES) $(LIBS)
LIB_NAME = terminalutil
OUTPUT = lib$(LIB_NAME).a

SRCS = src/terminal_util.c 

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
clean:
	del .\build\*.a
	del .\src\*.o
	
# del $(PREFIX)\install\lib\$(OUTPUT)
# del $(PREFIX)\install\include\*.h


.PHONY: clean install uninstal



