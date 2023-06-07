NAME			=	so_long
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
IFLAGS			=	-Iincludes -I/usr/bin/includes
MINILIBX		=	-lmlx -framework OpenGL -framework AppKit
RM				=	rm -rf

#MINILIBX_PATH	=	/Users/tigrankhachatryan/Desktop/all/42/minilibx
#X11_FLAGS		=	-L/usr/X11/lib -lXext -lX11

SRC_PATH		=	src
OBJ_PATH		=	obj
SRCS			=	$(wildcard $(SRC_PATH)/*.c)
OBJS			=	$(patsubst $(SRC_PATH)/%.c, $(OBJ_PATH)/%.o, $(SRCS))

.DEFAULT_GOAL	=	all
HEADER			=	includes/so_long.h Makefile

all:				$(NAME)

$(OBJ_PATH)/%.o:	$(SRC_PATH)/%.c $(HEADER)
						-@mkdir -p $(OBJ_PATH)
						-@$(CC) $(IFLAGS) $(CFLAGS) -c $< -o $@

$(NAME):			$(OBJS)
						-@$(CC) $(CFLAGS) $(IFLAGS) $(MINILIBX) -o $(NAME) $(OBJS)
						@echo "Build complete!"
#						-@$(CC) $(CFLAGS) $(MINILIBX) $(X11_FLAGS) -o $(NAME) $(OBJS)

clean:
						-@$(RM) $(OBJ_PATH)

fclean:				clean
						-@$(RM) $(NAME)

re:					fclean all

.PHONY:	all clean fclean re
