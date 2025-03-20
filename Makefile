NAME = philo
BONUS = philo_bonus
HEADER = philo.h

CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar -rcs
LIBFT = libft/libft.a

GREEN = \033[0;32m
BLUE = \033[0;34m
YELLOW = \033[0;33m
RESET = \033[0m

PHILO = philo_life
INFO = info_struct
UTILS = utils_file
SRC = main.c $(INFO)/args_check.c $(INFO)/create_arrays.c $(INFO)/fill_info.c \
      $(UTILS)/clean.c $(UTILS)/print.c $(UTILS)/utils.c \
      $(PHILO)/philo_act.c $(PHILO)/philo.c
B_SRC = bonus.c

OBJ_DIR = obj
OBJ_FILES = $(SRC:%.c=$(OBJ_DIR)/%.o)
B_OBJ_FILES = $(B_SRC:%.c=$(OBJ_DIR)/%.o)

all : $(NAME)
	@echo ""
	@echo "$(YELLOW)"
	@cat art/philo.txt
	@cat art/coine.txt
	@echo "$(RESET)"

$(NAME) : $(OBJ_FILES)  $(LIBFT)
	@echo "$(GREEN)making philo...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ_FILES)  $(LIBFT) -o $(NAME)

bonus : $(B_OBJ_FILES) $(LIBFT)
	@echo "$(GREEN)making philo_bonus...$(RESET)"
	@$(CC) $(CFLAGS) $(B_OBJ_FILES)  $(LIBFT) -o $(BONUS)

$(LIBFT):
	@echo "$(GREEN)making libft...$(RESET)"
	@make all -C libft

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(BLUE)cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@make clean -C libft

fclean: clean
	@echo "$(BLUE)cleaning program...$(RESET)"
	@rm -rf $(NAME) $(BONUS)
	@make fclean -C libft

re: fclean all

.PHONY : all fclean clean re bonus