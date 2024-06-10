SRCS_F =					$(addprefix /vector/,\
								ft_p_set.c\
								ft_v_set.c\
								ft_v_norm.c\
								ft_p_to_v.c\
								ft_p_translate.c\
								ft_v_add.c\
								ft_v_scalar_prod.c\
								ft_v_normalize.c\
								ft_v_dot_prod.c\
								ft_v_cross_prod.c\
								ft_tuple_print.c)\
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
								ft_create_ray.c\
								ft_transform.c\
								ft_hit.c\
								ft_free_inters_lst.c\
								ft_new_inters.c\
								ft_inters_sphere.c\
								ft_mat_obj.c\
								ft_mat_sphere.c)\
							$(addprefix /matrix/,\
								ft_mat_id.c\
								ft_mat_print.c\
								ft_mat_prod.c\
								ft_mat_trans.c\
								ft_mat_inv.c\
								ft_mat_prod_tup.c\
								ft_translation.c\
								ft_scaling.c)\
							ft_display.c\
							main.c

OBJS_F = 					$(SRCS_F:.c=.o)
SRCS_D =					./srcs/
OBJS_D =					./objs/
SRCS =						$(addprefix $(SRCS_D), $(SRCS_F))
OBJS =						$(addprefix $(OBJS_D), $(OBJS_F))
HEADERS_D =					./include/
HEADERS_F =					vector.h\
							parsing.h\
							matrix.h\
							compute.h\
							display.h
HEADERS =					$(addprefix $(HEADERS_D), $(HEADERS_F))
CC = 						cc
CPPFLAGS =					-I./libft/include -I./include -I./mlx/
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

mlx:
							if [ ! -d $(LIB_MLX_D) ]; then git clone https://github.com/42Paris/minilibx-linux.git $(LIB_MLX_D); fi;
							@make -C $(LIB_MLX_D)

$(NAME):					mlx $(LIBFT) $(OBJS)
							@echo "$(LIB_COLOR)[$(NAME)] Compiling$(NO_COLOR) $(LIB_COLOR)binary$(NO_COLOR)"
							@$(CC) $(CPPFLAGS) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIB_FT_D) -L$(LIB_MLX_D) -lft -lm -lmlx -lX11 -lXext

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
								--show-leak-kinds=all \
								--show-reachable=yes \
								--track-fds=yes\
								--track-origins=yes \
								./$(NAME) test.rt

clean:						
							@make --no-print-directory -C $(LIB_FT_D) clean
							@rm -rfd $(OBJS_D)

fclean:						clean
							@make --no-print-directory -C $(LIB_FT_D) fclean
							@rm -f $(NAME)

re:							fclean all

echo:
							echo $(OBJS)

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
