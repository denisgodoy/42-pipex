NAME := pipex

CC := gcc

OBJ_DIR := obj

CFLAGS := -Wall -Wextra -Werror -g

INCLUDES := -I includes/

HEADERS := includes/pipex.h

SRC := 	main.c \
		errors.c \
		ft_free_arr.c \
		ft_check_args.c \
		ft_check_shell.c \
		ft_pipex.c \
		$(addprefix utils/, \
		ft_memcmp.c \
		ft_split.c \
		ft_strdup.c \
		ft_strjoin_free.c \
		ft_strjoin.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strrchr.c \
		ft_substr.c)

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

.PHONY: all clean fclean re
