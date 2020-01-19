

AR = ar
CC = gcc
PREFIX = .
INCLUDES = -I./include
LIBS =	-L./lib
CFLAGS = -O3 -Wall $(INCLUDES) $(LIBS)
OUTPUT = liblist.a

SRCS = src/list.c 

OBJS = $(SRCS:.c=.o)

all: build

install: all
	copy  .\build\$(OUTPUT) $(PREFIX)\install\lib
	copy  .\src\*.h $(PREFIX)\install\include

build: $(OBJS)
	$(AR) rcs build/$(OUTPUT) $^

%.o: %.c
	$(CC) $< $(CFLAGS) -c -o $@

clean:
	del .\build\*.a
	del .\src\*.o
	
# del $(PREFIX)\install\lib\$(OUTPUT)
# del $(PREFIX)\install\include\*.h


.PHONY: clean install uninstall
