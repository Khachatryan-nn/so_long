NAME			=	so_long
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -rf

MINILIBX_PATH	=	/Users/tikhacha/Desktop/all/minilibx
#MINILIBX_PATH	=	/Users/tigrankhachatryan/Desktop/all/42/minilibx
MINILIBX		=	-L$(MINILIBX_PATH) -lmlx -framework OpenGL -framework AppKit
#X11_FLAGS		=	-L/usr/X11/lib -lXext -lX11
#-L/usr/X11/lib -lXext -lX11

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
						-@$(CC) $(CFLAGS) $(MINILIBX) -o $(NAME) $(OBJS)
						@echo "Build complete!"
#						-@$(CC) $(CFLAGS) $(MINILIBX) $(X11_FLAGS) -o $(NAME) $(OBJS)

clean:
						-@$(RM) $(OBJ_PATH)

fclean:				clean
						-@$(RM) $(NAME)

re:					fclean all

.PHONY:	all clean fclean re
