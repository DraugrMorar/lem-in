OBJ_DIR	 = ./obj

LIB_DIR	 = ./libft

NAME	 = lem-in

LIBFT 	 = $(LIB_DIR)/libft.a

SRC 	 = main.c \
		validation1.c \
		validation2.c \
		validation3.c \
		record.c \
		sets.c \
		allocation.c \
		free1.c \
		free2.c \
		print_res1.c \
		print_res2.c \
		bfs.c \
		block_del.c \
		add.c \
		alg1.c \
		alg2.c \
		alg3.c

OBJ 	 = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

CC	 = gcc

CFLAGS	 = -Wall -Wextra -Werror

LIB_INC  = -I $(LIB_DIR)/includes

LIB_LINK = -L $(LIB_DIR) -lft

all: $(NAME)

$(LIBFT):
	@make -C $(LIB_DIR) --no-print-directory

$(OBJ_DIR):
	@mkdir -p $@

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB_INC) $(LIB_LINK) -o $(NAME)
	@echo ✅ Lem-in Executable created.

$(addprefix $(OBJ_DIR)/, %.o):%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(LIB_INC) -c $< -o $@

clean:
	@make -C $(LIB_DIR) clean --no-print-directory
	rm -rf $(OBJ_DIR)
	@echo ❌ Lem-in Object files deleted.

fclean: clean
	@make -C $(LIB_DIR) fclean --no-print-directory
	rm -f $(NAME)
	@echo ❌ Lem-in Executable deleted.

re: fclean all