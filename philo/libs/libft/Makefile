CC				= gcc
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror -I.
OBJDIR			= obj

SRCS			=	ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
					ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
					ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c ft_striteri.c \
					ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
					ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
					ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c \
					ft_printf.c print_hexadecimal.c check_error_print_address.c \
					ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
					ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
					ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c \
					get_next_line_bonus.c get_next_line_utils_bonus.c \
					ft_strcmp.c ft_putsunsignednbr_fd.c

OBJS			= $(SRCS:.c=.o)
OBJS			:= $(addprefix $(OBJDIR)/, $(OBJS))

NAME			= libft.a

all:			$(OBJDIR) $(NAME)

# Ensure obj/ directory exists
$(OBJDIR):
				@mkdir -p $(OBJDIR)

# Compile .o files inside obj/
$(OBJDIR)/%.o:	%.c | $(OBJDIR)
				$(CC) $(CFLAGS) -c $< -o $@

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				@echo "Cleaning object files..."
				$(RM) $(OBJDIR)

fclean:			clean
				@echo "Removing $(NAME)..."
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re bonus
