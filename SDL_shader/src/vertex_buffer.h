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

// TODO: Fazer funções pra mudar a data e tudo mais ao invés de já setar ela nessa função
//       de inicialização; pra mim, o preferivel seria que a função de inicialização não
//       tivesse nenhum argumento, a não ser que mais pra frente quando eu vá deixar essas
//       funções um pouco mais complexas precise de alguma coisa (o mesmo se aplica pras
//       outras funções de buffers)
// SDL_GL_VertexBuffer* SDL_GL_CreateVertexBuffer(void* data, unsigned int size);
// void SDL_GL_DestroyVertexBuffer(SDL_GL_VertexBuffer* vbo);

// void SDL_GL_VertexBufferData(SDL_GL_VertexArray* vertex_array, void* data, unsigned int size);

// void SDL_GL_BindVertexBuffer(/*SDL_GL_VertexArray* vertex_array,*/ SDL_GL_VertexBuffer* vbo);
// void SDL_GL_UnbindVertexBuffer(/*SDL_GL_VertexArray* vertex_array, SDL_GL_VertexBuffer* vbo*/);
