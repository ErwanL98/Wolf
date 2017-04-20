# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/19 12:54:42 by ele-cren          #+#    #+#              #
#    Updated: 2017/04/20 14:39:41 by ele-cren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = wolf3d

SRC = src/calc.c src/main.c src/draw.c src/check.c src/error.c src/event.c \
	  src/init.c src/menu.c src/sdl.c src/initbase.c src/event2.c src/free.c

OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))

FLAGS = -I /tmp/SDL2/ttf/include/SDL2 -I ./SDL2/SDL2/include -I ./libft/include\
		-I ./include

SDLFLAGS = `sdl2-config --cflags --libs`

LIBS = -L./libft -lft -L/tmp/SDL2/ttf/lib -lSDL2_ttf -L./SDL2/SDL2/build \
	   -lSDL2 -lSDL2main

.SILENT :

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft/
	$(CC) $(OBJ) -o $(NAME) $(LIBS) $(SDLFLAGS) $(SDLLIBS)
	echo "\033[32m[✔] \033[0mWolf3d"

obj/%.o : src/%.c
	test -e ./SDL2/SDL2/build || (cd SDL2/SDL2 ; ./configure ; make -j4 ; cd -)
	test -e /tmp/SDL2/freetype || (cd SDL2/freetype ; \
		./configure --prefix=/tmp/SDL2/freetype ; make install ; cd -)
	test -e /tmp/SDL2/ttf || (cd SDL2/SDL2_ttf ; \
		./configure --with-freetype-prefix=/tmp/SDL2/freetype \
		--prefix=/tmp/SDL2/ttf ; make install ; cd -)
	mkdir -p obj
	$(CC) $(FLAGS) -c $< -o $@
	echo "\033[32m[✔] \033[0m$@"

.PHONY : clean fclean

clean :
	make -C libft/ clean
	/bin/rm -rf obj/
	echo "\033[31m[✗] \033[0mObject files"

fclean : clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)
	echo "\033[31m[✗] \033[0m$(NAME)"

re : fclean all
