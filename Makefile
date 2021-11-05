NAME := pipex

CC := clang

CFLAGS := -Wall -Wextra -Werror -I includes/ -g

HEADERS := includes/pipex.h

SRC := main.c \
		ft_check_args.c \
		ft_free_arr.c \
		ft_pipex.c \
		ft_cmd_format.c \
		$(addprefix utils/, \
		ft_strdup.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_memcmp.c \
		ft_split.c \
		ft_substr.c \
		ft_strjoin_free.c)

OBJ := $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)
	rm -rf $(BONUS_OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

commit:
	git add .
	git commit -m "update pipex"
	git push origin main
