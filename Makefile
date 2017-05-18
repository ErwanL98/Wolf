# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/19 12:54:42 by ele-cren          #+#    #+#              #
#    Updated: 2017/05/18 10:37:41 by ele-cren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = wolf3d

SRC = src/calc.c src/main.c src/draw.c src/check.c src/error.c src/event.c \
	  src/init.c src/menu.c src/sdl.c src/initbase.c src/event2.c src/free.c

OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))

FLAGS = -Wall -Wextra -Werror -I /tmp/SDL2/SDL2_ttf/include/SDL2  \
		-I ./SDL2/SDL2/include  -I ./libft/include -I ./include -g

LIBS = -L./libft -lft -L/tmp/SDL2/SDL2_ttf/lib -lSDL2_ttf -L/tmp/SDL2/SDL2/lib \
	   -lSDL2 -lSDL2main

HEADER = include/wolf.h libft/include/libft.h

.SILENT :

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft/
	$(CC) $(OBJ) -o $(NAME) $(LIBS) $(SDLLIBS)
	echo "\033[32m[✔] \033[0mWolf3d"

obj/%.o : src/%.c $(HEADER)
	test -e /tmp/SDL2/SDL2 || (cd SDL2/SDL2 ; \
		./configure --prefix=/tmp/SDL2/SDL2 ; make install ; cd -)
	test -e /tmp/SDL2/freetype || (cd SDL2/freetype ; \
		./configure --prefix=/tmp/SDL2/freetype ; make install ; cd -)
	test -e /tmp/SDL2/SDL2_ttf || (cd SDL2/SDL2_ttf ; \
		./configure --with-sdl-prefix=/tmp/SDL2/SDL2 \
		--with-freetype-prefix=/tmp/SDL2/freetype --prefix=/tmp/SDL2/SDL2_ttf ; \
		make install ; cd -)
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
