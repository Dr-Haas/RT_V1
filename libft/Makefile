#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 19:03:44 by rmarracc          #+#    #+#              #
#    Updated: 2018/12/18 20:37:27 by rmarracc         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME 	= libft.a
SRC 	= ft_atoi.c ft_bs_islower.c ft_bs_isspace.c ft_bs_isupper.c ft_bs_lstpushback.c ft_bs_putarray.c ft_bs_putarray_fd.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c get_next_line.c sget_next_line.c
PRINTF 	= ft_printf/ft_parse_string.c ft_printf/ft_conversions.c ft_printf/ft_extra_func.c ft_printf/ft_flag_priority.c ft_printf/ft_init_arg.c ft_printf/ft_itoa_base.c ft_printf/ft_max.c ft_printf/ft_parse_char.c ft_printf/ft_parse_double.c ft_printf/ft_parse_hex.c ft_printf/ft_parse_octal.c ft_printf/ft_parse_percent.c ft_printf/ft_parse_pointer.c ft_printf/ft_parse_signed.c ft_printf/ft_parse_unsigned.c ft_printf/ft_parsing.c ft_printf/ft_printf.c
OBJ 	= $(SRC:.c=.o)
PFOBJ 	= $(PRINTF:.c=.o)
CC 		= @gcc
CFLAGS 	= -Wall -Wextra -Werror -I.

_GREEN =	$ \033[32m
_YELLOW =	$ \033[33m
_RED =		$ \033[31m
_END =		$ \033[0m

all : $(NAME)

$(NAME) : $(OBJ) $(PFOBJ) libft.h
	@ar rc $(NAME) $(OBJ) $(PFOBJ)
	@ranlib $(NAME)
	@printf "$(_GREEN)libft compiled\n$(_END)"

noprintf : $(OBJ) libft.h
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean :
	@rm -f $(OBJ) $(PFOBJ)
	@rm -f $(PFOBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re