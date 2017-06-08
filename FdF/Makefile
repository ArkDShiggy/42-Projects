OBJDIR := objs
SRCDIR := srcs
OBJLIST := main.o read.o image.o hooks.o midpoint.o
OBJS := $(addprefix $(OBJDIR)/,$(OBJLIST))
SRCS := $(addprefix $(SRCDIR)/,$(OBJLIST))
LIB := -L./libft libft.a libmlx.a -lmlx -framework OpenGL -framework AppKit
CC := clang
INCDIR := -I./libft/includes -I./includes
CFLAGS := -Wall -Wextra -Werror $(INCDIR)
NAME := fdf

.PHONY : all clean fclean re libft_clean libft_fclean

all : $(NAME)

$(NAME) :	$(OBJS) libft.a libmlx.a
			gcc -o $@ $(LIB) $(OBJS)

$(OBJDIR)/%.o : $(SRCDIR)/%.c includes/fdf.h
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

clean : libft_clean libmlx_clean
	-rm -r $(OBJDIR)

fclean : libft_fclean libmlx_fclean
	-rm $(NAME)
	-rm -r $(OBJDIR)

re : fclean all

libmlx.a :
	make -C minilibx_macos
	cp minilibx_macos/libmlx.a .

libft.a :
	make -C libft
	cp libft/libft.a .

libft_clean :
	make clean -C libft

libft_fclean :
	-rm libft.a
	make fclean -C libft

libmlx_clean :
	make clean -C minilibx_macos

libmlx_fclean :
	rm libmlx.a
		make clean -C minilibx_macos
