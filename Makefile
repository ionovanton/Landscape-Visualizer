NAME				=	fdf

OS					:=	$(shell uname -s)

CC					=	cc

FLAGS				=	-Wall -Wextra -Werror

MLX					=	-I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

SOURCE_LIST			=	fdf.c ft_init_1.c ft_init_2.c ft_free.c hook.c \
						ft_utils_1.c ft_utils_2.c ft_utils_3.c ft_utils_4.c ft_utils_5.c \
						map_1.c map_2.c \
						draw_1.c draw_2.c draw_3.c \
						get_next_line.c get_next_line_utils.c

SRCS				=	$(SOURCE_LIST)

OBJECT_DIRECTORY	=	objs
OBJECT_LIST			=	$(SOURCE_LIST:.c=.o)
OBJS				=	$(addprefix $(OBJECT_DIRECTORY)/,$(OBJECT_LIST))

HEADER_LIST			=	fdf.h typedef.h define.h get_next_line.h mlx.h

INCLUDE				=	-I includes

HDRS				=	$(addprefix includes/,$(HEADER_LIST))

all: $(NAME)

ifeq ($(OS), Darwin)
$(NAME): $(OBJS) $(filter-out includes/mlx.h,$(HDRS))
	$(CC) -lm $(FLAGS) $(INCLUDE) $(OBJS) $(MLX) -o $@
	chmod 777 $(NAME)

$(OBJECT_DIRECTORY)/%.o: %.c $(filter-out includes/mlx.h,$(HDRS))
	mkdir -p $(OBJECT_DIRECTORY)
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@
else
$(NAME): $(OBJS) $(HDRS)
	$(CC) $(FLAGS) -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz $(OBJS) minilibx-linux/libmlx_Linux.a -o $(NAME)
	chmod a+rwx $(NAME)

$(OBJECT_DIRECTORY)/%.o: %.c $(HDRS)
	mkdir -p $(OBJECT_DIRECTORY)
	$(CC) $(FLAGS) $(INCLUDE) -I usr/includes -I minilibx-linux -Imlx_linux -c $< -o $@
endif

clean:
	rm -rfd $(OBJECT_DIRECTORY)
	rm -rf fdf_debug *.dSYM vgcore.* .DS_Store 

fclean: cls clean
	rm -rf $(NAME)

re: fclean all

cls:
	printf "\33c\e[3J"

n: cls
	norminette $(filter-out debug.c, $(SRCS)) $(filter-out includes/mlx.h, $(addprefix includes/,$(HEADER_LIST)))

.PHONY: all run clean fclean re n cls
