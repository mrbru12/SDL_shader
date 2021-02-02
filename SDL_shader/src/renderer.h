#pragma once

// #include "util/buffer.h"

// TODO: Fazer um header com algumas declarations �teis pra n�o ficar #include <SDL.h> em todo o lugar
struct SDL_Window;

// ======================================================================================================
// SHADER RENDERER ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ======================================================================================================

// TODO: Ao inv�s de ter os VAOs e etc... do OpenGL todos bruteforceds no SDL_GL_Renderer, usar a ideia de
//       meshes(struct que guarda VAOs, VBOs, etc... para um objeto simples como um tri�ngulo ou um cubo) 
//       e models (struct que guarda v�rias meshes que juntas formam um objeto mais complexo, como uma �rvore).
//       Dessa forma as fun��es de drawing do SDL_GL_Renderer s� v�o precisar de meshes (quando for pra coisas
//       simples, como desenhar uma linha) ou models como par�metros. Exemplos de como implementar isso est�o
//       na sec��o "Model Loading" do learnopengl.com
// TODO: Criar algumas meshes simples como a de um tri�ngulo, pixel, linha, quadrado, etc... na inicializa��o 
//       do SDL_GL_Renderer pra servirem de data base pras fun��es b�sicas de drawing, como a SDL_GL_DrawRect(). 
//       Dessa forma v�o ficar mais simples os par�metros, podendo passar s� a posi��o, por exemplo, n�o precisando 
//       passar uma mesh inteira, exemplo: SDL_GL_DrawRect(SDL_Rect rect, SDL_Color color);
typedef struct SDL_GL_Renderer SDL_GL_Renderer;

SDL_GL_Renderer* SDL_GL_CreateRenderer(SDL_Window* window);
void SDL_GL_DestroyRenderer(SDL_GL_Renderer* renderer);

// SDL_GLContext* SDL_GL_GetContext(SDL_GL_Renderer* renderer);

void SDL_GL_RenderClear(SDL_GL_Renderer* renderer);
void SDL_GL_RenderPresent(SDL_GL_Renderer* renderer);

void SDL_GL_RenderDrawLine(SDL_GL_Renderer* renderer, size_t size, void* data);
void SDL_GL_RenderDrawLines(SDL_GL_Renderer* renderer, size_t size, void* data, unsigned int count);
void SDL_GL_RenderDrawPoint(SDL_GL_Renderer* renderer, int x, int y); // void SDL_GL_RenderDrawPoint(SDL_GL_Renderer* renderer, size_t size, void* data);
// void SDL_GL_RenderDrawPoints();
// void SDL_GL_RenderDrawRect();
// void SDL_GL_RenderDrawRects();
// void SDL_GL_RenderDrawTriangle();
// void SDL_GL_RenderDrawTriangles();
void SDL_GL_RenderFillTriangle(SDL_GL_Renderer* renderer, size_t size, void* data); // SDL_GL_Buffer buffer);
// void SDL_GL_RenderFillTriangles();
void SDL_GL_RenderFillRect(SDL_GL_Renderer* renderer, size_t size, void* data); //  SDL_GL_Buffer buffer);
// void SDL_GL_RenderFillRects();
