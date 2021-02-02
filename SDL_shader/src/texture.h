#pragma once

typedef struct SDL_GL_Texture2D SDL_GL_Texture2D;

SDL_GL_Texture2D* SDL_GL_CreateTexture2D(unsigned int texture_units_count);
void SDL_GL_DestroyTexture2D(SDL_GL_Texture2D* texture);

void SDL_GL_LoadTexture2D(SDL_GL_Texture2D* texture, const char* path);

void SDL_GL_BindTexture2D(SDL_GL_Texture2D* texture);
