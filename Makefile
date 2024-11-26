NAME = push_swap

FT = is/ft_isdigit is/ft_isspace \
	str/ft_strlen str/ft_atoi str/ft_strdup str/ft_strchr str/ft_substr str/ft_strjoin str/ft_split \
	fd/ft_putstr_fd \
	get_next_line/get_next_line \
	ft_printf/ft_hexa_printf ft_printf/ft_put_printf ft_printf/ft_printf ft_printf/ft_toupper \
	parsing/ft_check parsing/ft_init_stacks parsing/ft_is_sorted parsing/ft_sort_array \
	rules/ft_swap rules/ft_push rules/ft_rotate rules/ft_reverse_rotate \
	push_swap_utils/ft_sqrt push_swap_utils/ft_stack_length push_swap_utils/ft_little_case \
	push_swap_utils/ft_lstadd_front \
	sorting/ft_chunk_sort sorting/ft_turk_sort sorting/push_swap \
	main \

SOURCES = $(addprefix src/, $(addsuffix .c, $(FT)))
OBJS = $(addprefix obj/, $(addsuffix .o, $(FT)))

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude

all: $(NAME)

obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf obj

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
 
