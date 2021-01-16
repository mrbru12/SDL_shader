#pragma once

// ======================================================================================================
// VERTEX BUFFER OBJECT |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ======================================================================================================

/*
typedef struct
{
    unsigned int id;
    void* data;
    unsigned int size;
    unsigned int usage;
} SDL_GL_VertexBuffer; // TODO: SDL_GL_VertexBufferInfo
*/

// Opaque Pointer: https://en.wikipedia.org/wiki/Opaque_pointer
// typedef struct SDL_GL_VertexBuffer SDL_GL_VertexBuffer;

// TODO: Fazer fun��es pra mudar a data e tudo mais ao inv�s de j� setar ela nessa fun��o
//       de inicializa��o; pra mim, o preferivel seria que a fun��o de inicializa��o n�o
//       tivesse nenhum argumento, a n�o ser que mais pra frente quando eu v� deixar essas
//       fun��es um pouco mais complexas precise de alguma coisa (o mesmo se aplica pras
//       outras fun��es de buffers)
// SDL_GL_VertexBuffer* SDL_GL_CreateVertexBuffer(void* data, unsigned int size);
// void SDL_GL_DestroyVertexBuffer(SDL_GL_VertexBuffer* vbo);

// void SDL_GL_VertexBufferData(SDL_GL_VertexArray* vertex_array, void* data, unsigned int size);

// void SDL_GL_BindVertexBuffer(/*SDL_GL_VertexArray* vertex_array,*/ SDL_GL_VertexBuffer* vbo);
// void SDL_GL_UnbindVertexBuffer(/*SDL_GL_VertexArray* vertex_array, SDL_GL_VertexBuffer* vbo*/);
