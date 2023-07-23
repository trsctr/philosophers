# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 16:51:49 by oandelin          #+#    #+#              #
#    Updated: 2023/07/23 14:02:14 by oandelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	philo
CC			= 	cc
CFLAGS		= 	-Wall -Werror -Wextra -pthread
DBFLAG 		=	-g
THRDBFLAG	=	-fsanitize=thread
MEMDBFLAG 	=	-fsanitize=address
SRCDIR		=	src/
SRCFILES	= 	philo.c utils.c error.c actions.c init.c threads.c routine.c print.c
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
	$(CC) $(CFLAGS) $(DBFLAG) $(SRCS) -o $(NAME)

debugthreads:
	$(CC) $(CFLAGS) $(DBFLAG) $(THRDBFLAG) $(SRCS) -o $(NAME)

debugleaks:
	$(CC) $(CFLAGS) $(DBFLAG) $(MEMDBFLAG) $(SRCS) -o $(NAME)

clean:
	@echo "i'mg going to put here something once i figure out how to work the object files like I want"

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re debug debugthreads debugleaks