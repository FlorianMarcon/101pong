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


void	vector(float **vector, float time)
{
	float *v_speed = *vector;

	v_speed[0] = v_speed[0] * time;
	v_speed[1] = v_speed[1] * time;
	v_speed[2] = v_speed[2] * time;
}

void	find_time(float *v_speed, char **av)
{
	float time = atof(av[7]);
	float point[3];

	vector(&v_speed, time);
	point[0] = atof(av[4]) + v_speed[0];
	point[1] = atof(av[5]) + v_speed[1];
	point[2] = atof(av[6]) + v_speed[2];
	printf("At time t+%i, ball coordinates will be :\n", (int)time);
	printf("(%.2f;%.2f;%.2f)\n",point[0], point[1], point[2]);
	vector(&v_speed, 1/time);
}

float	conv_rad_deg(float nb)
{
	nb = 180 * nb / M_PI;
	return (nb);
}
void	find_bat(float *v_speed, char **av)
{
	float result;
	float var_b;
	float var_p;

	if (atof(av[3]) > 0 && atof(av[3]) <= atof(av[3]) + v_speed[2])
		printf("The ball won't reach the bat.\n");
	else if (atof(av[3]) < 0 && atof(av[3]) >= atof(av[3]) + v_speed[2])
		printf("The ball won't reach the bat.\n");
	else {
		var_b = sqrt(pow(v_speed[0], 2) + pow(v_speed[1], 2));
		var_p = sqrt(pow(v_speed[0], 2) + pow(v_speed[1], 2) + pow(v_speed[2], 2));
		result = acos(var_b/var_p);
		result = conv_rad_deg(result);
		printf("The incidence angle is :\n%.2f degrees\n",result);
	}
}
void	pong(char **av)
{
	float v_speed[3] = {atof(av[4]) - atof(av[1]), atof(av[5]) - atof(av[2]), atof(av[6]) - atof(av[3])};

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
	return (84);
}
