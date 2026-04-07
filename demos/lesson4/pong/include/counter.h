#ifndef COUNTER_H
#define COUNTER_H

typedef struct Counter
{
    float x;
    float y;
    float width;
    float height;
    float value;
    float limit;
} Counter;

void init_counter(Counter* counter, float x, float y, float limit);

void reset_counter(Counter* counter);

void update_counter(Counter* counter);

void render_counter(Counter* counter);

#endif