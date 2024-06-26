# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: picarlie <picarlie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/11 08:45:07 by picarlie          #+#    #+#              #
#    Updated: 2024/06/26 11:46:57 by picarlie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Standard
SERVER				= server
CLIENT				= client

# Directories
LIBFT				= Libft/libft.a
INC					= inc/
SRC_DIR				= srcs/
OBJ_DIR				= obj/

# Compiler and CFlags
CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -I
RM					= rm -f

# Source Files
SERVER_DIR			=	$(SRC_DIR)server.c

CLIENT_DIR			=	$(SRC_DIR)client.c

# Concatenate all source files
SERVER_SRCS			= $(SERVER_DIR)
CLIENT_SRCS			= $(CLIENT_DIR)

# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJ_SERVER 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SERVER_SRCS))
OBJ_CLIENT 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(CLIENT_SRCS))

# Build rules
start:				
					@make all

$(LIBFT):
					@make -C Libft

all: 				$(SERVER)

$(SERVER): 			$(OBJ_SERVER) $(LIBFT)
					@$(CC) $(CFLAGS) $(INC) $(OBJ_SERVER) $(LIBFT) -o $(SERVER)
					
$(CLIENT): 			$(OBJ_CLIENT) $(LIBFT)
					@$(CC) $(CFLAGS) $(INC) $(OBJ_CLIENT) $(LIBFT) -o $(CLIENT)

# Compile object files from source files
$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./Libft

fclean: 			clean
					@$(RM) $(SERVER)
					@$(RM) $(CLIENT)
					@$(RM) $(LIBFT)

re: 				fclean all

# Phony targets represent actions not files
.PHONY: 			start all clean fclean re
