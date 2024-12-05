NAME:= checker

CC = cc
CFLAGS = -Wall -Wextra -Werror -I../../include
LIB = ../octolib/libft.a
OUTPUT_DIR = ../../

SRC =	checker_rules/ft_push.c checker_rules/ft_reverse_rotate.c checker_rules/ft_rotate.c checker_rules/ft_swap.c \
    	checker.c \
		../parsing/ft_check.c ../parsing/ft_init_stacks.c ../parsing/ft_is_sorted.c \
		../push_swap_utils/ft_lstadd_front.c ../push_swap_utils/ft_free_all.c \

OBJ = $(SRC:.c=.o)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIB)
		$(CC) $(CFLAGS) -o $(OUTPUT_DIR)$(NAME) $(OBJ) $(LIB)

$(LIB):
		$(MAKE) -C ../octolib

all: $(NAME)

clean:
		$(MAKE) clean -C ../octolib
		rm -f $(OBJ)

fclean: clean
		rm -f $(OUTPUT_DIR)$(NAME)

re: fclean all

.PHONY: all clean fclean re