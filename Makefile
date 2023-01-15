CC		=	gcc

NAME	=	BOMBER_MAN

SRC		=	main.c\
			jeu.c

OBJ		=	$(SRC:.c=.o)

CFLAGS	+=	-I./include
CFLAGS	+=	-Wall -Werror -Wextra

LDFLAGS += -lSDL -lSDL_ttf -lSDL_imag

RM		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJ) 
	$(CC) $(OBJ) $(LIBS) -o $(NAME)

clean	:
			$(RM) $(OBJ)
fclean	:	
			$(RM) $(NAME)
			

re		:	fclean clean all 

.PHONY	:	all obj clean fclean re
