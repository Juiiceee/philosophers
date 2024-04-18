NAME		:= philo
OBJ_DIR		:= obj
SRCS		:= checkarg.c create.c init.c main.c routine.c utils.c
SRCS		:= $(SRCS:%=%)
OBJS		:= $(SRCS:%.c=$(OBJ_DIR)/%.o)
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g3
CPPFLAGS	:= -MMD -MP -I include
RM			:= rm -rf
DIR_DUP		= mkdir -p $(@D)
#./philo 190 800 200 200 20 | grep -E "[0-9]+ 189 is eating" | wc -l

all		: $(NAME)

$(NAME)	:	$(OBJS)
	$(DIR_DUP)
	$(CC) $(OBJS) $(CFLAGS) -lpthread -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	$(DIR_DUP)
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

-include $(DEPS)

clean	:
	$(RM) $(OBJ_DIR)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all

.PHONY: all clean fclean re