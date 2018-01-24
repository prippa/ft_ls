# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prippa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 14:20:39 by prippa            #+#    #+#              #
#    Updated: 2018/01/15 14:29:46 by prippa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_ls
LIBRARY		=	libft.a

# FLAGS		= 	-Wall -Werror -Wextra

CC			=	gcc

DIR_LIBFT	=	./libft/
DIR_INC		=	$(DIR_LIBFT)includes/
DIR_FPF		=	$(DIR_LIBFT)printf/
DIR_OBJ		= 	./obj/

HEAD_LIBFT	=	libft.h get_next_line.h
HEAD_FPF	=	ft_printf.h
HEAD_LS		=	ft_ls.h

C_LIBFT		=  ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c\
			ft_isascii.c ft_isdigit.c ft_islowercase.c ft_isprint.c ft_isspace.c\
			ft_isstralpha.c ft_isstrdigit.c ft_isstrlowercase.c ft_isstruppercase.c\
			ft_isuppercase.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c\
			ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c\
			ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
			ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c\
			ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c\
			ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c\
			ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c\
			ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c\
			ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c\
			ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c\
			ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c\
			ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c\
			ft_strtrim.c ft_tolower.c ft_tostrlowercase.c ft_tostruppercase.c\
			ft_toupper.c ft_itoa_base.c get_next_line.c\
			ft_arr_free.c ft_arrlen.c

C_FPF		= 	ft_pf_strjoin.c ft_charjoin.c\
				ft_printf.c ft_unicode.c ft_conv_sig_int.c ft_conv_unsig_int.c\
				ft_get_flags.c ft_get_type.c\
				ft_get_oux.c ft_get_di.c ft_get_c.c ft_get_s.c\
				ft_output_c_modul.c ft_output_s_modul.c ft_output_d_modul.c\
				ft_output_u_modul.c ft_output_ox_modul.c\
				ft_output_p_modul.c

C_LS		=	main.c ls_print_dir.c ls_print_file.c\
				ls_sorting_algo.c ls_readdir.c\
				ls_get_args.c ls_path_valid.c\
				ls_get_flags.c ls_get_mode.c



OBJ_LIBFT 	= 	$(C_LIBFT:.c=.o)
OBJ_FPF 	= 	$(C_FPF:.c=.o)
OBJ_LS 		= 	$(C_LS:.c=.o)

OBJ 		= 	$(addprefix $(DIR_OBJ),$(OBJ_LIBFT))
OBJ 		+= 	$(addprefix $(DIR_OBJ),$(OBJ_FPF))
OBJ 		+= 	$(addprefix $(DIR_OBJ),$(OBJ_LS))

INC 		= 	$(addprefix -I,$(DIR_INC))
INC_LIBFT 	= 	$(addprefix $(DIR_INC),$(HEAD_LIBFT))
INC_FPF 	= 	$(addprefix $(DIR_INC),$(HEAD_FPF))


all: $(NAME)

$(NAME): obj $(OBJ)
	@ar rc $(LIBRARY) $(OBJ)
	@ranlib $(LIBRARY)
	@echo "Compiling" [ $(LIBRARY) ]
	@$(CC) -o $(NAME) $(OBJ) -lm $(LIBRARY)
	@echo "Compiling" [ $(NAME) ]

obj:
	@mkdir -p $(DIR_OBJ)

$(DIR_OBJ)%.o: $(DIR_LIBFT)%.c $(INC_LIBFT)
	@$(CC) $(FLAGS) $(INC) -c -o $@ $<
	@echo "Linking" [ $< ]

$(DIR_OBJ)%.o: $(DIR_FPF)%.c $(INC_FPF)
	@$(CC) $(FLAGS) $(INC) -c -o $@ $<
	@echo "Linking" [ $< ]

$(DIR_OBJ)%.o: %.c $(HEAD_LS)
	@$(CC) $(FLAGS) $(INC) -c -o $@ $<
	@echo "Linking" [ $< ]

clean:
	@rm -rf $(DIR_OBJ)
	@echo "Clean [obj files]"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBRARY)
	@echo "Clean" [ $(LIBRARY) ]
	@echo "Clean" [ $(NAME) ]

re: fclean all

.PHONY: all clean fclean re
