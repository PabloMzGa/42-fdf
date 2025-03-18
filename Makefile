# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/20 14:34:30 by pabmart2          #+#    #+#              #
#    Updated: 2025/03/14 17:31:53 by pabmart2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lglfw -lm
BUILD_DIR = build
OBJ_DIR = build/obj
NAME = fdf

SRC = \
	src/main.c \
	src/hooks/exit_keyhook.c \
	src/interaction/rotation.c \
	src/render/camera.c \
	src/render/render.c \
	src/render/lines/draw_line_helper.c \
	src/render/lines/draw_line.c \
	src/utils/clean_utils.c \
	src/utils/file_utils.c \
	src/vect_process/map2d_helper.c \
	src/vect_process/map2d.c \
	src/vect_process/process_coord_helper.c \
	src/vect_process/process_coord.c \

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

LIBS = \
	lib/MLX42/include/libmlx42.a \
	lib/libft/include/libft.a

INCLUDES = \
	-Iinclude \
	-Ilib/MLX42/include \
	-Ilib/MLX42/include/MLX42 \
	-Ilib/MLX42/include/lodepng \
	-Ilib/MLX42/include/glad \
	-Ilib/MLX42/include/KHR \
	-Ilib/libft/include

all: $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "\033[31mObject files removed\033[0m"

fclean: clean
	@rm -f $(BUILD_DIR)/$(NAME)
	@$(MAKE) -C lib/libft fclean
	@echo "\033[31m$(NAME) removed\033[0m"

re: fclean
	$(MAKE) all

libft:
	@echo "\033[33mCompiling libft...\033[0m"
	@$(MAKE) -C lib/libft

$(NAME): libft $(OBJ)
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(OBJ) -o $(BUILD_DIR)/$(NAME) $(LIBS) $(LDFLAGS) $(INCLUDES)
	@echo "\033[32m\n¡$(NAME) compiled! \
	ᕦ(\033[36m⌐■\033[32m_\033[36m■\033[32m)ᕤ\n"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "\033[34mCompiling: \033[0m$<"

.PHONY: all clean fclean re bonus
