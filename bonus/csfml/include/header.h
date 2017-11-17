/*
** EPITECH PROJECT, 2017
** 101pong
** File description:
** header
*/
#ifndef HEADER_
#define HEADER_

typedef struct framebuffer {
	unsigned int	width;
	unsigned int	height;
	sfUint8		*pixels;
} framebuffer_t;

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);

void my_put_ball(framebuffer_t *buffer, unsigned int x, unsigned int y, sfColor color);

void my_delete_ballPixel(framebuffer_t *buffer, sfVector2i ball);

void my_delete_pixelDown(framebuffer_t *buffer, unsigned int x, unsigned int y);

void my_delete_pixelUp(framebuffer_t *buffer, unsigned int x, unsigned int y);

void my_put_right_racket(framebuffer_t *buffer, unsigned int x, unsigned int y, sfColor color);

void my_put_left_racket(framebuffer_t *buffer, unsigned int x, unsigned int y, sfColor color);

void my_put_playspace(framebuffer_t *buffer, unsigned int x, unsigned int y, sfColor color);

int analyse_eventsRight(sfRenderWindow *window, unsigned int height_left_racket, unsigned int width_left_racket, framebuffer_t *buffer, sfColor color);

int analyse_eventsLeft(sfRenderWindow *window, unsigned int height_left_racket, unsigned int width_left_racket, framebuffer_t *buffer, sfColor color);

#endif
