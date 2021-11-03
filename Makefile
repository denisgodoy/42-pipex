NAME := pipex

CC := clang

CFLAGS := -Wall -Wextra -Werror -g

HEADERS := pipex.h

SRC := main.c utils.c

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
