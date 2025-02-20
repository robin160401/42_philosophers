# Colors
GREEN  = \033[1;32m
YELLOW = \033[1;33m
RED    = \033[1;31m
BLUE   = \033[1;34m
RESET  = \033[0m

NAME            = philo
CC              = gcc
CFLAGS          = -Wall -Werror -Wextra -Wunused -g
RM              = rm -rf
OBJDIR          = obj

# Library Paths
LIBDIR          = ./libs

# philosophers Source Files
SRCS            = src/check_input.c src/cleanup.c src/create_philos.c src/eat_r.c \
				  src/ft_atoi.c src/ft_isdigit.c src/ft_putendl_fd.c src/init_data.c \
				  src/join_threads.c src/monitor.c src/philo.c src/routine.c src/sleep_r.c \
				  src/think_r.c src/time_functions.c src/utils.c
OBJS            = $(patsubst src/%.c, $(OBJDIR)/%.o, $(SRCS))

# Build Target
all: $(NAME)

# Create libs directory if not exists
$(LIBDIR):
	@mkdir -p $(LIBDIR)

# Create obj directory if not exists
$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Compile philox
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

# Compile Object Files
$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	@echo "$(BLUE)Compiling pipex object: $<$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

# Clean Object Files
clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	$(RM) $(OBJS)

# Full Cleanup
fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	$(RM) $(NAME)
	@echo "$(RED)Removing obj folders...$(RESET)"
	$(RM) -rf $(OBJDIR)

# Rebuild Everything
re: fclean all

.PHONY: all clean fclean re
