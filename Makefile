NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude

SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = src/octolib


FT = parsing/ft_check parsing/ft_init_stacks parsing/ft_is_sorted parsing/ft_sort_array \
	rules/ft_swap rules/ft_push rules/ft_rotate rules/ft_reverse_rotate \
	push_swap_utils/ft_stack_length push_swap_utils/ft_little_case \
	push_swap_utils/ft_lstadd_front push_swap_utils/ft_free_all \
	sorting/ft_chunk_sort sorting/ft_turk_sort sorting/push_swap sorting/get_functions sorting/ft_chunk_utils \
	main

SOURCES = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(FT)))
OBJS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(FT)))

LIB = $(LIB_DIR)/libft.a

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
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