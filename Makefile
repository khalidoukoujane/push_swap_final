NAME = push_swap 
CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADER = push_swap.h
SRC = error_handling.c ft_split.c main.c pa_pb.c push_swap.c ra_rb_rr.c rra_rrb_rrr.c sa_sb_ss.c sorting.c stack_utils.c utils.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@printf "\033[36mCreating $(NAME)...\033[0m\n"
	@$(CC) $(CFLAGS) $(OBJ) -o $@

%.o : %.c $(HEADER)
	@printf "\033[36mcompiling $<\033[0m\n"
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@printf "\033[33mCleaning object files.\033[0m\n"
	@rm -f $(OBJ)

fclean : clean
	@printf "\033[33mremoving $(NAME)\033[0m\n"
	@rm -f $(NAME)

re : fclean all

.PHONY : clean