NAME			=	so_long
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -rf

SRC_PATH		=	src
OBJ_PATH		=	obj
SRCS			=	$(wildcard $(SRC_PATH)/*.c)
OBJS			=	$(patsubst $(SRC_PATH)/%.c, $(OBJ_PATH)/%.o, $(SRCS))

.DEFAULT_GOAL	=	all
HEADER			=	includes/so_long.h

all:				$(NAME)

$(OBJ_PATH)/%.o:	$(SRC_PATH)/%.c $(HEADER)
						-@mkdir -p $(OBJ_PATH)
						-@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):			$(OBJS)
						-@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
						@echo "Build complete!"

clean:
						-@$(RM) $(OBJ_PATH)

fclean:				clean
						-@$(RM) $(NAME)

re:					fclean all

.PHONY:	all clean fclean re