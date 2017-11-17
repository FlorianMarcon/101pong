/*
** EPITECH PROJECT, 2017
** 101pong
** File description:
** playspace
*/
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <SFML/Window/Export.h>
#include "header.h"

void	my_put_playspace(framebuffer_t *buffer, unsigned int x, unsigned int y, sfColor color)
{
	int	var = (x + y * buffer->width) * 4;
	int	size2 = var + (10 * buffer->height) + 40;
	int 	size = 0;
	int	i = y;

	while (i != y + 10) {
		var = (x + i * buffer->width) * 4;
		size = var + (4 * 1200);
		while (var != size) {
			buffer->pixels[var] = color.r;
			buffer->pixels[var + 1] = color.g;
			buffer->pixels[var + 2] = color.b;
			buffer->pixels[var + 3] = color.a;
			var = var + 4;
		}
		var = (var - 40);
		i = i + 1;
	}
        while (i != y + 790) {
		var = (x + i * buffer->width) * 4;
		size = var + (4 * 603);
                var = var + (4 * 597);
		while (var != size) {
			buffer->pixels[var] = color.r;
			buffer->pixels[var + 1] = color.g;
			buffer->pixels[var + 2] = color.b;
			buffer->pixels[var + 3] = color.a;
			var = var + 4;
		}
		var = (var - 40);
		i = i + 1;
	}
        while (i != y + 800) {
                var = (x + i * buffer->width) * 4;
                size = var + (4 * 1200);
                while (var != size) {
                        buffer->pixels[var] = color.r;
                        buffer->pixels[var + 1] = color.g;
                        buffer->pixels[var + 2] = color.b;
                        buffer->pixels[var + 3] = color.a;
                        var = var + 4;
                }
                var = (var - 40);
                i = i + 1;
        }
}
