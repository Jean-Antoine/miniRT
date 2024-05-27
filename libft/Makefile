SRCS_D =					./srcs/
OBJS_D =					./objs/
BASE_D =					/base/
PRINTF_D =					/printf/
GNL_D =						/gnl/
LIST_D =					/list/
SRCS_BASE =					ft_isalpha.c\
							ft_isdigit.c\
							ft_isalnum.c\
							ft_isascii.c\
							ft_isprint.c\
							ft_strlen.c\
							ft_memset.c\
							ft_bzero.c\
							ft_memcpy.c\
							ft_memmove.c\
							ft_strlcpy.c\
							ft_strlcat.c\
							ft_toupper.c\
							ft_tolower.c\
							ft_strchr.c\
							ft_strrchr.c\
							ft_strncmp.c\
							ft_memchr.c\
							ft_memcmp.c\
							ft_strnstr.c\
							ft_atoi.c\
							ft_calloc.c\
							ft_strdup.c\
							ft_substr.c\
							ft_strjoin.c\
							ft_strtrim.c\
							ft_split.c\
							ft_itoa.c\
							ft_strmapi.c\
							ft_striteri.c\
							ft_putchar_fd.c\
							ft_putstr_fd.c\
							ft_putendl_fd.c\
							ft_putnbr_fd.c\
							ft_atof.c\
							ft_min.c\
							ft_max.c\
							ft_abs.c\
							ft_max_array.c\
							ft_min_array.c\
							ft_free_tab.c
SRCS_LIST =					ft_lstnew_bonus.c\
							ft_lstadd_front_bonus.c\
							ft_lstsize_bonus.c\
							ft_lstlast_bonus.c\
							ft_lstadd_back_bonus.c\
							ft_lstdelone_bonus.c\
							ft_lstclear_bonus.c\
							ft_lstiter_bonus.c\
							ft_lstmap_bonus.c
SRCS_GNL = 					get_next_line.c\
							get_next_line_utils.c
SRCS_PRINTF =				ft_printf.c\
							ft_itostr.c\
							ft_ptrtostr.c\
							ft_putstr.c\
							ft_strapd_c.c\
							ft_strppd_c.c\
							ft_newfld.c\
							ft_readformat.c \
							ft_readflags.c \
							ft_readparams.c \
							ft_strpadding.c \
							ft_applyprecision.c\
							ft_applysign.c \
							ft_applyhexprefix.c\
							ft_applywidth.c\
							ft_fldmap.c \
							ft_clearfldlst.c
SRCS_F = 					$(addprefix $(BASE_D), $(SRCS_BASE))\
							$(addprefix $(LIST_D), $(SRCS_LIST))\
							$(addprefix $(GNL_D), $(SRCS_GNL))\
							$(addprefix $(PRINTF_D), $(SRCS_PRINTF))
SRCS =						$(addprefix $(SRCS_D), $(SRCS_F))
OBJS =						$(addprefix $(OBJS_D), $(SRCS_F:.c=.o))
HEADER_D =					./include/
NAME =						libft.a
CC =						cc
CPPFLAGS =					-I./include/
CFLAGS =					-Wall -Wextra -Werror
SILENT =					FALSE
OBJ_COLOR =					\033[0;34m
LIB_COLOR =					\033[1;36m
NO_COLOR =					\033[0m
BOLD =						\033[1m

all: 						$(NAME)

$(OBJS_D)%.o:				$(SRCS_D)%.c
	@mkdir -p $(addprefix $(OBJS_D), $(BASE_D) $(PRINTF_D) $(GNL_D) $(LIST_D))
ifeq (FALSE, $(SILENT))
	$(CC) $(CPPFLAGS) -c $(CFLAGS) $< -o $@
else
	@$(CC) $(CPPFLAGS) -c $(CFLAGS) $< -o $@
endif

$(NAME): 					$(OBJS)
ifeq (FALSE, $(SILENT))
	ar crs $@ $?
else
	@ar crs $@ $?
endif
clean:
	@rm -fdr $(OBJS_D)

fclean: 					clean
	@rm -f $(NAME)

re: 						fclean all

norme:
	norminette $(SRCS)
	norminette -R CheckDefine $(HEADER_D)

.PHONY:						mkdir_obj

echo:						
	echo $(SILENT)