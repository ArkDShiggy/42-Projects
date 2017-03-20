#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/01 18:19:05 by jcatinea          #+#    #+#              #
#    Updated: 2016/12/02 10:04:56 by jcatinea         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

OBJDIR := objs
SRCDIR := srcs
OBJLIST := \
	printf_eval.o printf_main.o printf_list.o printf_conversion.o \
	printf_types.o printf_types2.o printf_types3.o printf_types4.o \
	printf_wctos.o printf_adjust.o printf_itoa.o printf_uitoa_base.o\
	ft_strinc.o ft_putwchar.o ft_putwstr.o \
	xt_error.o \
	ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o \
	ft_isascii.o ft_isdigit.o ft_isprint.o ft_itoa.o \
	ft_lstadd.o ft_lstdel.o ft_lstdelone.o ft_lstiter.o \
	ft_lstmap.o ft_lstnew.o ft_memalloc.o ft_memccpy.o \
	ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memdel.o \
	ft_memmove.o ft_memset.o ft_putchar.o ft_putchar_fd.o \
	ft_putendl.o ft_putendl_fd.o ft_putnbr.o ft_putnbr_fd.o \
	ft_putstr.o ft_putstr_fd.o ft_strcat.o ft_strchr.o \
	ft_strclr.o ft_strcmp.o ft_strcpy.o ft_strdel.o \
	ft_strdup.o ft_strequ.o ft_striter.o ft_striteri.o \
	ft_strjoin.o ft_strlcat.o ft_strlen.o ft_strmap.o \
	ft_strmapi.o ft_strncat.o ft_strncmp.o ft_strncpy.o \
	ft_strnequ.o ft_strnew.o ft_strnstr.o ft_strrchr.o \
	ft_strsplit.o ft_strstr.o ft_strsub.o ft_strtrim.o \
	ft_tolower.o ft_toupper.o

OBJS := $(addprefix $(OBJDIR)/,$(OBJLIST))
SRCS := $(addprefix $(SRCDIR)/,$(OBJLIST))
LIB := -L./libft -lft
CC := clang
INCDIR := -I./includes
CFLAGS := -Wall -Wextra -Werror $(INCDIR)
NAME := libftprintf.a

.PHONY : all clean fclean re


$(NAME) : $(OBJS)
			ar rc $(NAME) $(OBJS)

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

all   : $(NAME)

clean :
	-rm -r $(OBJDIR)

fclean :
	-rm $(NAME)
	-rm -r $(OBJDIR)

re : fclean all
