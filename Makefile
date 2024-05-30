SRCS_F =					$(addprefix /operations/,\
								ft_p_set.c\
								ft_v_set.c\
								ft_v_norm.c\
								ft_p_to_v.c\
								ft_p_translate.c\
								ft_v_add.c\
								ft_v_scalar_prod.c\
								ft_v_normalize.c\
								ft_v_dot_prod.c\
								ft_v_cross_prod.c)\
							$(addprefix /parsing/,\
								ft_error.c\
								ft_open_file.c\
								ft_parse.c\
								ft_parse_line.c\
								ft_parse_light.c\
								ft_parse_object.c\
								ft_parse_camera.c\
								ft_set_color.c\
								ft_set_point.c\
								ft_set_scalar.c\
								ft_is_numeric.c\
								ft_tabsize.c\
								ft_free_scene.c)\
							$(addprefix /compute/,\
								ft_compute.c\
								)\
							main.c

OBJS_F = 					$(SRCS_F:.c=.o)
SRCS_D =					./srcs/
OBJS_D =					./objs/
SRCS =						$(addprefix $(SRCS_D), $(SRCS_F))
OBJS =						$(addprefix $(OBJS_D), $(OBJS_F))
HEADERS_D =					./include/
HEADERS_F =					mini_rt.h \
							struct.h \
							operations.h \
							parsing.h \
							libraries.h
HEADERS =					$(addprefix $(HEADERS_D), $(HEADERS_F))
CC = 						cc
CPPFLAGS =					-I./libft/include -I./include 
CFLAGS =					-Wall -Werror -Wextra -g3
LIB_FT_D =					./libft/
LIB_MLX_D =					./mlx/
LIBFT =						$(LIB_FT_D)/libft.a
NAME =						miniRT
OBJ_COLOR =					\033[0;34m
LIB_COLOR =					\033[1;36m
NO_COLOR =					\033[0m
BOLD =						\033[1m

all:						$(NAME)

mlx :
							if [ ! -d $(LIB_MLX_D) ]; then git clone https://github.com/42Paris/minilibx-linux.git $(LIB_MLX_D); fi;
							make -C $(LIB_MLX_D)

$(NAME):					mlx $(LIBFT) $(OBJS)
							@echo "$(LIB_COLOR)[$(NAME)] Compiling$(NO_COLOR) $(LIB_COLOR)binary$(NO_COLOR)"
							@$(CC) $(CPPFLAGS) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIB_FT_D) -lft -lm -L$(LIB_MLX_D) -lX11 -lXext

$(OBJS_D)%.o:				$(SRCS_D)%.c $(HEADERS)
							@mkdir -p $(dir $@)
							@echo "$(LIB_COLOR)[miniRT] $(NO_COLOR)Compiling $(OBJ_COLOR)$(notdir $<)$(NO_COLOR)"
							@$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(LIBFT):
							@echo "$(LIB_COLOR)[libft] Compiling$(NO_COLOR) $(LIB_COLOR)library$(NO_COLOR)"
							@make --no-print-directory -C $(LIB_FT_D) all SILENT=TRUE

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
							@make --no-print-directory -C $(LIB_FT_D) clean
							@rm -rfd $(OBJS_D)

fclean:						clean
							@make --no-print-directory -C $(LIB_FT_D) fclean
							@rm -f $(NAME)

re:							fclean all

echo:
							echo $(SRCS)

clean_local:
							rm -rfd $(OBJS_D)

update_libft:
							rm -drf ./libft
							git clone git@github.com:Jean-Antoine/my_libft.git libft
							rm -drf ./libft/.git
							git add ./libft/
							git commit -m "update libft"
							git push

debug:						clean_local $(NAME)

.PHONY:						all clean fclean re
