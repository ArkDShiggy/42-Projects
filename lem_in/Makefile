OBJDIR := objs
SRCDIR := srcs
OBJLIST := main.o links.o rooms.o search.o read.o larray.o print.o \
explore.o paths.o ft_lstappend.o free.o update_link.o solve.o
OBJS := $(addprefix $(OBJDIR)/,$(OBJLIST))
SRCS := $(addprefix $(SRCDIR)/,$(OBJLIST))
LIB := -L./libft -lft
CC := clang
INCDIR := -I./libft/includes -I./includes
CFLAGS := -Wall -Wextra -Werror $(INCDIR)
NAME := lem_in

.PHONY : all clean fclean re libft/libft.a libft_clean libft_fclean

all : $(NAME)

$(NAME) :	libft/libft.a $(OBJS)
			gcc -o $@ $(LIB) $(OBJS)

$(OBJDIR)/%.o : $(SRCDIR)/%.c
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

clean : libft_clean
	-rm -r $(OBJDIR)

fclean : libft_fclean
	-rm $(NAME)
	-rm -r $(OBJDIR)

re : fclean all

libft/libft.a :
	make -C libft

libft_clean :
	make clean -C libft

libft_fclean :
	make fclean -C libft
