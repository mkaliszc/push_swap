NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJ_DIR = obj
LIB_DIR = ../octolib

SRC = \
		checker \
		checker_rules/ft_push checker_rules/ft_rotate checker_rules/ft_reverse_rotate checker_rules/ft_swap \
		parsing/ft_check parsing/ft_init_stacks parsing/ft_is_sorted \

SOURCES = $(addsuffix .c, $(SRC))
OBJS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC)))
LIB = $(LIB_DIR)/libft.a

all: $(NAME)

$(OBJ_DIR)/%.o: %c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB)

$(LIB):
	@$(MAKE) -C $(LIB_DIR)

clean:
	@$(MAKE) clean -C $(LIB_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) fclean -C $(LIB_DIR)
	rm -f $(NAME)


re: fclean all

.PHONY: all clean fclean re 