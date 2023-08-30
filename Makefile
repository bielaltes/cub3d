# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 00:35:07 by jsebasti          #+#    #+#              #
#    Updated: 2023/08/30 16:16:13 by baltes-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= cub3d
INC_DIR		= INC
LIB_DIR		= LIB
MKFL		= Makefile
SRC_DIR		= SRC/
OBJ_DIR		= OBJ/
MLX_DIR		= LIB/minilibx_opengl_20191021
MLX			= libmlx.a
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
INC_MLX		= mlx.h


# ----Libraryes----
PW_HEADER	= $(INC_DIR)/cub3d.h
LIB			= $(LIB_DIR)/libft/libft.a
LIB_L 		= $(LIB_DIR)/libft/
LIB_M 		= $(LIB_DIR)/minilibx_opengl_20191021/
# =============

# -------------
RM = rm -rf
MP = mkdir -p
CFLAGS =  -g -Wall -Wextra -Werror -fsanitize=address
LIBC = ar -rcs
# =============

SRC_L	=	main.c


SRC = $(addprefix $(SRC_DIR), $(SRC_L))

# -------------
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
DEP = $(addsuffix .d, $(basename $(OBJ)))
# =============

all:
	@$(MAKE) -C $(LIB_L) --no-print-directory
	@$(MAKE) -C $(LIB_M) --no-print-directory
	@$(MAKE) $(NAME) --no-print-directory

$(OBJ_DIR)%.o: %.c $(MKFL)
	@$(MP) $(dir $@)
	@printf "                       \rCompiling $<"
	@$(CC) $(CFLAGS) -MMD -I $(INC_DIR) -c $< -o $@

$(NAME):: $(OBJ) $(LIB)
	@printf "\nLinking minishell\n"
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) $(MLX_FLAGS) -o $(NAME)

$(NAME)::
	@echo "Hello, Minishell already compiled 😇"

-include $(DEP)

clean:
	@$(MAKE) clean -C $(LIB_M) --no-print-directory
	@$(MAKE) clean -C $(LIB_L) --no-print-directory
	$(RM) $(OBJ_DIR)

fclean: clean
	@$(MAKE) fclean -C $(LIB_M) --no-print-directory
	@$(MAKE) clean -C $(LIB_L) --no-print-directory
	$(RM) $(NAME)

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) --no-print-directory

.PHONY: all clean fclean re
