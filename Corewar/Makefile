# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 09:47:44 by ndombre           #+#    #+#              #
#    Updated: 2017/03/20 17:58:24 by jcatinea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

WORDIR=./tmp
BUILDDIR=$(WORDIR)

DEP=Makefile libft/blist.h libft/btree.h libft/btree/btree.h libft/ft_printf/ft_printf.h libft/get_next_line.h libft/libft.h includes
PDEP=libft/libft libft/blist libft/btree libft/ft_printf libft/get_next_line libft includes

#OBJ COMMON
BASSE_SRC= op.c
SRC=$(addprefix com_src/,$(BASSE_SRC))
OBJ=$(addprefix $(BUILDDIR)/obj/,$(SRC:.c=.o))

#OBJ ASM
ASM=asm
BASSE_SRC_ASM= asm_main.c asm_error.c asm_env.c asm_header.c asm_parse.c \
asm_write.c asm_line.c asm_args.c asm_free.c asm_args2.c ft_lstappend.c\
ft_secure_atoi.c asm_header2.c

SRC_ASM=$(addprefix asm_src/,$(BASSE_SRC_ASM))
OBJ_ASM=$(addprefix $(BUILDDIR)/obj/,$(SRC_ASM:.c=.o))

#OBJ CORWAR
VM=corewar
MAIN_BASSE_SRC_VM=main.c


BASSE_SRC_VM=	./get/get_champion.c 			\
				./get/get_header.c 				\
				./get/get_content.c 			\
				./debug/debug_champion.c		\
				./debug/dump_memory.c 			\
				./debug/debug_vm.c				\
				./debug/debug_temp.c			\
				./parsing/parse_args.c 			\
				./parsing/parse_uids.c 			\
				./process_fcts/add_process.c	\
				./process_fcts/create_process.c	\
				./process_fcts/delete_process.c	\
				./process_fcts/fork_process.c	\
				./process_fcts/gen_process.c	\
				./corelib/get_pc.c				\
				./corelib/set_pc.c				\
				./corelib/get_carry.c			\
				./corelib/change_carry.c		\
				./corelib/set_reg.c				\
				./corelib/get_reg.c				\
				./corelib/get_ind.c				\
				./corelib/set_ind.c				\
				./corelib/decode_info.c 		\
				./corelib/ft_magic_params.c		\
   				./corelib/code_param.c			\
   				./corelib/real_to_fake_uid.c	\
				./web/file_fcts.c				\
				./web/json_cycle.c				\
				./web/json_memory.c				\
				corelib/processe_len.c			\
				load_champs.c 					\
				struct_init.c 					\
				setup_memory.c					\
				get_ind_of.c					\
				set_ind_of.c					\
				instruction/instruction.c		\
				instruction/instruction_1.c		\
				instruction/instruction_2.c		\
				instruction/instruction_3.c		\
   				instruction/instruction_4.c		\
				./termcaps/termcap.c			\
				./termcaps/termcap_ini.c		\
				ft_secure_atoi.c				\
				cycle.c							\
				cycle2.c						\
				song.c							\
				free_fcts.c						\
				end_printf.c


SRC_VM=$(addprefix vm_src/,$(BASSE_SRC_VM)) $(addprefix vm_src/,$(MAIN_BASSE_SRC_VM))
OBJ_VM=$(addprefix $(BUILDDIR)/obj/,$(SRC_VM:.c=.o))

SRC_LIB_VM=$(addprefix vm_src/,$(BASSE_SRC_VM))
OBJ_LIB_VM=$(addprefix $(BUILDDIR)/obj/,$(SRC_LIB_VM:.c=.o))



.PHONY: all clean fclean re

all: $(ASM)

$(BUILDDIR)/obj/%.o: %.c $(DEP)
	@mkdir -p $(dir $@)
	gcc -g -Wall -Werror -Wextra -I./includes -I./libft -I./libft/libunit/ -o $@ -c $<

clean:
	make -C libft fclean
	rm -rf $(WORDIR)

fclean: clean
	rm -f $(ASM) || true
	rm -f $(VM) || true
	rm -rf $(VM).dSYM || true
	rm -rf $(ASM).dSYM || true

re: fclean
	make

$(ASM): $(OBJ) $(OBJ_ASM) $(PDEP)
	make -C libft libft.a
	gcc -Wall -Werror -Wextra -o $(ASM) $(OBJ) $(OBJ_ASM) libft/libft.a -I./libft/

$(VM): $(OBJ) $(OBJ_VM) $(PDEP)
	make -C libft libft.a
	gcc -Wall -Werror -Wextra -o $(VM) $(OBJ) $(OBJ_VM) libft/libft.a -lcurses -I./libft/

make_corwar: corewar
	@echo "\033[0;33m"
	ls -la corewar
	./corewar || true
	@echo "\033[0m"

make_asm: asm
	@echo "\033[0;33m"
	ls -la asm
	./asm || true
	@echo "\033[0m"
