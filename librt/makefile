# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghaas <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/04 19:38:09 by ghaas             #+#    #+#              #
#    Updated: 2019/01/28 11:55:40 by rmarracc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



SRCS 		=	ft_vset.c 				\
				ft_vsum.c 				\
				ft_vsub.c 				\
				ft_vmul.c 				\
				ft_vdiv.c 				\
				ft_vdot.c 				\
				ft_vsqrd.c 				\
				ft_vnorm.c 				\
				ft_vcross.c 			\

OBJS		=	$(SRCS:.c=.o)

NAME 		=	librt.a

CC 			=	clang

CFLAGS 		=	-Wall -Wextra -Werror

_GREEN 		=	$ \033[32m
_YELLOW 	=	$ \033[33m
_RED 		=		$ \033[31m
_END 		=		$ \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@gcc $(CFLAGS) -I. -c $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@printf "$(_GREEN)librt compiled\n$(_END)"

%.o: %.c
	@$(CC) -c $(CFLAGS) -I. $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY : clean fclean all re


