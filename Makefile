NAME = so_long
CFLAGS = -Wall -Wextra -Werror
MAIN = main.c
DIR_SRC = ./src
DIR_OBJS = ./obj
INCLUDES = -I ./include -I ./libft

SRC = $(MAIN) check_map.c collision.c destroy.c error_mensage.c events.c \
init_data.c item_count.c read_map.c render_utils.c render.c sprintes_load.c \
start_game.c \

OBJS = $(SRC:.c=.o)
SRC_PATH = $(addprefix $(DIR_SRC)/, $(SRC))
OBJS_PATH = $(addprefix $(DIR_OBJS)/, $(OBJS))

all:	$(NAME)

$(NAME): $(OBJS_PATH) ./libft/libft.a
	gcc $(CFLAGS) $(INCLUDES) $^ -o $@

./libft/libft.a:
	@make -C libft

./obj/%.o: ./src/%.c
	mkdir -p obj
	gcc $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make clean -C libft
	rm -rf *.o $(OBJS_PATH)

fclean:	clean
	@make fclean -C libft
	rm -rf *.o $(OBJS_PATH) $(NAME)

re: fclean all

mclean: all clean

.PHONY:	all clean fclean re mclean