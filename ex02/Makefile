NAME	:= indentify

CC		:= c++
CFLAGS	:= -Wall -Wextra -Werror -std=c++98

SRCS	:= main.cpp \
		   Base.cpp \
		   A.cpp \
		   B.cpp \
		   C.cpp \
		   identify.cpp \
		   generate.cpp

OBJS	:= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
