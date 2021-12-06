NAME = pipex

C_FILES = main.c child.c parent.c

OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(C_FILES:.c=.o))

SRC_DIR = srcs

OBJ_DIR = objs

# CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -r $(OBJ_DIR)

fclean: clean
	rm $(NAME)

re: fclean all
