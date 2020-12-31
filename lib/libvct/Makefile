NAME = libvct.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBS = ar -rc
SRCS = length.c product.c arithmetric.c init.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(LIBS) $(NAME) $(OBJS)
	@echo "Compiled libvct"

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)

fclean:
	@rm -f $(NAME) $(OBJS) $(OBJS_BONUS)

re: fclean $(NAME)

.PHONY	: all clean fclean re
