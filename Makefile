NAME = pipex

BONUS_NAME = pipex_bonus

MANDATORY_FILES = main.c

COMMON_FILES = parse.c free.c utils.c pipex.c

BONUS_FILES = main_bonus.c utils_bonus.c

MANDATORY_OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(MANDATORY_FILES:.c=.o))

COMMON_OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(COMMON_FILES:.c=.o))

BONUS_OBJ_FILES = $(addprefix $(BONUS_OBJ_DIR)/, $(BONUS_FILES:.c=.o))

SRC_DIR = srcs

BONUS_SRC_DIR = bonus_srcs

OBJ_DIR = objs

BONUS_OBJ_DIR = bonus_objs

LIBFT = libftprintf/libft.a

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

bonus: $(BONUS_NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(BONUS_OBJ_DIR):
	@mkdir -p $(BONUS_OBJ_DIR)

$(NAME): $(MANDATORY_OBJ_FILES) $(COMMON_OBJ_FILES) $(LIBFT)
	$(CC) $(CFLAGS) -fsanitize=address -o $@ $^

$(BONUS_NAME): $(COMMON_OBJ_FILES) $(BONUS_OBJ_FILES) $(LIBFT)
	$(CC) $(CFLAGS) -fsanitize=address -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -g -c $< -o $@

$(BONUS_OBJ_DIR)/%.o: $(BONUS_SRC_DIR)/%.c | $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) -g -c $< -o $@

$(LIBFT):
	make -C libftprintf

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BONUS_OBJ_DIR)
	make clean -C libftprintf

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)
	make fclean -C libftprintf

re: fclean all
