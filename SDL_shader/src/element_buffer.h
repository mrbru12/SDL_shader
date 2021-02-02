#pragma once

// ======================================================================================================
// ELEMENT BUFFER OBJECT ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ======================================================================================================

/*
typedef struct
{
    unsigned int id;
    const unsigned int* data;
    unsigned int size;
    unsigned int usage;
} SDL_GL_ElementBuffer; // TODO: SDL_GL_ElementBufferInfo

// Opaque Pointer: https://en.wikipedia.org/wiki/Opaque_pointer
// typedef struct SDL_GL_ElementBuffer SDL_GL_ElementBuffer;

// TODO: Dar suporte para tipos menores de data pro index buffer, como unsigned char, dessa
//       forma não vai ocupar tanta VRAM se o modelo que estiver sendo desenhado não for
//       tão grande e, portanto, não precise de muitos indices
SDL_GL_ElementBuffer* SDL_GL_CreateElementBuffer(const unsigned int* data, unsigned int size);
void SDL_GL_DestroyElementBuffer(SDL_GL_ElementBuffer* buffer);

void SDL_GL_ElementBufferData(SDL_GL_VertexArray* vertex_array, const unsigned int* data, unsigned int size);
*/

// void SDL_GL_BindElementBuffer(/*SDL_GL_VertexArray* vertex_array,*/ SDL_GL_ElementBuffer* buffer);
// void SDL_GL_UnbindElementBuffer(/*SDL_GL_VertexArray* vertex_array, SDL_GL_ElementBuffer* buffer*/);
