################################################################################
################################## VARIABLES ###################################
################################################################################

NAME    := ex01

CC      =  c++
CFLAGS  =  -Wall -Wextra -Werror -std=c++17
HEADERS =  -I.

SRC     := main.cpp Fixed.cpp

OBJ_DIR := _obj
OBJ     := $(addprefix $(OBJ_DIR)/, $(SRC:%.cpp=%.o))

################################################################################
#################################### RULES #####################################
################################################################################

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $^ -o $@ $(HEADERS)
	@echo "[$(NAME)] Created binary."

$(OBJ_DIR)/%.o: %.cpp
	@if [ ! -d "$(dir $@)" ]; then \
		mkdir -p $(dir $@); \
	fi
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)
	@echo "[$(NAME)] Compiled $<."

clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
		rm -rf $(OBJ_DIR); \
		echo "[$(NAME)] Removed object files."; \
	fi

fclean: clean
	@if [ -f "$(NAME)" ]; then \
		rm -f $(NAME); \
		echo "[$(NAME)] Removed binary."; \
	fi

re:	fclean all

.PHONY: all clean fclean re

################################################################################
################################################################################
