NAME = pipex

C_FILES = main.c parse.c free.c utils.c

OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(C_FILES:.c=.o))

SRC_DIR = srcs

OBJ_DIR = objs

LIBFT = libftprintf/libft.a

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_FILES) $(LIBFT)
	$(CC) $(CFLAGS) -fsanitize=address -o $@ $^ libftprintf/libft.a

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -g -c $< -o $@

$(LIBFT):
	make -C libftprintf

clean:
	rm -rf $(OBJ_DIR)
	make clean -C libftprintf

fclean: clean
	rm -f $(NAME)
	make fclean -C libftprintf

re: fclean all
