# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prippa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/08 17:51:31 by prippa            #+#    #+#              #
#    Updated: 2018/01/08 17:51:54 by prippa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	ft_ls

CC 			= 	gcc

FLAGS		= 	-Wall -Werror -Wextra

LFT_PATH 	= 	./libft/
INC_PATH 	= 	$(LFT_PATH)includes/

SRC			=	main.c

OBJ			= 	$(SRC:.c=.o)


INC 		= $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LFT_PATH)
	@$(CC) -o $(NAME) $(OBJ) -lm $(LFT_PATH)libftprintf.a
	@echo "Compiling" [ $(NAME) ]

%.o: %.c
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<
	@echo "Linking" [ $< ]

clean:
	@make -C $(LFT_PATH) clean
	@rm -rf $(OBJ)
	@echo "Cleaning obj..."

fclean: clean
	@make -C $(LFT_PATH) fclean
	@rm -rf $(NAME) $(OBJ)
	@echo "Remove..." [ $(NAME) ]

re: fclean $(NAME)
