# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ageels <ageels@student.42.fr>                +#+                      #
#                                                    +#+                       #
#    Created: 2022/07/10 20:20:04 by ageels        #+#    #+#                  #
#    Updated: 2022/07/17 21:55:50 by ageels        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FLAGS = -Wall -Werror -Wextra -g
SOURCE = src/main.c\
	src/libfun00.c\
	src/libfun01.c\
	src/listfun00.c\
	src/listfun01.c\
	src/parse.c\

GREEN = \x1b[32m
RESET = \033[0m

OBJECT = $(patsubst src/%.c,obj/%.o,$(SOURCE))

$(NAME) : $(OBJECT)
	@cc $(FLAGS) $(OBJECT) -o $@
	@echo "$(GREEN)push_swap ready$(RESET)"

obj/%.o : src/%.c
	@mkdir -pv obj
	@cc $(FLAGS) -o $@ -c $^ 

all: $(NAME)

clean:
	@test -e obj && rm -fr obj && echo "$(GREEN)cleaned push swap$(RESET)" || echo "$(GREEN)clean: no objects to clean$(RESET)"

fclean: clean
	@test -e $(NAME) && rm $(NAME) || echo "$(GREEN)fclean: no executable to clean$(RESET)"

re: fclean all

.PHONY: all clean fclean re