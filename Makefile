SOURCE_FILES =
CFLAGS = -Wall -Wextra -Werror -g
LIBFLAGS = -lft
SOURCE_DIR = ./
SOURCES := $(addprefix $(SOURCE_DIR),$(SOURCE_FILES))
OBJECTS := $(SOURCES:.c=.o)
NAME = fdf

all : $(NAME)

re : fclean all

$(NAME) : $(OBJECTS)
	gcc $(CFLAGS) -Llibft -o $(NAME) $(OBJECTS) $(LIBFLAGS)

$(OBJECTS) : $(SOURCES)
	gcc -g -c $(SOURCES)

clean : 
	rm -f $(OBJECTS) $(LIBOBJECTS)
	make clean -C libft/

fclean : clean
	rm -f $(NAME)
	make fclean -C libft/