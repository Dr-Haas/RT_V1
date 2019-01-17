# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghaas <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/04 19:38:25 by ghaas             #+#    #+#              #
#    Updated: 2019/01/06 22:14:03 by rmarracc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME 	=	rtv1

LIBMLX 	=	-L minilibx_macos/ -lmlx -framework OpenGL -framework Appkit

LIBFT 	=	LIBFT
LIBRT 	=	LIBRT
LIBS 	=	librt/librt.a libft/libft.a

CC 		=	clang
CFLAGS 	=	-Wall -Wextra -Werror

SRCS 	=	sources/main.c \
			sources/ft_get_env.c \
			sources/ft_set_obj.c \
			sources/ft_set_env.c \
			sources/ft_lfill.c \
			sources/ft_file_copy.c \
			sources/ft_file_check.c \
			sources/ft_put_env.c \
			sources/ft_intersect.c \
			sources/ft_draw_scene.c \
			sources/ft_get_color.c  \

OBJS 	=	$(SRCS:.c=.o)

_GREEN 	=	$ \033[32m
_YELLOW =	$ \033[33m
_RED 	=	$ \033[31m
_END 	=	$ \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT)
	@$(MAKE) -C $(LIBRT)
	@gcc $(CFLAGS) -o $(NAME) -I /usr/local/include/ $(OBJS) $(LIBS) $(LIBMLX)
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
	@$(CC) -c $(CFLAGS) -I. $< -o $@ 

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
	@rm -f $(NAME)
	@printf "$(_YELLOW)rtv1 fcleaned\n"

re: fclean all

.PHONY: libft librt clean fclean all re
