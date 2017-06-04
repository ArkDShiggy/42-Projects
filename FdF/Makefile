OBJDIR := objs
SRCDIR := srcs
OBJLIST := main.o read.o test.o
OBJS := $(addprefix $(OBJDIR)/,$(OBJLIST))
SRCS := $(addprefix $(SRCDIR)/,$(OBJLIST))
LIB := -L./libft libft.a libmlx.a -lmlx -framework OpenGL -framework AppKit
CC := clang
INCDIR := -I./libft/includes -I./includes
CFLAGS := -Wall -Wextra -Werror $(INCDIR)
NAME := fdf

.PHONY : all clean fclean re libft.a libft_clean libft_fclean

all : $(NAME)

$(NAME) :	$(OBJS) libft.a
			gcc -o $@ $(LIB) $(OBJS)

$(OBJDIR)/%.o : $(SRCDIR)/%.c
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

clean : libft_clean
	-rm libft.a
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
	make fclean -C libft
