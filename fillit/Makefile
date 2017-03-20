OBJDIR := objs
SRCDIR := srcs
OBJLIST := \
	entry.o \
	fillit.o \
	main.o \
	map.o \
	piece.o \
	read.o \
	read_block.o
OBJS := $(addprefix $(OBJDIR)/,$(OBJLIST))
SRCS := $(addprefix $(SRCDIR)/,$(OBJLIST))
LIB := -L./libft -lft
CC := clang
INCDIR := -I./libft -I./inc
CFLAGS := -Wall -Wextra -Werror $(INCDIR)
NAME := fillit

.PHONY : all clean fclean re libft libft_clean libft_fclean

all : $(NAME)
	
$(NAME) : libft $(OBJS)
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
	
libft :
	make -C libft

libft_clean :
	make clean -C libft

libft_fclean :
	make fclean -C libft
