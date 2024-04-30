CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -framework OpenGL -framework AppKit
CFILES = ft_substr.c events.c main.c calculate_mandelbrot.c handel_image.c ft_atoi.c calculate_julia.c ft_strncmp.c\
			params_for_atoi.c
CFILESBS = ./bonus/ft_substr_bonus.c ./bonus/events_bonus.c ./bonus/calculate_mandelbrot_bonus.c\
			./bonus/handel_image_bonus.c ./bonus/ft_atoi_bonus.c ./bonus/calculate_julia_bonus.c\
			./bonus/ft_strncmp_bonus.c ./bonus/calculate_burning_ship_bonus.c ./bonus/events2_bonus.c\
			./bonus/events3_bonus.c ./bonus/main_bonus.c ./bonus/params_for_atoi_bonus.c ./bonus/mouse_move_bonus.c
BONUSOBJ = $(CFILESBS:.c=.o)
OBJ = $(CFILES:.c=.o)
NAME = fractol
NAME_BNS = fractol_bonus
MINILIBX = ./minilibx_opengl_20191021/libmlx.a

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${CFLAGS} ${LDFLAGS} -O3 ${OBJ} ${MINILIBX} -o ${NAME}

git:
	git add .
	git commit -m "make commit"
	git push

clean:
	rm -rf ${OBJ}

fclean: clean
	rm ${NAME}

bonus : $(NAME_BNS)

${NAME_BNS}: ${BONUSOBJ}
	${CC} ${CFLAGS} ${LDFLAGS} -O3 ${BONUSOBJ} ${MINILIBX} -o ${NAME_BNS}

cleanbs:
	rm ${BONUSOBJ}

fcleanbs: cleanbs
	rm ${NAME_BNS}

re: fclean all

rebs: fcleanbs bonus

lib:
	curl  -O https://cdn.intra.42.fr/document/document/24002/minilibx_opengl.tgz
	tar -xzf minilibx_opengl.tgz
	rm minilibx_opengl.tgz