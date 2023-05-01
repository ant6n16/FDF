# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 13:19:05 by lumorale          #+#    #+#              #
#    Updated: 2023/05/01 19:28:01 by antdelga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fdf

CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra
RM				=	rm -f
AR				=	ar -rcs

SRCS			=	src/ft_error.c \
					src/utils.c \
					src/utils_reading.c \
					src/draw.c \
					src/data_reading.c \
					src/ft_velazquez.c \
					src/ft_space.c \
					src/bar.c \
					src/ft_hooks.c \
					src/main.c \
					

#		COLORS		#
CYELLOW			=\033[1;33m
CGREEN			=\033[0;32m
CRED			=\033[0;91m
CRESET			=\033[0m

OBJS			=	$(SRCS:.c=.o)

OBJS_B			=	$(SRCS_B:.c=.o)

INC_LFT = -Ilibft
LIBFT = libft/libft.a

MLX_DIR = MLX42
LIBMLXL = libmlx42.a
LIBMLX = $(MLX_DIR)/libmlx42.a -ldl -lglfw -pthread -lm
INC_MLX = -I$(MLX_DIR)/include/MLX42 -Iinclude -lglfw -L"/Users/$$USER/.brew/opt/glfw/lib/"

INC = -Iinclude $(INC_LFT) $(INC_FTP) $(INC_GNL) $(INC_MLX)

%.o: %.c
				@$(CC) $(CFLAGS) -c $< -o $@

all:			$(LIBFT) $(LIBMLXL) $(NAME)

$(LIBFT):
				@echo "\n$(CYELLOW)Compile Libft$(CRESET)"
				@make -C ./libft

$(LIBMLXL):
				@echo "\n$(CYELLOW)Compile MLX42$(CRESET)"
				@make -C ./MLX42

$(NAME):		$(OBJS)
				@$(CC) $(FLAGS) $(INC) $(LIBMLX) $(LIBFT) $(OBJS) -o $(NAME)
				@echo "\n$(CYELLOW)$(NAME) -> $(CGREEN) compiled$(CRESET)"

clean:
				@$(RM) $(OBJS)
				@make -C ./libft clean
				@make -C ./MLX42
				@echo "${CYELLOW}${NAME} $(CGREEN) -> ${CRED} objects deleted.${CRESET}"

fclean:			clean
				@$(RM) $(NAME)
				@$(RM) $(NAME_B)
				@make -C ./libft fclean
				@make -C ./MLX42 fclean
				@echo "${CYELLOW}${NAME} $(CGREEN) -> ${CRED} was deleted.${CRESET}"

re:				fclean all

.PHONY:			all clean fclean re bonus