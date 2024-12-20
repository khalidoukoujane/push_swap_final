NAME = push_swap 
CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADER = push_swap.h
SRC = error_handling.c ft_split.c main.c pa_pb.c push_swap.c ra_rb_rr.c rra_rrb_rrr.c sa_sb_ss.c sorting.c stack_utils.c utils.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@printf "\x1b[36mCreating $(NAME)...\x1b[0m\n"
	@$(CC) $(CFLAGS) $(OBJ) -o $@

%.o : %.c $(HEADER)
	@printf "\x1b[36mcompiling $<\x1b[0m\n"
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@printf "\x1b[33mCleaning object files.\x1b[0m\n"
	@rm -f $(OBJ)

fclean : clean
	@printf "\x1b[33mremoving $(NAME)\x1b[0m\n"
	@rm -f $(NAME)

re : fclean all

.PHONY : clean