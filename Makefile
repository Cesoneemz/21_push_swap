# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/11 14:59:03 by wlanette          #+#    #+#              #
#    Updated: 2022/01/27 18:14:57 by wlanette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
NAME_B		= checker
SRCS		= ./srcs/main.c ./srcs/ft_utils.c ./srcs/ft_validators.c \
			  ./srcs/ft_check_is_sorted.c ./srcs/ft_push_treatment.c \
			  ./srcs/ft_stack_treatment.c ./srcs/ft_stack_utils.c \
			  ./srcs/ft_swap_treatment.c ./srcs/ft_rotate_treatment.c \
			  ./srcs/ft_reverse_rotate_treatment.c ./srcs/ft_sorting_algs.c \
			  ./srcs/ft_separation.c ./srcs/ft_insertion_sort.c ./srcs/ft_find_place.c \
			  ./srcs/ft_getters.c ./srcs/ft_score_treatment.c
OBJS		= $(SRCS:.c=.o)

SRCS_B		= ./srcs/ft_checker.c ./srcs/ft_utils.c ./srcs/ft_validators.c \
			  ./srcs/ft_check_is_sorted.c ./srcs/ft_stack_treatment.c ./srcs/ft_stack_utils.c \
			  ./srcs/ft_separation.c ./includes/gnl/get_next_line.c ./includes/gnl/get_next_line_utils.c \
			  ./srcs/ft_push_treatment.c ./srcs/ft_swap_treatment.c ./srcs/ft_rotate_treatment.c \
			  ./srcs/ft_reverse_rotate_treatment.c
OBJS_B		= $(SRCS_B:.c=.o)

LIBFT		= ./includes/libft/libft.a

INCS		= ./includes/
INCS_HEADER	= ./includes/push_swap.h


CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I$(INCS)
RM			= rm -rf

all:		$(NAME) bonus

$(NAME):	$(OBJS) $(INCS_HEADER) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
			make bonus -C ./includes/libft/

clean:		
			make clean -C ./includes/libft/
			$(RM) $(OBJS) $(OBJS_B)

fclean:		clean
			make fclean -C ./includes/libft/
			$(RM) $(NAME) $(NAME_B)

re:			fclean all 

bonus:		$(NAME_B)

$(NAME_B):	$(OBJS_B) $(INCS_HEADER) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJS_B) $(LIBFT) -o $(NAME_B)

.PHONY:		all clean fclean re bonus