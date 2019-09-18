# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madams <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/12 08:40:50 by madams            #+#    #+#              #
#    Updated: 2019/09/17 11:15:48 by madams           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC_PATH = srcs
SRC_NAME = main.c parser.c ray_caster.c hook.c draw.c hud.c side_menu.c

OBJ_PATH = objs
OBJ_NAME = $(SRC_NAME:.c=.o)

CC = clang
CFLAGS = -Wall -Werror -Wextra

CPPFLAGS = -I includes -I libft/includes

LDFLAGS = -L libft
LDLIBS = -lft -lm -lmlx -framework OpenGL -framework AppKit

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: libft $(NAME)

$(NAME): $(OBJ) libft/libft.a
	@$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@
	@echo "Compilation of Wolf3d:	\033[1;32mOK\033[m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -c $< $(CPPFLAGS) -o $@

libft:
	@make -C libft

clean:
	@make -C libft clean
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "Wolf3d:	Removing Objs"

fclean:
	@make -C libft fclean
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "Wolf3d:	Removing Objs"
	@rm -f $(NAME)
	@echo "Wolf3d:	Removing Wolf3d"

re: fclean all

.PHONY: all clean fclean re libft

