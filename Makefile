CC			=	gcc
CFLAGS 		=	-Wall -Werror -Wextra
ASM			=	nasm
ASM_FLAGS	=	-f macho64
RM			=	/bin/rm -f

NAME		=	libasm.a
SRCS		=	ft_strlen.s \
				ft_strcpy.s \
				ft_strcmp.s \
				ft_write.s \
				ft_read.s \
				ft_strdup.s
OBJS		=	$(SRCS:.s=.o)

%.o:			%.s
				$(ASM) $(ASM_FLAGS) $<

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rc $(NAME) $(OBJS)

test:			all
				$(CC) $(CFLAGS) -o libasm main.c -L. -lasm 
				./libasm

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)
				$(RM) libasm

re:				fclean $(NAME)

.PHONY:			clean fclean re