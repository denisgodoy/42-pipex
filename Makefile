NAME := pipex

CC := clang

OBJ_DIR := obj

CFLAGS := -Wall -Wextra -Werror -g

INCLUDES := -I includes/

HEADERS := includes/pipex.h

SRC := 	main.c \
		ft_check_args.c \
		free.c \
		ft_pipex.c \
		ft_error_handler.c \
		$(addprefix utils/, \
		ft_strdup.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_memcmp.c \
		ft_split.c \
		ft_substr.c \
		ft_strjoin_free.c \
		ft_strjoin.c \
		ft_strrchr.c)

OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)/utils
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ) $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $(NAME)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

commit:
	git add .
	git commit -m "update pipex"
	git push origin main

.PHONY: all clean fclean re