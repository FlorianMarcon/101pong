/*
** EPITECH PROJECT, 2017
** findbat
** File description:
** 101pong
*/
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

	if (atof(av[6]) > 0 && atof(av[6]) <= atof(av[6]) + v_speed[2])
		printf("The ball won't reach the bat.\n");
	else if (atof(av[6]) < 0 && atof(av[6]) >= atof(av[6]) + v_speed[2])
		printf("The ball won't reach the bat.\n");
	else {
		var_b = sqrt(pow(v_speed[0], 2) + pow(v_speed[1], 2));
		var_p = sqrt(pow(v_speed[0], 2) + pow(v_speed[1], 2) + pow(v_speed[2], 2));
		result = acos(var_b/var_p);
		result = conv_rad_deg(result);
		printf("The incidence angle is :\n%.2f degrees\n",result);
	}
}
