NAME = pipex

BONUS_NAME = pipex_bonus

MANDATORY_FILES = main.c

COMMON_FILES = parse.c free.c utils.c utils2.c utils3.c utils4.c split.c pipex.c

BONUS_FILES = main_bonus.c utils_bonus.c get_next_line.c get_next_line_utils.c

MANDATORY_OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(MANDATORY_FILES:.c=.o))

COMMON_OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(COMMON_FILES:.c=.o))

BONUS_OBJ_FILES = $(addprefix $(BONUS_OBJ_DIR)/, $(BONUS_FILES:.c=.o))

SRC_DIR = srcs

BONUS_SRC_DIR = bonus_srcs

OBJ_DIR = objs

BONUS_OBJ_DIR = bonus_objs

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

bonus: $(BONUS_NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(BONUS_OBJ_DIR):
	@mkdir -p $(BONUS_OBJ_DIR)

$(NAME): $(MANDATORY_OBJ_FILES) $(COMMON_OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

$(BONUS_NAME): $(COMMON_OBJ_FILES) $(BONUS_OBJ_FILES)
	$(CC) $(CFLAGS) -o $(NAME) $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -g -c $< -o $@

$(BONUS_OBJ_DIR)/%.o: $(BONUS_SRC_DIR)/%.c | $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) -g -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BONUS_OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
