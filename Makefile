CC = cc
CFLAGS += -Wall -Wextra -Werror -g
export FT_EXTRA_CFLAGS += -g
# -fprofile-arcs -ftest-coverage -O1
# before an include!
NAME = libft_test
# $(shell basename $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST)))))
C_SRC += ftt_utils.c
C_SRC += ftt_lib_meta.c
C_SRC += ftt_lib_ctype.c
C_SRC += ftt_lib_mem.c
C_SRC += ftt_lib_str.c
C_SRC += ftt_lib_fmt.c
C_SRC += ftt_lib_iol.c
C_SRC += ftt_lib_toa.c
C_SRC += ftt_lib_kv.c
C_SRC += ftt_lib_arr.c
C_SRC += ftt_lib_lst.c

LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a
VALGRIND = valgrind -q --trace-children=yes
FUNCHECK = funcheck

C_DIR = ./src
BIN_DIR = ./bin
OBJ = $(C_SRC:%.c=$(BIN_DIR)/%.o)

.PHONY: fclean clean re all test run $(LIBFT) ride test_leaks

$(NAME): bin/$(NAME)
pg: bin/pg
all: $(NAME)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean

clean:
	rm -f ./$(BIN_DIR)/*

re: clean all

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(BIN_DIR)/$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -lcriterion -o $@ $(OBJ) $(LIBFT)

$(BIN_DIR)/pg: src/ftt_utils.c src/pg.c $(LIBFT)
	$(CC) $(CFLAGS) src/ftt_utils.c src/pg.c -I$(LIBFT_DIR) -lbsd -o $@ $(LIBFT)

test: bin/$(NAME)
	./bin/$(NAME)

ride: bin/pg
	$(FUNCHECK) bin/pg

test_leaks: bin/$(NAME)
	$(VALGRIND) ./bin/$(NAME)

$(BIN_DIR):
	mkdir $(BIN_DIR)

$(BIN_DIR)/%.o: src/%.c $(BIN_DIR)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

