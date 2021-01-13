#include "window.h"

SDL_Window* SDL_GL_CreateWindow(const char* title, int x, int y, int w, int h, Uint32 flags)
{
    // This function sets the OpenGL attribute attr to value.
    // The requested attributes should be set before creating an OpenGL window.
    // You should use SDL_GL_GetAttribute() to check the values after creating 
    // the OpenGL context, since the values obtained can differ from the requested ones.
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    SDL_Window* window = SDL_CreateWindow(title, x, y, w, h, flags | SDL_WINDOW_OPENGL);
}
