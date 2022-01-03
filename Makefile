NAME = pipex

C_FILES = main.c children.c parse.c error.c free.c

OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(C_FILES:.c=.o))

SRC_DIR = srcs

OBJ_DIR = objs

LIBFT = srcs/libftprintf/libft.a

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_FILES) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ srcs/libftprintf/libft.a

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C srcs/libftprintf

clean:
	rm -rf $(OBJ_DIR)
	make clean -C srcs/libftprintf

fclean: clean
	rm -f $(NAME)
	make fclean -C srcs/libftprintf

re: fclean all
