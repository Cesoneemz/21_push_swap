# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/11 14:59:03 by wlanette          #+#    #+#              #
#    Updated: 2022/01/25 16:52:31 by wlanette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
SRCS		= ./srcs/main.c ./srcs/ft_utils.c ./srcs/ft_validators.c \
			  ./srcs/ft_check_is_sorted.c ./srcs/ft_push_treatment.c \
			  ./srcs/ft_stack_treatment.c ./srcs/ft_stack_utils.c \
			  ./srcs/ft_swap_treatment.c ./srcs/ft_rotate_treatment.c \
			  ./srcs/ft_reverse_rotate_treatment.c ./srcs/ft_sorting_algs.c \
			  ./srcs/ft_separation.c ./srcs/ft_insertion_sort.c ./srcs/ft_find_place.c\
			  ./srcs/ft_getters.c ./srcs/ft_score_treatment.c
OBJS		= $(SRCS:.c=.o)

LIBFT		= ./libft/libft.a

INCS		= ./includes/
INCS_HEADER	= ./includes/push_swap.h

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I$(INCS) -g
RM			= rm -rf

all:		$(NAME)

$(NAME):	$(OBJS) $(INCS_HEADER) $(LIBFT) Makefile
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
			make bonus -C ./libft/

clean:		
			make clean -C ./libft/
			$(RM) $(OBJS)

fclean:		clean
			make fclean -C ./libft/
			$(RM) $(NAME)

re:			fclean all 

.PHONY:		all clean fclean re