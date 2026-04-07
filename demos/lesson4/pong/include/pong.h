#ifndef PONG_H
#define PONG_H

#include "ball.h"
#include "pad.h"
#include "counter.h"

#include <stdbool.h>

/**
 * Pong game elements
 */
typedef struct Pong
{
    int width;
    int height;
    Ball ball;
    Pad left_pad;
    Pad right_pad;
    Counter left_counter;
    Counter right_counter;
    int left_point;
    int right_point;
} Pong;

/**
 * Initialize the pong table.
 */
void init_pong(Pong* pong, int width, int height);

/**
 * Update the pong game.
 */
void update_pong(Pong* pong, double time);

/**
 * Render the pong game.
 */
void render_pong(Pong* pong);

/**
 * Move the left pad to the given position.
 */
void set_left_pad_position(Pong* pong, float position);

/**
 * Set the speed of the left pad.
 */
void set_left_pad_speed(Pong* pong, float speed);

/**
 * Move the right pad to the given position.
 */
void set_right_pad_position(Pong* pong, float position);

/**
 * Set the speed of the right pad.
 */
void set_right_pad_speed(Pong* pong, float speed);

void inc_ball_size(Pong* pong, float size);

void dec_ball_size(Pong* pong, float size);

void set_ball_position(Pong* pong ,int x, int y);

/**
 * Bounce the ball when necessary.
 */
void bounce_ball(Pong* pong);

#endif /* PONG_H */
