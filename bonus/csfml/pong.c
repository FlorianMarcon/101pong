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
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>

typedef struct framebuffer {
        unsigned int width;
        unsigned int height;
        sfUint8      *pixels;
} framebuffer_t;

void move_rect(sfIntRect *rect, int offset, int max_value)
{
        rect->left += offset;
        if (rect->left == max_value) {
                rect->left = 0;
        }

}

void manage_mouse_click(sfRenderWindow *window)
{
        sfVector2i Posi;

        Posi = sfMouse_getPositionRenderWindow(window);

        //if (Posi.x > spritePos.x && Posi.x < spritePos.y + 110  &&
        //    Posi.y > spritePos.y && Psoi.x < spritePos.y +100) {
        //        return (1);
        //}
        printf("x = %d  y = %d\n", Posi.x, Posi.y);
        //return (0);
}

void analyse_events(sfRenderWindow *window)
{
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
                manage_mouse_click(window);
        }

}


int main()
{
        sfRenderWindow *window;
        sfEvent event;
        sfVideoMode video_mode = {1200, 800, 32};
        sfTexture* texture;
        sfTexture* texture2;
        sfSprite* sprite;
        sfSprite* sprite2;
        sfIntRect rect;
        sfClock *my_clock;
        sfTime my_time;
        float second;
        sfVector2f spritePos = {0, 0};

        my_clock = sfClock_create();
        texture2 = sfTexture_create(1200, 800);
        texture = sfTexture_createFromFile("./src/super_ball.png", NULL);
        sprite2 = sfSprite_create();
        sprite = sfSprite_create();
        rect.top = 0;
        rect.left = 0;
        rect.width = 64;
        rect.height = 64;
        sfSprite_setTexture(sprite, texture, sfTrue);
        sfSprite_setTexture(sprite2, texture2, sfTrue);



ledpin (ledpin, INTPUT);

if( ledpin != 0V){

}





        window = sfRenderWindow_create(video_mode, "My_window",
                                      sfDefaultStyle, NULL);
        while (sfRenderWindow_isOpen(window)) {
               while (sfRenderWindow_pollEvent(window, &event)) {
                        if (event.type == sfEvtClosed)
                               sfRenderWindow_close(window);
                               analyse_events(window);
                }
                my_time = sfClock_getElapsedTime(my_clock);
                second = my_time.microseconds / 1000000.0;
                if (second > 0.2) {
                        move_rect(&rect, 64, 512);
                        sfClock_restart(my_clock);
                }
                sfSprite_setTextureRect(sprite, rect);
                sfSprite_setPosition(sprite, spritePos);

                spritePos.x += 0.50;
                spritePos.y = (cos(spritePos.x /30)* 50) + 100;
                if (spritePos.x > 1200) {
                        spritePos.x = -110;
                }
                sfRenderWindow_clear(window, sfBlack);
                sfRenderWindow_drawSprite(window, sprite2, NULL);
                sfRenderWindow_drawSprite(window, sprite, NULL);
                sfRenderWindow_display(window);

       }
       sfSprite_destroy(sprite2);
       sfTexture_destroy(texture2);
       sfSprite_destroy(sprite);
       sfTexture_destroy(texture);
       sfRenderWindow_destroy(window);
}
