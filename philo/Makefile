# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trsctr <trsctr@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 16:51:49 by oandelin          #+#    #+#              #
#    Updated: 2023/07/18 12:28:25 by trsctr           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	philo
CC			= 	cc
CFLAGS		= 	-Wall -Werror -Wextra
DBFLAGS		=	-g -fsanitize=thread
SRCDIR		=	src/
SRCFILES	= 	philo.c utils.c error.c actions.c
OBJ_DIR		= 	obj/
OBJFILES	= 	$(SRCFILES:.c=.o)
INC_DIR		=	include
HEADER		=	$(INC_DIR)/($NAME).h
SRCS 		=	$(addprefix $(SRCDIR), $(SRCFILES))
OBJS		=	$(addprefix $(OBJDIR), $(OBJFILES))

all: $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	
debug:
	$(CC) $(CFLAGS) $(DBFLAGS) $(SRCS) -o $(NAME)

clean:
	@echo "jooh"

fclean: clean
	rm -rf $(NAME)
	@echo "\033[0;91m* $(NAME) was deleted *\033[0m"

re: fclean all

.PHONY: all clean fclean re