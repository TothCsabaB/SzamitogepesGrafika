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

    draw_sphere();

    draw_cone();
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
    float buffer[64][2];
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(1, 1, 0);
    float step = 2*M_PI/64;
    float top=0.4f;
    float bottom=0;
    float radius = 0.2;
    float center_x = 0.7;
    float center_y = 0.4;
    int count=0;

    for(float i = 0; i < 2*M_PI; i+=step)
    {
        float x = radius*cos(i)+center_x;
        float y = radius*sin(i)+center_y;
        glVertex3f(x, y, top);
        glVertex3f(x, y, bottom);
        buffer[count][0]=x;
        buffer[count][1]=y;
        count++;
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(center_x, center_y, top);
    for (int i = 0; i < 64; i++)
    {
        glVertex3f(buffer[i][0], buffer[i][1], top);
    }
    glVertex3f(buffer[0][0], buffer[0][1], top);
    glEnd();
}

void draw_sphere()
{
    float step = 2*M_PI/20;
    float vertical_step = M_PI/10;
    float radius = 0.15;
    float center_x = 0.3;
    float center_y = 0.7;
    float center_z = 0.2;
    
    for (float j = 0; j < M_PI; j+=vertical_step)
    {
        glBegin(GL_TRIANGLE_STRIP);
        glColor3f(0.5, 0.5, 0.5);
        for(float i = 0; i < 2*M_PI + 0.001; i+=step)
        {
            float x = radius * sin(j) * cos(i) + center_x;
            float x_up = radius * sin(j+vertical_step) * cos(i) + center_x;

            float y = radius * sin(j) * sin(i) + center_y;
            float y_up = radius *sin(j+vertical_step) * sin(i) + center_y;

            
            glVertex3f(x, y, radius*cos(j)+center_z);

            glVertex3f(x_up, y_up, radius* cos(j+vertical_step)+center_z);
        }
        glEnd();
    }
}

void draw_cone()
{
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.7, 0.7, 0.7);
    float step = 2*M_PI/64;
    float top=0.4f;
    float bottom=0;
    float radius = 0.15;
    float center_x = 0.8;
    float center_y = 0.85;

    glVertex3f(center_x, center_y, top);
    for (float i = 0; i < 2*M_PI; i+=step)
    {
        float x = radius*cos(i)+center_x;
        float y = radius*sin(i)+center_y;

        glVertex3f(x, y, bottom);
    }
    glEnd();
}

