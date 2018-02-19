# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scorbion <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 13:13:07 by scorbion          #+#    #+#              #
#    Updated: 2017/03/16 15:10:12 by cesnault         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
LIB = libfdf.a
OBJS = main.o \
	   ft_draw.o \
	   main_extended.o \
	   draw_line.o \
	   ft_iso.o \
	   red_cross.o  

INCLUDES =  -I minilibx_macos/ -I libft/includes/ minilibx_macos/libmlx.a libft/libft.a
FLAGS = -Wall -Werror -Wextra 
FRM = -framework openGL -framework Appkit
.PHONY:all clean
all : $(NAME)

$(NAME) : $(OBJS) 
	make -C libft
	make -C minilibx_macos
	ar rc $(LIB) $(OBJS)
	gcc $(FLAGS) $(INCLUDES) $(LIB) -o $(NAME) $(FRM)
%.o: %.c
	gcc $(FLAGS) -c $^

clean :
	rm -f $(OBJS)
	make clean -C libft
	make clean -C minilibx_macos

fclean : clean
	rm -f $(NAME)
	rm -f $(LIB)
	make fclean -C libft

re : fclean all

