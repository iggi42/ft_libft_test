CC = cc
CFLAGS += -Wall -Wextra -Werror -g
# -fprofile-arcs -ftest-coverage
# before an include!
NAME = libft_test
# $(shell basename $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST)))))
C_SRC = ftt_utils.c ftt_lib_ctype.c ftt_lib_str.c ftt_lib_str2.c ftt_lib_mem.c 
LIBFT_DIR = ../main
LIBFT = $(LIBFT_DIR)/libft.a
VALGRIND = valgrind -q --trace-children=yes

C_DIR = ./src
BIN_DIR = ./bin
OBJ = $(C_SRC:%.c=$(BIN_DIR)/%.o)

.PHONY: fclean clean re all test run $(LIBFT)


$(NAME): bin/$(NAME)
pg: bin/pg
all: $(NAME)

fclean: clean
	(cd $(LIBFT_DIR) && $(MAKE) fclean)

clean:
	rm -f $(BIN_DIR)/*

re: fclean all

$(LIBFT):
	(cd $(LIBFT_DIR) && $(MAKE) libft.a)

bin/$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -lcriterion -o $@ $(OBJ) $(LIBFT)

$(BIN_DIR)/pg: src/ftt_utils.c src/pg.c $(LIBFT)
	$(CC) $(CFLAGS) src/ftt_utils.c src/pg.c -I$(LIBFT_DIR) -lbsd -o $(BIN_DIR)/pg $(LIBFT)

test: bin/$(NAME)
	./bin/$(NAME)

test_leaks: bin/$(NAME)
	$(VALGRIND) ./bin/$(NAME)
$(BIN_DIR):
	mkdir $(BIN_DIR)

$(BIN_DIR)/%.o: src/%.c $(LIBFT_DIR)/libft.h # $(BIN_DIR)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

