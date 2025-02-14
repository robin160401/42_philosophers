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
LIBFT_PATH      = $(LIBDIR)/libft
LIBFT_OBJDIR    = $(LIBFT_PATH)/obj

# libft Clone Info
LIBFT_REPO      = https://github.com/robin160401/42_libft/archive/refs/heads/master.zip
LIBFT           = $(LIBFT_PATH)/libft.a
LIBFT_ZIP       = $(LIBDIR)/libft.zip

# philosophers Source Files
SRCS            = $(wildcard src/*.c)
OBJS            = $(patsubst src/%.c, $(OBJDIR)/%.o, $(SRCS))

# Build Target
all: $(LIBFT) $(NAME)

# Create libs directory if not exists
$(LIBDIR):
	@mkdir -p $(LIBDIR)

# Create obj directory if not exists
$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Download and Extract libft (only when needed)
$(LIBFT_PATH): $(LIBDIR)
	@echo "$(YELLOW)Downloading libft...$(RESET)"
	@curl -L $(LIBFT_REPO) -o $(LIBFT_ZIP) || { echo "$(RED)Failed to download libft.$(RESET)"; exit 1; }
	@echo "$(BLUE)Extracting libft...$(RESET)"
	@unzip -q $(LIBFT_ZIP) -d $(LIBDIR)
	@mv $(LIBDIR)/42_libft-master $(LIBFT_PATH)
	@rm $(LIBFT_ZIP)

# Compile libft
$(LIBFT): $(LIBFT_PATH)
	@echo "$(BLUE)Building libft.a in $(LIBFT_PATH)...$(RESET)"
	@$(MAKE) -C $(LIBFT_PATH) -j$(nproc)

# Compile pipex
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
	@echo "$(RED)Cleaning libft object files...$(RESET)"
	@$(MAKE) clean -C $(LIBFT_PATH) || true
	@$(RM) $(LIBFT_PATH)/libft.a || true

# Full Cleanup
fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	$(RM) $(NAME)
	@echo "$(RED)Removing obj folders...$(RESET)"
	$(RM) -rf $(OBJDIR)
	@echo "$(RED)Removing libft folder...$(RESET)"
	$(RM) -rf $(LIBFT_PATH) $(LIBDIR)

# Rebuild Everything
re: fclean all

.PHONY: all clean fclean re
