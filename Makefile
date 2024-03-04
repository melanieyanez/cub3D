# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/09 23:57:00 by melanieyane       #+#    #+#              #
#    Updated: 2024/03/04 12:09:09 by myanez-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

# Dossiers

SRCDIR = SRCS
OBJDIR = objs
HDRDIR = includes


# Fichiers

SRCS = $(shell find ${SRCDIR} -name '*.c')
OBJS = ${SRCS:${SRCDIR}%.c=${OBJDIR}%.o}
HEADERS = ${HDRDIR}

# Compilation

GCC = GCC
CFLAGS = -Wall -Wextra -Werror

# Commandes

RM = rm -Rf

# Règles

${OBJDIR}/%.o : ${SRCDIR}/%.c
	@mkdir -p ${OBJDIR}
	@echo "Compiling $< into ${@F}..."
	@${GCC} ${CFLAGS} -Imlx -I ${HEADERS} -c $< -o $@

${NAME} : ${OBJS}
	@echo "\nCompiling the mlx library..."
	@make -C mlx > /dev/null 2>&1;
	@echo "\nCompiling the libft library..."
	@make -C libft
	@echo "\nCompiling so_long executable..."
	@${GCC} ${CFLAGS} ${OBJS} -Llibft -lft -Lmlx -lmlx -lz -framework OpenGL -framework AppKit -o ${NAME}
	@echo "\nAll done!"
			
all : ${NAME}

# Nettoyage

clean : 
	@echo "Cleaning...\n"
	@${RM} ${OBJS}
	@make clean -C mlx
	@make clean -C libft

fclean : clean
	@echo "Full cleaning...\n"
	@${RM} ${NAME}
	@make fclean -C libft

# Autres règles

re : fclean all

.PHONY : re fclean clean all
	


