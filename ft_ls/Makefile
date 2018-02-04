OBJDIR := objs
SRCDIR := srcs
OBJLIST := btree.o compare.o env.o main.o node.o stat.o
OBJS := $(addprefix $(OBJDIR)/,$(OBJLIST))
SRCS := $(addprefix $(SRCDIR)/,$(OBJLIST))
LIB := -L./libft libft.a
CC := clang
INCDIR := -I./libft/includes -I./includes
CFLAGS := -Wall -Wextra -Werror $(INCDIR)
NAME := ft_ls

.PHONY : all clean fclean re libft_clean libft_fclean

all : $(NAME)

$(NAME) :	$(OBJS) libft.a
			gcc -o $@ $(LIB) $(OBJS)

$(OBJDIR)/%.o : $(SRCDIR)/%.c includes/ft_ls.h
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

libft.a :
	make -C libft
	cp libft/libft.a .

libft_clean :
	make clean -C libft

libft_fclean :
	-rm libft.a
	make fclean -C libft
