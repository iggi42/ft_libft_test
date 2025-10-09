CC = cc
CFLAGS += -Wall -Wextra -Werror -g -fprofile-arcs -ftest-coverage
# before an include!
NAME = $(shell basename $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST)))))
C_SRC = ftt_utils.c ftt_lib_ctype.c ftt_lib_str.c ftt_lib_mem.c
LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a
VALGRIND = valgrind -q --trace-children=yes

C_DIR = ./src
BIN_DIR = ./bin
OBJ = $(C_SRC:%.c=$(BIN_DIR)/%.o)

.PHONY: fclean clean re all test run


$(NAME): bin/$(NAME)
all: $(NAME)

fclean: clean
	(cd $(LIBFT_DIR) && $(MAKE) fclean)

clean:
	rm -f $(OBJ) bin/$(NAME)

re: fclean all

$(LIBFT):
	(cd $(LIBFT_DIR) && $(MAKE) libft.a)

bin/$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -lcriterion -o $@ $(OBJ) $(LIBFT)

run: bin/$(NAME)
	$(VALGRIND) ./bin/$(NAME)

bin/%.o: src/%.c $(LIBFT_DIR)/libft.h
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

