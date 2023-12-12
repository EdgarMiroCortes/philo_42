#==================COLORS==================#

GREEN   =   \033[38;5;154m
RED     =   \033[38;5;197m
PURPLE  =   \033[38;5;171m
BLUE    =   \033[38;5;14m
NC      =   \033[0m
YELLOW  =   \033[38;5;190m

#=================COMMANDS=================#

NAME        =   philo
DIR_OBJ		=	temp/
CC          =   gcc
CFLAGS  =   -Wall -Wextra -Werror
INCLUDE =   -I./inc -I./readline
RM          =   rm -fr

SRC = philo.c utils.c init.c #parsing.c routine.c supervisor.c

OBJ     =   $(addprefix $(DIR_OBJ), $(SRC:.c=.o))

#==================RULES===================#

all : temp $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $@
	@echo "${GREEN}Philo Compiled${NC}"

$(DIR_OBJ)%.o: %.c Makefile $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "${YELLOW}Compiling obj $@...${NC}"

temp    :
	@mkdir -p $(DIR_OBJ)

clean   :
	@$(RM) $(DIR_OBJ)
	@printf "${RED}Objs deleted\n${NC}"

fclean  : clean
	@$(RM) $(NAME)
	@printf "${RED}Philo deleted\n${NC}"

norm    :
	@printf "${PURPLE}SEARCHING FOR A PRINTF IN THE PROJECT: "
	@printf "%i \n${NC}" $(shell grep "printf" *.c | wc -l)
	@printf "${YELLOW}Norminette...\n${NC}"
	@printf "${RED}"
	@norminette src/*/*.c src/*.c inc/*.h *.c > test && printf "$(GREEN)\t[OK]\n" || grep Error test
	@printf "${NC}"
	@rm test

re      : fclean all

.PHONY : all clean fclean norm re
