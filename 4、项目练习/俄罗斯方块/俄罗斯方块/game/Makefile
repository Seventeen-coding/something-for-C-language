
AR = ar
CC = gcc
PREFIX = .
INCLUDES = -I../include -I./src \
			-I./src/display -I./src/data \
			-I./src/config -I./src/util
LIBS =	-L../lib -L./build  -lterminalwindow -lterminalutil  -lpthread -llist -lwinmm
CFLAGS = -O3 -w $(INCLUDES) $(LIBS)
OUTPUT = libgame.a

SRCS = src/game.c \
		src/util/game_util.c	\
		src/display/game_block.c	\
		src/display/game_info_area.c \
		src/display/game_play_area.c \
		src/display/game_background.c	\
		src/data/game_block_data.c	\
		src/config/game_config.c

OBJS = $(SRCS:.c=.o)

all: build

install: all
	copy  .\build\$(OUTPUT) $(PREFIX)\install\lib
	copy  .\src\*.h $(PREFIX)\install\include
	copy  .\src\util\*.h $(PREFIX)\install\include
	copy  .\src\display\*.h $(PREFIX)\install\include
	copy  .\src\data\*.h $(PREFIX)\install\include
	copy  .\src\config\*.h $(PREFIX)\install\include
build: $(OBJS)
	$(AR) rcs build/$(OUTPUT) $^

%.o: %.c
	$(CC) $< $(CFLAGS) -c -o $@

example_test_key_monitor: all
	$(CC) example/test_key_monitor.c -lgame $(CFLAGS) -o test.exe -
test: all
	$(CC) example/test.c -lgame $(CFLAGS) -o test.exe 
test2: all
	$(CC) example/test2.c -lgame $(CFLAGS) -o test2.exe 
test3: all
	$(CC) example/test3.c -lgame $(CFLAGS) -o test3.exe 
test4: all
	$(CC) example/test4.c -lgame $(CFLAGS) -o test4.exe 
clean:
	del .\build\*.a
	del .\src\*.o
	del .\src\util\*.o
# del $(PREFIX)\install\lib\$(OUTPUT)
# del $(PREFIX)\install\include\*.h


.PHONY: clean install uninstall
