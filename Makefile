CC = cc
CFLAGS += -Wall -Wextra -Werror
NAME = libft_tester
C_FILES = ftlib_test.c ftt_lib_ctype.c

HEADER = include/$(NAME).h
SRC = include/$(HEADER) src/$(C_FILES)
#TODO replace src/%.c to bin/%.o
#OBJ = $(C_FILES:src/%.c=bin/%.o)

bin/%.o: $(SRC)
	$(CC) $(CFLAGS) -I../libft/ -c $< -o $@

bin/$(NAME):
	$(CC) -I../libft/ -o ./bin/$@ $(OBJ)

$(NAME): bin/$(NAME)
all: $(NAME)

fclean: clean
clean:
	rm -f $(OBJ) bin/$(NAME)

re: clean all
