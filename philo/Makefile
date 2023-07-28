NAME 		= 	philo
CC			= 	cc
CFLAGS		= 	-Wall -Werror -Wextra -pthread
DBFLAG 		=	-g
THRDBFLAG	=	-fsanitize=thread
MEMDBFLAG 	=	-fsanitize=address
SRCDIR		=	src/
SRCFILES	= 	philo.c utils.c print.c init.c party.c cleanup.c routine.c \
				monitoring.c actions.c
OBJ_DIR		= 	obj/
OBJFILES	= 	$(SRCFILES:.c=.o)
INC_DIR		=	include
HEADER		=	$(INC_DIR)/$(NAME).h
SRCS 		=	$(addprefix $(SRCDIR), $(SRCFILES))
OBJS		=	$(addprefix $(OBJ_DIR), $(OBJFILES))
RED 		:= 	\033[0;31m
GREEN 		:= 	\033[0;32m
YELLOW 		:= 	\033[0;33m
BLUE		:= 	\033[0;34m
MAGENTA		:= 	\033[0;35m
CYAN		:=	\033[0;36m
RESET 		:= 	\033[0m

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@echo "Creating directory $(CYAN)$(OBJ_DIR)$(RESET)"
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRCDIR)%.c $(HEADER)
	@echo "Building object file: $(CYAN)$@$(RESET) from source file $(MAGENTA)$<$(RESET)"
	@$(CC) $(CFLAGS) -I$(INC_DIR) $< -c -o $@

$(NAME): $(OBJS) $(HEADER)
	@echo "Compiling $(RED)philo$(RESET) binary"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Finished!$(RESET)"

debug:
	$(CC) $(CFLAGS) $(DBFLAG) $(SRCS) -o $(NAME)

debugthreads:
	$(CC) $(CFLAGS) $(DBFLAG) $(THRDBFLAG) $(SRCS) -o $(NAME)

debugleaks:
	$(CC) $(CFLAGS) $(DBFLAG) $(MEMDBFLAG) $(SRCS) -o $(NAME)

clean:
	@echo "Deleting $(CYAN)object$(RESET) files"
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)Object files deleted!$(RESET)"

fclean: clean
	@echo "Deleting $(RED)philo$(RESET) binary"
	@rm -rf $(NAME)
	@echo "$(GREEN)Philo binary deleted!$(RESET)"

re: fclean all

.PHONY: all clean fclean re debug debugthreads debugleaks