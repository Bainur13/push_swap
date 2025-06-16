#Colors / base 16 / Bright

DEF_COLOR		= \033[0;39m
GRAY			= \033[0;90m
RED				= \033[0;91m
GREEN			= \033[0;92m
YELLOW			= \033[0;93m
BLUE			= \033[0;94m
MAGENTA			= \033[0;95m
CYAN			= \033[0;96m
WHITE			= \033[0;97m

#Colors / Perso / Bright

ORANGE			= \033[38;5;214m

#Libft

LIBFT_DIR		= Includes/libft/
LIBFT_NAME		= libft.a
LIBFT			= $(LIBFT_DIR)$(LIBFT_NAME)

#Printf

PRINTF_DIR		= Includes/ft_printf/
PRINTF_NAME		= libftprintf.a
PRINTF			= $(PRINTF_DIR)$(PRINTF_NAME)

#Variables

NAME	= push_swap
CC		=  cc
FLAGS	= -Wall -Werror -Wextra -g3
RM				= rm -f
AR				= ar rcs
NORM			= ./includes\
					./libft/include/\
					s./libft/src_lib
INCLUDE			= 	-I ./includes/\
					-I ./libft/\
					-I ./ft_printf/\
					-I ./get_next_line/

#Sources

OBJ_DIR_F 		= obj/
SRC_DIR_F		= src/
BONUS_DIR_F		= checker42/get_next_line/
SRC_FUNCTIONS_F	= main \
					check parse utils utils2 utils3 \
					instructions more_instructions set_up_algo \
					algo_part1 algo_part2 algo_part3 get_groups push_by_groups

PS_SRC		= $(addprefix $(SRC_DIR_F), $(addsuffix .c, $(SRC_FUNCTIONS_F)))
PS_OBJ		= $(addprefix $(OBJ_DIR_F), $(addsuffix .o, $(SRC_FUNCTIONS_F)))

#Bonus

NAME_BONUS	= checker

#Sources_bonus

SRC_BONUS	= 	check parse utils utils2 utils3 instructions \
				more_instructions set_up_algo algo_part1 algo_part2 \
				algo_part3 get_groups push_by_groups\

BONUS_SRC	= $(addprefix $(SRC_DIR_F), $(addsuffix .c, $(SRC_BONUS))) checker42/get_next_line/get_next_line_utils.c checker42/get_next_line/get_next_line.c  checker42/checker.c
BONUS_OBJ	= $(addprefix $(OBJ_DIR_F), $(addsuffix .o, $(SRC_BONUS))) checker42/get_next_line/get_next_line_utils.o checker42/get_next_line/get_next_line.o  checker42/checker.o

#Cache

IFMAKE_DIR_F	= .cache_exists

#instructions

all:			$(LIBFT) $(PRINTF) $(NAME)

$(IFMAKE_DIR_F):
					@mkdir -p $(OBJ_DIR_F)
					@mkdir -p $(OBJ_DIR_F)push_swap/

$(LIBFT):
					@echo "Getting libft ready"
					@make -sC $(LIBFT_DIR)

$(PRINTF):
					@echo "Getting printf ready"
					@make -sC $(PRINTF_DIR)

$(OBJ_DIR_F)%.o: $(SRC_DIR_F)%.c | $(IFMAKE_DIR_F)
					@echo "$(ORANGE)Loading... $< $(DEF_COLOR)"
					@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@


$(OBJ_DIR_F)push_swap/%.o: $(SRC_DIR_F)push_swap/%.c | $(IFMAKE_DIR_F)
					@echo "$(ORANGE)Loading... $< $(DEF_COLOR)"
					@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@



$(NAME): $(PS_OBJ) $(LIBFT) $(PRINTF)
					@echo "Compiling push_swap..."
					@$(CC) $(FLAGS) -o $(NAME) $(PS_OBJ) $(LIBFT) $(PRINTF) $(INCLUDE) -g3
					@echo "push_swap ready."


bonus:			$(NAME_BONUS)

$(NAME_BONUS): $(BONUS_OBJ) $(LIBFT) $(PRINTF)
	@echo "Compiling checker..."
	@$(CC) $(FLAGS) -o $(NAME_BONUS) $(BONUS_OBJ) $(LIBFT) $(PRINTF) $(INCLUDE) -g3
	@echo "checker ready."

$(BONUS_DIR_F)checker42/%.o: $(SRC_DIR_F)push_swap/%.c | $(IFMAKE_DIR_F)
					@echo "$(ORANGE)Loading... $< $(DEF_COLOR)"
					@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

$(BONUS_DIR_F)%.o: $(SRC_DIR_F)%.c | $(IFMAKE_DIR_F)
					@echo "$(ORANGE)Loading... $< $(DEF_COLOR)"
					@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@



clean:
					@echo "Removing object files"
					@rm -rf $(OBJ_DIR_F)
					@make clean -C $(LIBFT_DIR)
					@make clean -C $(PRINTF_DIR)
					
fclean:			clean
					@echo "Removing push_swap..."
					@rm -f $(NAME)
					@rm -f $(LIBFT_DIR)$(LIBFT_NAME)
					@rm -f $(PRINTF_DIR)$(PRINTF_NAME)

clean_all :		fclean
					@echo "Removing checker..."
					@rm -f ./checker42/*.o
					@rm -f ./checker42/get_next_line/*.o
					@rm -f ./checker

re:				fclean all
					@echo "$(BLUE)Cleaned and rebuilt everything for push_swap$(DEF_COLOR)"

norm:
					@norminette $(SRC_DIR_F) $(NORM) $(LIBFT_DIR) $(PRINTF_DIR) | grep -v Norme -B1 || true
					@echo "Norminet the cat says : $(RED)M$(ORANGE)e$(YELLOW)o$(GREEN)w$(CYAN) !$(BLUE)!$(MAGENTA)!$(DEF_COLOR)"

.PHONY: all re clean fclean norm bonus