##
## EPITECH PROJECT, 2022
## Untitled (Workspace)
## File description:
## Makefile
##

NAME	=	mysh

CFLAGS	+=	-I ./include

SRC	=	./src/main.c \
		./src/all_str/my_putstr.c	\
		./src/all_str/my_strncat.c \
		./src/all_str/my_str_to_word_array.c \
		./src/all_str/my_strcmp.c	\
		./src/all_str/my_strncmp.c \
		./src/launch_all.c \
		./src/environement_funct.c \
		./src/del_line.c \
		./src/get_file_path.c \
		./src/all_str/path_specs.c \
		./src/cd_operations.c \
		./src/all_str/my_strlen.c \
		./src/all_str/my_strcpy.c \
		./src/value_init.c \
		./src/my_root.c \
		./src/is_alpha_num.c \
		./src/all_str/my_strdup.c \
		./src/all_str/my_strncpy.c \
		./src/wrong_architecture.c \
		./src/cmd_errors.c \
		./src/my_execve.c

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) $(CFLAGS) -o $(NAME)
	cp $(NAME) ./tests/
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY : all clean fclean re
