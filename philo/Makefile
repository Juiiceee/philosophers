NAME		:= philo
OBJ_DIR		:= obj
SRCS		:= checkarg.c create.c init.c main.c routine.c utils.c
SRCS		:= $(SRCS:%=%)
OBJS		:= $(SRCS:%.c=$(OBJ_DIR)/%.o)
CC			:= cc
#NORM		:= norminette *.c *.h
CFLAGS		:= -Wall -Wextra -Werror -g3
RM			:= rm -rf
DIR_DUP		= mkdir -p $(@D)

all		: norm $(NAME)

norm	:
	$(NORM)

$(NAME)	:	$(OBJS)
	$(DIR_DUP)
	$(CC) $(OBJS) $(CFLAGS) -lpthread -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	$(DIR_DUP)
	$(CC) -c $< $(CFLAGS) -o $@

clean	:
	$(RM) $(OBJS)
	$(RM) $(OBJ_DIR)

fclean	:	clean
	$(RM) bin

re		:	fclean all

.PHONY: all clean fclean re norm