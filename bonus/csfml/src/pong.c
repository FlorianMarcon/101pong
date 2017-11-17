/*
** EPITECH PROJECT, 2017
** 101pong
** File description:
** pong
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

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
	framebuffer_t *buffer;
	int i = 0;

	buffer = malloc(sizeof(framebuffer_t));
	buffer->width = width;
	buffer->height = height;
	buffer->pixels = malloc(sizeof(framebuffer_t) * width * height * 4);
	for (i = 0; i < (width * height * 4); i++) {
		buffer->pixels[i] = 0;
	}
	return (buffer);
}


void my_put_ball(framebuffer_t *buffer, unsigned int x, unsigned int y, sfColor color)
{
        int	var = (x + y * buffer->width) * 4;
        int	size2 = var + (10 * buffer->height) + 40;
        int 	size = 0;
        int	i = y;


        while (i != y + 10) {
                var = (x + i * buffer->width) * 4;
                size = var + (4 * 10);
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

void my_delete_ballPixel(framebuffer_t *buffer, sfVector2i ball)
{
        int	var = (ball.x + ball.y * buffer->width) * 4;
        int 	size = 0;
        int	i = ball.y;
        sfColor color = {0, 0, 0, 255};


        while (i != ball.y + 10) {
                var = (ball.x + i * buffer->width) * 4;
                size = var + (4 * 10);

                while (var != size) {
                        //if (var <  >) // condition a ajouter pour gerer la ligne du milieu
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

int main()
{
        int width = 1200;
        int height = 800;
        int height_left_racket = 200;
        int height_right_racket = 400;
        int width_left_racket = 0;
        int width_right_racket = 1190;
	int player1 = 0;
	int player2 = 0;
        sfRenderWindow *window;
        sfEvent event;
        sfTexture* texture = sfTexture_create(width, height);
        sfVideoMode video_mode = {width, height, 32};
        sfSprite* sprite;
        sfVector2f spritePos = {0, 0};
        sfColor			color = sfColor_fromRGBA(255, 255, 255, 255);
        framebuffer_t		*buffer = framebuffer_create(width, height);
        sfClock *my_clock;
        sfTime my_time;
        float second;
        sfVector2i ball = {250, 400};
        sfVector2i vitesse = {1, 1};

        my_clock = sfClock_create();
        sprite = sfSprite_create();
        my_put_playspace(buffer, 0, 0, color);
        my_put_left_racket(buffer, width_left_racket, height_left_racket, color);
        my_put_right_racket(buffer, width_right_racket, height_right_racket, color);
        my_put_ball(buffer, ball.x, ball.y, color);

        window = sfRenderWindow_create(video_mode,
                                       "My window",
                                       sfDefaultStyle,
                                       NULL);
        while (sfRenderWindow_isOpen(window)) {

                sfTexture_updateFromPixels(texture, buffer->pixels, 1200, 800, 0, 0);
                sfSprite_setTexture(sprite, texture, sfTrue);
                while (sfRenderWindow_pollEvent(window, &event)) {
                        if (event.type == sfEvtClosed) {
                                sfRenderWindow_close(window);
                        }
                        height_right_racket = analyse_eventsRight(window,
                                               height_right_racket,
                                               width_right_racket,
                                               buffer, color);
                        height_left_racket = analyse_eventsLeft(window,
                                              height_left_racket,
                                              width_left_racket,
                                              buffer, color);
                }
		my_put_playspace(buffer, 0, 0, color);
                my_time = sfClock_getElapsedTime(my_clock);
                second = my_time.microseconds / 1000000.0;
                if (second > 0.0005) {
		//	printf("vitesse.x = %d\n", vitesse.x);
		//	printf("ball.x = %d\n", ball.x);
                        my_delete_ballPixel(buffer, ball);
                        if (ball.y == 10 || ball.y == 780)
                                vitesse.y *= (-1);
                        if (ball.x <= 10 && ball.y >= height_left_racket && ball.y <= height_left_racket + 70) {
                                vitesse.x *= (-1);
			}
                        if (ball.x >= 1180 && ball.y >= height_right_racket && ball.y <= height_right_racket + 70)
                                vitesse.x *= (-1);
                        ball.x += vitesse.x;
                        ball.y += vitesse.y;
                        my_put_ball(buffer, ball.x, ball.y, color);
                        sfClock_restart(my_clock);
                }
                if (ball.x < 0) {
			my_delete_ballPixel(buffer, ball);
			player1 += 1;
			vitesse.x *= (-1);
			ball.x = 10;
			ball.y = height_left_racket + 35;
			printf("player1 = %d\n", player1);
			while (second < 10) {
				if (sfKeyboard_isKeyPressed(sfKeyB))
				        break;
				my_time = sfClock_getElapsedTime(my_clock);
				second = my_time.microseconds / 1000000.0;
			}
		}
		if (ball.x > 1190) {
			my_delete_ballPixel(buffer, ball);
		        player2 += 1;
			vitesse.x *= (-1);
			ball.x = 1180;
			ball.y = height_right_racket + 35;
			printf("player2 = %d\n", player2);
			while (second < 10) {
				if (sfKeyboard_isKeyPressed(sfKeyB))
				        break;
				my_time = sfClock_getElapsedTime(my_clock);
				second = my_time.microseconds / 1000000.0;
			}
		}
		if (player1 == 5) {
			printf("player1 WIN!!!!! SCORE = %d\n", player1);
			printf("player2 LOOSE!!! SCORE = %d\n", player2);
			return (0);
		}
		if (player2 == 5) {
			printf("player2 WIN!!!!! SCORE = %d\n", player2);
			printf("player1 LOOSE!!! SCORE = %d\n", player1);
			return (0);
		}
                sfRenderWindow_clear(window, sfBlack);
                sfRenderWindow_drawSprite(window, sprite, NULL);
                sfRenderWindow_display(window);

        }
        sfRenderWindow_destroy(window);
        return (0);
}
