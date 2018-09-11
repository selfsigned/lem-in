# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/04 23:57:19 by xperrin           #+#    #+#              #
#    Updated: 2018/09/11 18:34:33 by xperrin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
CFLAGS = -Wextra -Wall -g #-Werror
LDFLAGS = -L$(LIB) -lft

LIB = libft
LIBINC = -I$(LIB)/includes
LIBAR = libft/libft.a

INCDIR = includes
INCFILES = lemin.h lemin_structs.h
INCFULL = $(addprefix $(INCDIR)/, $(INCFILES))
INC = $(addprefix -I, $(INCDIR)) $(LIBINC)
SRCDIR = src

SRC = main.c \
      mem.c \
      input.c \
      helpers.c \
      parse_rooms.c \
      parse_links.c \
      algo.c \
      path.c

VPATH= $(SRCDIR)
OBJDIR = obj
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

.PHONY: all lib clean fclean re

all:
	@$(MAKE) lib
	@$(MAKE) $(NAME)


$(NAME): $(OBJ) $(LIBAR)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $@

lib:
	@$(MAKE) -C $(LIB) --no-print-directory

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.c $(INCFULL) | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $< $(INC)

clean:
	@$(MAKE) -C $(LIB) clean --no-print-directory
	$(RM) -r $(OBJDIR)

fclean:
	@$(MAKE) -C $(LIB) fclean --no-print-directory
	$(RM) -r $(OBJDIR) $(NAME)

re:
	@$(MAKE) --no-print-directory fclean
	@$(MAKE) --no-print-directory
