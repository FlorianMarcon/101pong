/*
** EPITECH PROJECT, 2017
** find bat
** File description:
** 101pong
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
