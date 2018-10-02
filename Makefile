#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/13 15:30:08 by vbrazhni          #+#    #+#              #
#    Updated: 2018/09/13 15:30:09 by vbrazhni         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem-in
VS_NAME = vs

CC = gcc
FLAGS = -Wall -Werror -Wextra -O3
LIBRARIES = -lft -L$(LIBFT_DIRECTORY) -L$(SDL_LIBRARY) -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_gfx
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS) -I$(SDL_HEADERS)

SDL_LIBRARY = $(HOME)/.brew/lib
SDL_HEADERS = $(HOME)/.brew/include

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)includes/

HEADERS_LIST = lem_in.h\
	error_message.h\
	vs.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = ./sources/
SOURCES_LIST = read_next_line.c\
	parse.c\
	parse_ants.c\
	parse_rooms.c\
	parse_links.c\
	parse_locations.c\
	parse_turns.c\
	is.c\
	validate.c\
	bfs.c\
	align_links.c\
	count_io_links.c\
	find_room.c\
	find_link.c\
	find_ant.c\
	delete_links.c\
	delete_input_forks.c\
	delete_output_forks.c\
	paths.c\
	perform_turns.c\
	perform_turns_utils.c\
	turn_location.c\
	ants.c\
	ants_locations.c\
	free.c\
	free_2.c\
	utils.c\
	print.c\
	vs_color.c\
	vs_rect.c\
	vs_create.c\
	vs_init.c\
	vs_shift.c\
	vs_event.c\
	vs_draw.c\
	vs_draw_scene.c\
	vs_clear.c\
	vs_utils.c
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

LI_SOURCES_LIST = lem_in.c
LI_SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(LI_SOURCES_LIST))

VS_SOURCES_LIST = vs.c
VS_SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(VS_SOURCES_LIST))

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

LI_OBJECTS_LIST = $(patsubst %.c, %.o, $(LI_SOURCES_LIST))
LI_OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(LI_OBJECTS_LIST))

VS_OBJECTS_LIST = $(patsubst %.c, %.o, $(VS_SOURCES_LIST))
VS_OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(VS_OBJECTS_LIST))

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(NAME) $(VS_NAME)

$(NAME): $(LIBFT) $(OBJECTS_DIRECTORY) $(LI_OBJECTS) $(OBJECTS)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(LI_OBJECTS) $(OBJECTS) -o $(NAME)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(VS_NAME): $(LIBFT) $(OBJECTS_DIRECTORY) $(VS_OBJECTS) $(OBJECTS)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(VS_OBJECTS) $(OBJECTS) -o $(VS_NAME)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(VS_NAME) was created$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(NAME): $(GREEN)Creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(LIBFT)
	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
	@rm -f $(VS_NAME)
	@echo "$(NAME): $(RED)$(VS_NAME) was deleted$(RESET)"
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all