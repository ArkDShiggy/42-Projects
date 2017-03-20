# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndombre <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/15 11:18:26 by ndombre           #+#    #+#              #
#    Updated: 2017/03/03 15:54:46 by cfabre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM=real/asm
COR=real/corwar
TMP=compile

ASM_R=../asm
COR_R=../corwar
TMP_R=tmp/user

S_TEST=source/Car.s\
	   source/Gagnant.s\
	   source/barriere.s\
	   source/basic.s\
	   source/cursor.s\
	   source/durex.s\
	   source/ex.s\
	   source/jumper.s\
	   source/maxidef.s\
	   source/mortel.s\
	   source/slider2.s\
	   source/test.s

COR_TEST=$(S_TEST:.s=.cor)

ccred=$(echo -e "\033[0;31m")
ccyellow=$(echo -e "\033[0;33m")
ccend=$(echo -e "\033[0m")

all: test

%.cor: %.s $(ASM) $(ASM_R)
	@echo
	@echo "\033[0;33m"
	@echo "#    test for" $@
	@echo "\033[0m"
	@mkdir -p $(TMP_R)
	$(ASM_R) $<
	mv $@ $(TMP_R)

	#@mkdir -p $(TMP)
	#$(ASM) $<
	#mv $@ $(TMP)

	diff $(TMP_R)/$(notdir $@) $(TMP)/$(notdir $@)

test:
	@echo "\033[0;31m"
	@echo YOU RUN TEST
	@echo "\033[0m"
	rm -rf $(TMP_R)
	make $(COR_TEST)
