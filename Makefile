
NAME			= libftasm.a

LIN_COMPILER	= nasm -f elf64

MAC_COMPILER	= nasm -f macho64

CC_FLAGS		= -Wall -Werror -Wextra

LIB_SRC_DIR		= ./src

LIB_SRC			=	ft_isdigit.s \
					ft_tolower.s \
					ft_toupper.s \
					ft_islower.s \
					ft_isupper.s \
					ft_isalpha.s \
					ft_isprint.s \
					ft_isalnum.s \
					ft_isascii.s \
					ft_bzero.s \
					ft_strlen.s \


LIB_OBJ		= $(LIB_SRC:.s=.o)

LIB_SRCS	= $(addprefix $(LIB_SRC_DIR)/, $(LIB_SRC))

NEWLINE		= @echo ""

all : $(NAME)

$(NAME): $(LIB_OBJ)
	ar rc $(NAME) $(LIB_OBJ)

%.o: $(LIB_SRC_DIR)/%.s
	$(LIN_COMPILER) $< -o $@

clean:
	rm -rf $(LIB_OBJ) $(PNTF_OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean 
	$(MAKE) all

.PHONY: all clean fclean re