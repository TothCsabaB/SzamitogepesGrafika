#include "scene.h"

#include <math.h>
#include <GL/gl.h>

void init_scene(Scene* scene)
{
}

void update_scene(Scene* scene)
{
}

void render_scene(const Scene* scene)
{
    draw_origin();
    glBegin(GL_QUADS);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);
    glVertex3f(1, 0, 1);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);
    glVertex3f(1, 0, 1);
    glVertex3f(1, 0, 0);

    glEnd();

    draw_triangle();

    draw_chess_board();

    draw_cylinder();
}

void draw_origin()
{
    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);

    glEnd();
}

void draw_triangle()
{
    glBegin(GL_TRIANGLES);
    glColor3f(1, 1, 0);
    glVertex3f(0, 0, 0.5);

    glColor3f(0, 1, 1);
    glVertex3f(0.5, 0, 0);

    glColor3f(1, 0, 1);
    glVertex3f(0, 0.5, 0);

    glEnd();
}



void draw_chess_board()
{
    glBegin(GL_QUADS);
    float step = 0.125;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((j+i)%2==0)
            {
                glColor3f(0, 0, 0);
            }else
            {
                glColor3f(1, 1, 1);
            }
            glVertex3f( (i+1)*step, (j+1)*step, 0);
            glVertex3f((i+1)*step, j*step, 0);
            glVertex3f(i*step, j*step, 0);
            glVertex3f(i*step, (j+1)*step, 0);
        }
        
    }
    glEnd();
    
}

void draw_cylinder()
{
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(1, 1, 0);
    float step = 2*M_PI/64;
    float top=1.0f;
    float bottom=0;
    int count = 0;

    glVertex3f(0.5*cos(0), 0.5*sin(0), top);
    for(float i = 0; i < 2*M_PI; i+=step)
    {
        if(count%2==0){
            glVertex3f(0.5*cos(i), 0.5*sin(i), bottom);
        }else{
            glVertex3f(0.5*cos(i), 0.5*sin(i), top);
        }
        count++;
    }
    glVertex3f(0.5*cos(0), 0.5*sin(0), top);
    
    glEnd();
}

