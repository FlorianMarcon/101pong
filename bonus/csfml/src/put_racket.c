/*
** EPITECH PROJECT, 2017
** 101pong
** File description:
** put_racket
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

void my_put_right_racket(framebuffer_t *buffer, unsigned int x, unsigned int y, sfColor color)
{
        int	var = (x + y * buffer->width) * 4;
        int	size2 = var + (10 * buffer->height) + 40;
        int 	size = 0;
        int	i = y;


        while (i != y + 80) {
                var = (x + i * buffer->width) * 4;
                size = var + (4 * 10);
                //var = var +(4);
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

void my_put_left_racket(framebuffer_t *buffer, unsigned int x, unsigned int y, sfColor color)
{
        int	var = (x + y * buffer->width) * 4;
        int	size2 = var + (10 * buffer->height) + 40;
        int 	size = 0;
        int	i = y;


        while (i != y + 80) {
                var = (x + i * buffer->width) * 4;
                size = var + (4 * 10);
                //var = var +(4);
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
