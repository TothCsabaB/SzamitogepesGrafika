#include "pong.h"
#include <stdio.h>

void init_pong(Pong* pong, int width, int height)
{
    pong->width = width;
    pong->height = height;
    pong->left_point = 0;
    pong->right_point = 0;
    init_pad(&(pong->left_pad), 0, height, RED_THEME);
    init_pad(&(pong->right_pad), width - 50, height, GREEN_THEME);
    init_ball(&(pong->ball), width / 2, height / 2);
    init_counter(&(pong->left_counter), 0, 0, 10);
    init_counter(&(pong->right_counter), pong->width - 100, 0, 10);
}

void update_pong(Pong* pong, double time)
{
    update_pad(&(pong->left_pad), time);
    update_pad(&(pong->right_pad), time);
    update_ball(&(pong->ball), time);
    bounce_ball(pong);
}

void render_pong(Pong* pong)
{
    render_pad(&(pong->left_pad));
    render_pad(&(pong->right_pad));
    render_counter(&(pong->left_counter));
    render_counter(&(pong->right_counter));
    render_ball(&(pong->ball));
}

void set_left_pad_position(Pong* pong, float position)
{
    set_pad_position(&(pong->left_pad), position);
}

void set_left_pad_speed(Pong* pong, float speed)
{
    set_pad_speed(&(pong->left_pad), speed);
}

void set_right_pad_position(Pong* pong, float position)
{
    set_pad_position(&(pong->right_pad), position);
}

void set_right_pad_speed(Pong* pong, float speed)
{
    set_pad_speed(&(pong->right_pad), speed);
}

void dec_ball_size(Pong* pong, float size)
{
    if (pong->ball.radius > 10)
    {
        update_size(&(pong->ball), -size);
    }
}

void inc_ball_size(Pong* pong, float size)
{
    if (pong->ball.radius < 200)
    {
        update_size(&(pong->ball), size);
    }
}

void set_ball_position(Pong* pong ,int x, int y)
{
    update_ball_manually(&(pong->ball), x, y);
}

void bounce_ball(Pong* pong)
{
    if (pong->ball.x - pong->ball.radius < 50) {
        pong->ball.x = pong->ball.radius + 50;
        if(pong->ball.y + pong->ball.radius >= pong->left_pad.y &&
           pong->ball.y - pong->ball.radius  <= pong->left_pad.y + pong->left_pad.height) {
            pong->ball.speed_x *= -1;
        }else{
            pong->ball.x = pong->width/2;
            pong->ball.y = pong->height/2;
            update_counter(&(pong->right_counter));
        }
    }
    if (pong->ball.x + pong->ball.radius > pong->width - 50) {
        pong->ball.x = pong->width - pong->ball.radius - 50;
        if(pong->ball.y + pong->ball.radius >= pong->right_pad.y &&
           pong->ball.y - pong->ball.radius  <= pong->right_pad.y + pong->right_pad.height) {
            pong->ball.speed_x *= -1;
        }else{
            pong->ball.x = pong->width/2;
            pong->ball.y = pong->height/2;
            update_counter(&(pong->left_counter));
        }
    }
    if (pong->ball.y - pong->ball.radius < 0) {
        pong->ball.y = pong->ball.radius;
        pong->ball.speed_y *= -1;
    }
    if (pong->ball.y + pong->ball.radius > pong->height) {
        pong->ball.y = pong->height - pong->ball.radius;
        pong->ball.speed_y *= -1;
    }
}
