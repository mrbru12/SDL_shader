#pragma once

#include "buffer.h"

// ======================================================================================================
// SHADER RENDERER ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ======================================================================================================

typedef struct SDL_GL_Renderer SDL_GL_Renderer;

SDL_GL_Renderer* SDL_GL_CreateRenderer(SDL_Window* window);
void SDL_GL_DestroyRenderer(SDL_GL_Renderer* renderer);

// SDL_GLContext* SDL_GL_GetContext(SDL_GL_Renderer* renderer);

void SDL_GL_RenderClear(SDL_GL_Renderer* renderer);
void SDL_GL_RenderPresent(SDL_GL_Renderer* renderer);

// void SDL_GL_RenderDrawLine();
// void SDL_GL_RenderDrawLines();
// void SDL_GL_RenderDrawPoint();
// void SDL_GL_RenderDrawPoints();
// void SDL_GL_RenderDrawRect();
// void SDL_GL_RenderDrawRects();
void SDL_GL_RenderFillTriangle(SDL_GL_Renderer* renderer, size_t size, void* data); // SDL_GL_Buffer buffer);
// void SDL_GL_RenderFillTriangles();
void SDL_GL_RenderFillRect(SDL_GL_Renderer* renderer, size_t size, void* data); //  SDL_GL_Buffer buffer);
// void SDL_GL_RenderFillRects();
