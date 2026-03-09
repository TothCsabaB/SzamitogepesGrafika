#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX_LINE_COUNT 20

typedef struct{
	int r, g, b;
} Color;

typedef struct{
	int x1, y1, x2, y2;
	Color c;
} Line;

typedef struct{
  Line data[MAX_LINE_COUNT];
  int head, count;
} Buffer;

void add(const Line, Buffer*);
void draw_palett(SDL_Renderer*);

int main(int argc, char* argv[])
{ 
  int error_code;
  SDL_Window* window;
  bool need_run;
  bool is_draw;
  bool save_draw;
  bool is_rect;
  SDL_Event event;
  SDL_Renderer* renderer;

  Buffer lines = {0};
  
  error_code = SDL_Init(SDL_INIT_EVERYTHING);
  if(error_code != 0){
	  printf("[ERROR] SDL initialization error: %s\n", SDL_GetError());
	  return error_code;
  }

  
  window = SDL_CreateWindow(
    "Line",
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
	800, 600, 0);
	
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	



  need_run = true;
  is_draw = false;
  save_draw = false;
  is_rect = false;
  int valueY, valueX;
  int startX, startY;
  int endX, endY;
  Color color = {255, 255, 255};
  while (need_run) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_KEYDOWN:
        case SDL_SCANCODE_Q:
        need_run = false;
        break;
      case SDL_MOUSEMOTION:{
        valueX = event.motion.x;
        valueY = event.motion.y;
        break;
      }
      case SDL_MOUSEBUTTONDOWN:{
        if (event.button.y<50)
        {
          if (event.button.x<160)
          {
            color = (Color){255, 0, 0};
          }else if(160<event.button.x && event.button.x<320){
            color = (Color){0, 255, 0};
          }else if (320<event.button.x && event.button.x<480)
          {
            color = (Color){0, 0, 255};
          }else if (480<event.button.x && event.button.x<640)
          {
            color = (Color){255, 255, 255};
          }else{
            color = (Color){255, 255, 128};
          }
        }else{
          if (!is_draw)
          {
            startX = event.button.x;
            startY = event.button.y;  
            is_draw = true;
          }else{
            endX = event.button.x;
            endY = event.button.y;
            save_draw = true;
            is_draw = false;
          }
        }
        break;
      }
      case SDL_QUIT:
        need_run = false;
        break;
      }
    }

    draw_palett(renderer);

    if (is_draw)
    {
      SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
      SDL_RenderDrawLine(renderer, startX, startY, valueX, valueY);
    }
    if (save_draw)
    {
      add((Line){startX, startY, endX, endY, color}, &lines);
      save_draw = false;
    }

    for (int i = 0; i < lines.count; i++)
    {
      SDL_SetRenderDrawColor(renderer, lines.data[i].c.r, lines.data[i].c.g, lines.data[i].c.b, 255);
      SDL_RenderDrawLine(renderer, lines.data[i].x1, lines.data[i].y1, lines.data[i].x2, lines.data[i].y2);
    }
    
    SDL_RenderPresent(renderer);
  }

  
  
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  
  return 0;
}

void add(const Line input, Buffer* buffer){
  buffer->data[buffer->head] = input;
  buffer->head = (buffer->head + 1) % MAX_LINE_COUNT;

  if (buffer->count < MAX_LINE_COUNT) {
        buffer->count++;
  }
  return; 
}

void draw_palett(SDL_Renderer* renderer){
  int posX = 0;
  Color colors[] = {(Color){255, 0, 0},(Color){0, 255, 0},(Color){0, 0, 255},(Color){255, 255, 255},(Color){255, 255, 128}};
  for (int i = 0; i < 5; i++)
  {
    SDL_SetRenderDrawColor(renderer, colors[i].r, colors[i].g, colors[i].b , 255);
    SDL_RenderFillRect(renderer, &(SDL_Rect){posX, 0, 160, 50});
    posX = posX + 160;
  }
  
}

