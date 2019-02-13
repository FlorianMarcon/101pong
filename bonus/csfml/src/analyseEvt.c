/*
** EPITECH PROJECT, 2017
** 101pong
** File description:
** analyse
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

int analyse_eventsRight(sfRenderWindow *window, unsigned int height_left_racket,
                        unsigned int width_left_racket, framebuffer_t *buffer,
                        sfColor color)
{
        if (sfKeyboard_isKeyPressed(sfKeyP)) {
                if (height_left_racket <= 10)
                        return (height_left_racket);
                my_delete_pixelDown(buffer, width_left_racket, height_left_racket);
                height_left_racket -= 10;
                my_put_right_racket(buffer, width_left_racket, height_left_racket, color);
                return(height_left_racket);
        }

        if (sfKeyboard_isKeyPressed(sfKeyL)) {
                if (height_left_racket >= 710)
                        return (height_left_racket);
                my_delete_pixelUp(buffer, width_left_racket, height_left_racket);
                height_left_racket += 10;
                my_put_right_racket(buffer, width_left_racket, height_left_racket, color);
                return(height_left_racket);
        }
        return (height_left_racket);
}

int analyse_eventsLeft(sfRenderWindow *window, unsigned int height_left_racket,
                        unsigned int width_left_racket, framebuffer_t *buffer,
                        sfColor color)
{
        if (sfKeyboard_isKeyPressed(sfKeyA)) {
                if (height_left_racket <= 10)
                        return (height_left_racket);
                my_delete_pixelDown(buffer, width_left_racket, height_left_racket);
                height_left_racket -= 10;
                my_put_right_racket(buffer, width_left_racket, height_left_racket, color);
                return(height_left_racket);
        }

        if (sfKeyboard_isKeyPressed(sfKeyQ)) {
                if (height_left_racket >= 710)
                        return (height_left_racket);
                my_delete_pixelUp(buffer, width_left_racket, height_left_racket);
                height_left_racket += 10;
                my_put_right_racket(buffer, width_left_racket, height_left_racket, color);
                return(height_left_racket);
        }
        return (height_left_racket);
}
