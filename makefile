# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghaas <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/04 19:38:25 by ghaas             #+#    #+#              #
#    Updated: 2019/01/28 12:07:00 by ghaas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME 	=	rtv1

LIBMLX 	=	-L minilibx_macos/ -lmlx -framework OpenGL -framework Appkit

LIBFT 	=	LIBFT
LIBRT 	=	LIBRT
LIBS 	=	librt/librt.a libft/libft.a

CC 		=	clang
CFLAGS 	=	-Wall -Wextra -Werror

SRCS 	=	sources/main.c 			\
			sources/lstdel_func.c 	\
			sources/parse_bin.c 	\
			sources/print_data.c	\
			sources/mlx_init.c		\
			sources/raytrace.c		\
			sources/intersect.c		\
			sources/color.c			\
			sources/equation.c		\
			sources/light.c			\
			sources/extra.c			\

OBJS 	=	$(SRCS:.c=.o)

_GREEN 	=	$ \033[32m
_YELLOW =	$ \033[33m
_RED 	=	$ \033[31m
_END 	=	$ \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT)
	@$(MAKE) -C $(LIBRT)
	@$(MAKE) -C minilibx_macos/
	@$(CC) $(CFLAGS) -o $(NAME) -Iincludes/ $(OBJS) $(LIBS) $(LIBMLX) -fsanitize=address
	@printf "$(_GREEN)rtv1 compiled\n$(_END)"
	@echo "\033[34m"
	@echo "\033[38;5;24m  MMMºººAMV      MMºººMM        MMºººMM    MMºººMm"
	@echo " MM             MM     MM'     MM     MM   MM    Mm"
	@echo "\033[38;5;25m MM            MM       MM'   MM       MM  MM     mm"
	@echo " MM            MM       MM'   MM       MM  MM      M"
	@echo "\033[38;5;26m MM   AMVMMAMV MM       MM'   MM       MM  MM     mm"
	@echo " MM      MM     MM     MM'     MM     MM   MM    Mm"
	@echo "\033[38;5;27m  AMVmmmmMM      MMwwwMM        MMwwwMM    MMwwwMM "
	@echo ""
	@echo "\033[38;5;32m [2018]                    [${LOGIN}]\033[0m"

%.o: %.c
	@$(CC) -c $(CFLAGS) -Iincludes/ $< -o $@ 

clean:
	@$(MAKE) clean -C $(LIBFT)
	@$(MAKE) clean -C $(LIBRT)
	@rm -f $(OBJS)
	@printf "$(_RED)libft cleaned\n"
	@printf "$(_RED)librt cleaned\n"
	@printf "$(_RED)rtv1 cleaned\n"

fclean: clean
	@$(MAKE) fclean -C $(LIBFT)
	@$(MAKE) fclean -C $(LIBRT)
	@$(MAKE) clean -C minilibx_macos/
	@rm -f $(NAME)
	@printf "$(_YELLOW)rtv1 fcleaned\n"

re: fclean all

.PHONY: libft librt clean fclean all re
