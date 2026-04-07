#include "counter.h"

#include <GL/gl.h>

void init_counter(Counter* counter, float x, float y, float limit)
{
    counter->x = x;
    counter->y = y;
    counter->limit = limit;
    counter->value = 0;
    counter->height = 25;
    counter->width = 100;
}

void reset_counter(Counter* counter)
{
    counter->value = 0;
}

void update_counter(Counter* counter)
{
    if (counter->value < counter->limit) {
        counter->value++;
    } else {
        reset_counter(counter);
    }
}

void render_counter(Counter* counter)
{
    float x1, x2, y1, y2;
    float unit_width;

    y1 = counter->y;
    y2 = y1 + counter->height;
    unit_width = counter->width/counter->limit;

    for (int i = 0; i < counter->value; i++)
    {
        x1 = counter->x + i * unit_width;
        x2 = x1 + unit_width;

        glBegin(GL_QUADS);
            glColor3f(1.0, 0.0, 0.0);
            glVertex2f(x1, y1);
            glVertex2f(x2, y1);
            glVertex2f(x2, y2);
            glVertex2f(x1, y2);
        glEnd();
    }

    for (int i = counter->value; i < counter->limit; i++)
    {
        x1 = counter->x + i * unit_width;
        x2 = x1 + unit_width;

        glBegin(GL_QUADS);
            glColor3f(0.5, 0.5, 0.5);
            glVertex2f(x1, y1);
            glVertex2f(x2, y1);
            glVertex2f(x2, y2);
            glVertex2f(x1, y2);
        glEnd();
    }
    
}