/*
** EPITECH PROJECT, 2017
** 101pong
** File description:
** pong
*/
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	find_time(float *v_speed, char **av);
void	find_bat(float *v_speed, char **av);

void	pong(char **av)
{
	float v_speed[3] = 	{atof(av[4]) - atof(av[1]),
				atof(av[5]) - atof(av[2]),
				atof(av[6]) - atof(av[3])};

	printf("The speed vector coordinates are :\n");
	printf("(%.2f;%.2f;%.2f)\n", v_speed[0], v_speed[1], v_speed[2]);
	find_time(v_speed, av);
	find_bat(v_speed, av);
}

int	main(int ac, char **av)
{
	if (ac == 8) {
		pong(av);
		return (0);
	}
	printf("Usage: ./101pong x0 y0 z0 x1 y1 z1 n\n");
	return (84);
}
