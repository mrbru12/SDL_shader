#pragma once

// ======================================================================================================
// INDEX BUFFER OBJECT ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ======================================================================================================

/*
typedef struct
{
    unsigned int id;
    const unsigned int* data;
    unsigned int size;
    unsigned int usage;
} SDL_GL_IndexBuffer; // TODO: SDL_GL_IndexBufferInfo

// Opaque Pointer: https://en.wikipedia.org/wiki/Opaque_pointer
// typedef struct SDL_GL_IndexBuffer SDL_GL_IndexBuffer;

// TODO: Dar suporte para tipos menores de data pro index vbo, como unsigned char, dessa
//       forma não vai ocupar tanta VRAM se o modelo que estiver sendo desenhado não for
//       tão grande e, portanto, não precise de muitos indices
SDL_GL_IndexBuffer* SDL_GL_CreateIndexBuffer(const unsigned int* data, unsigned int size);
void SDL_GL_DestroyIndexBuffer(SDL_GL_IndexBuffer* vbo);

void SDL_GL_IndexBufferData(SDL_GL_VertexArray* vertex_array, const unsigned int* data, unsigned int size);
*/

// void SDL_GL_BindIndexBuffer(/*SDL_GL_VertexArray* vertex_array,*/ SDL_GL_IndexBuffer* vbo);
// void SDL_GL_UnbindIndexBuffer(/*SDL_GL_VertexArray* vertex_array, SDL_GL_IndexBuffer* vbo*/);
