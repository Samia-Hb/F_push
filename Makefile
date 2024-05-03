CFLAGS = -Wall -Wextra -Werror
CC = gcc -fsanitize=address -g3
BONUS = checker
NAME = push_swap

SRCS = main.c \
	algo.c \
	clean.c	\
	push_swap.c \
	push_swap_utils.c \
	push_back.c \
	movements.c \
	movements_P2.c \
	check_arguments.c \
	regular_cases.c \
	movements_calculation.c \
	LIBFT/ft_split.c \
	LIBFT/ft_strcmp.c \
	LIBFT/ft_strlen.c \
	LIBFT/ft_atoi.c\
	LIBFT/ft_putstring.c \
	FT_PRINTF/ft_printf.c \
	FT_PRINTF/ft_putchar.c \
	FT_PRINTF/ft_putnbr_base.c \
	FT_PRINTF/ft_putnbr_base_adr.c \
	FT_PRINTF/ft_putnbr_signed.c \
	FT_PRINTF/ft_putstr.c \
	FT_PRINTF/ft_putnbr_unsigned.c

SRCS_BONUS =	bonus/get_next_line/get_next_line.c bonus/get_next_line/get_next_line_utils.c \
       			bonus/checker.c bonus/check_arg.c bonus/push_swap_utils_bonus.c \
       			bonus/ft_split.c bonus/ft_atoi.c \
       			bonus/movements_bonus_P2.c bonus/movements_bonus.c bonus/check_type.c

OBJS = $(SRCS:.c=.o)

OBJB = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

bonus : $(BONUS)

$(BONUS): $(OBJB)
	$(CC) $(CFLAGS) -o $(BONUS) $(OBJB)

clean:
	rm -rf $(OBJS) $(OBJB)

fclean: clean
	rm -rf $(NAME) $(BONUS)

re: clean all