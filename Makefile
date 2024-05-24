SRCS_F =					$(addprefix /vector_operations/,\
								ft_create_point.c\
								ft_create_vector.c\
								ft_get_vector_norm.c\
								ft_create_vector_from_points.c\
								ft_translate_point.c\
								ft_add_vectors.c\
								ft_multiply_vector_by_num.c\
								ft_normalize_vector.c\
								ft_dot_product_vectors.c\
								ft_cross_product_vectors.c)\
							$(addprefix /parsing/,\
								ft_open_file.c\
								ft_new_light_addback.c\
								ft_create_color.c\
								ft_create_color_from_arg.c\
								ft_create_ambiant_light.c\
								ft_fill_scene.c\
								ft_create_scene.c\
								ft_parse_scene.c)\
							ft_tabsize.c\
							main.c

OBJS_F = 					$(SRCS_F:.c=.o)
SRCS_D =					./srcs/
OBJS_D =					./objs/
SRCS =						$(addprefix $(SRCS_D), $(SRCS_F))
OBJS =						$(addprefix $(OBJS_D), $(OBJS_F))
HEADERS_D =					./include/
HEADERS_F =					mini_rt.h \
							struct.h \
							vector_operations.h \
							parsing.h \
							libraries.h
HEADERS =					$(addprefix $(HEADERS_D), $(HEADERS_F))
CC = 						cc
CPPFLAGS =					-I./libft/include -I./include 
CFLAGS =					-Wall -Werror -Wextra -g3
LIBFT_PATH =				./libft/
LIBFT =						$(LIBFT_PATH)/libft.a
NAME =						miniRT
OBJ_COLOR =					\033[0;34m
LIB_COLOR =					\033[1;36m
NO_COLOR =					\033[0m
BOLD =						\033[1m

all:						$(NAME)

$(NAME):					$(LIBFT) $(OBJS)
							@echo "$(LIB_COLOR)[$(NAME)] Compiling$(NO_COLOR) $(LIB_COLOR)binary$(NO_COLOR)"
							$(CC) $(CPPFLAGS) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_PATH) -lft -lm

$(OBJS_D)%.o:				$(SRCS_D)%.c $(HEADERS)
							@mkdir -p $(dir $@)
							@echo "$(LIB_COLOR)[miniRT] $(NO_COLOR)Compiling $(OBJ_COLOR)$(notdir $<)$(NO_COLOR)"
							$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(LIBFT):
							@echo "$(LIB_COLOR)[  libft  ] Compiling$(NO_COLOR) $(LIB_COLOR)library$(NO_COLOR)"
							@make --no-print-directory -C $(LIBFT_PATH) all

bonus:						$(NAME)
							@cp $(NAME) $(NAME)_bonus

valgrind:					$(NAME)
							valgrind --leak-check=full \
								--child-silent-after-fork=yes \
								--show-leak-kinds=all \
								--show-reachable=yes \
								--track-fds=yes\
								--track-origins=yes \
								./$(NAME) test.rt

valgrindnoenv: 				$(NAME)
							valgrind --leak-check=full \
								--child-silent-after-fork=yes \
								--show-leak-kinds=all \
								--show-reachable=yes \
								--track-origins=yes \
								--track-fds=yes\
								env -i ./$(NAME)

clean:						
							@make --no-print-directory -C $(LIBFT_PATH) clean
							@rm -rfd $(OBJS_D)

fclean:						clean
							@make --no-print-directory -C $(LIBFT_PATH) fclean
							@rm -f $(NAME)

re:							fclean all

echo:
							echo $(SRCS)

clean_local:
							rm -rfd $(OBJS_D)

debug:						clean_local $(NAME)

.PHONY:						all clean fclean re
