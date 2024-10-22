# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 22:26:49 by sel-kham          #+#    #+#              #
#    Updated: 2022/04/24 23:52:53 by sel-kham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################# COLORS #################
RED := \033[0;31m
WHITE := \033[0;37m
GREEN := \033[0;32m
################# COLORS #################

CFLAGS := -Wall -Wextra -Werror

SRC_DIR := src
OBJ_DIR := obj
INC_DIR := includes

LIBFT_DIR := $(INC_DIR)/libft
PRINTF_DIR := $(INC_DIR)/ft_printf
GNL_DIR := $(INC_DIR)/get_next_line
HEADERS_DIR := $(INC_DIR)/headers

HEADERS := $(HEADERS_DIR)/push_swap.h
PRINTF := $(PRINTF_DIR)/libftprintf.a
LIBFT := $(LIBFT_DIR)/libft.a
GNL := $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c

HELPERS_DIR := $(SRC_DIR)/helpers
APP_DIR := $(SRC_DIR)/app
BONUS_DIR := $(SRC_DIR)/bonus

SRC := $(HELPERS_DIR)/ft_error.c $(HELPERS_DIR)/doubly_linked_list.c $(HELPERS_DIR)/push_swap_utilities.c $(HELPERS_DIR)/ft_insertion_sort.c \
	$(APP_DIR)/manage_stacks.c $(APP_DIR)/manage_inputs.c $(APP_DIR)/manage_stack_merg.c $(APP_DIR)/push_swap.c $(APP_DIR)/ft_lis.c $(APP_DIR)/ft_lis_sorting.c $(APP_DIR)/execute_instructions.c

OBJ := $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

MAIN := $(SRC_DIR)/main.c

NAME := push_swap

CHECKER := checker

all: $(NAME)

bonus: $(GNL) $(SRC_BNS) $(HEADERS) $(SRC) $(PRINTF) $(LIBFT)
	@echo "$(GREEN)Making $(WHITE)checker file..."
	@$(CC) $(CFLAGS) $(GNL) $(SRC) $(PRINTF) $(LIBFT) $(BONUS_DIR)/sorting_checker.c -o $(CHECKER)

$(NAME): $(MAIN) $(HEADERS) $(LIBFT) $(PRINTF) $(OBJ)
	@echo "$(GREEN)Making $(WHITE)push_swap file..."
	@$(CC) $(CFLAGS) $(MAIN) $(LIBFT) $(PRINTF) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(HELPERS_DIR)/%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(APP_DIR)/%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): $(shell find $(LIBFT_DIR) -name "*.c" -type f)
	@echo "$(GREEN)Making $(WHITE)libft files..."
	@$(MAKE) -C $(LIBFT_DIR)/

$(PRINTF): $(shell find $(PRINTF_DIR) -name "*.c" -type f)
	@echo "$(GREEN)Making $(WHITE)ft_printf files..."
	@$(MAKE) -C $(PRINTF_DIR)/

clean:
	@echo "$(RED)Removing $(WHITE)push_swap object files..."
	@rm -rf $(NAME)
	@echo "$(RED)Removing $(WHITE)ft_printf object files..."
	@$(MAKE) -C $(PRINTF_DIR)/ clean
	@echo "$(RED)Removing $(WHITE)libft object files..."
	@$(MAKE) -C $(LIBFT_DIR)/ clean

fclean: clean
	@echo "$(RED)Removing $(WHITE)push_swap executable file..."
	@rm -rf $(OBJ_DIR)/*.o
	@echo "$(RED)Removing $(WHITE)ft_printf static library file..."
	@$(MAKE) -C $(PRINTF_DIR)/ fclean
	@echo "$(RED)Removing $(WHITE)libft static library file..."
	@$(MAKE) -C $(LIBFT_DIR)/ fclean
	@echo "$(RED)Removing $(WHITE)checker executable file..."
	@rm -rf $(CHECKER)

re: fclean all
