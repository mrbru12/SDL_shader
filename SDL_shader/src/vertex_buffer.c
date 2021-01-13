#include "vertex_buffer.h"

// ======================================================================================================
// VERTEX BUFFER OBJECT |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ======================================================================================================

/*
SDL_GL_VertexBuffer* SDL_GL_CreateVertexBuffer(void* data, unsigned int size)
{
    SDL_GL_VertexBuffer* buffer = malloc(sizeof(SDL_GL_VertexBuffer));

    if (buffer)
    {
        buffer->data = data;
        buffer->size = size;
        buffer->usage = GL_STATIC_DRAW;

        GL_ASSERT(glGenBuffers(1, &(buffer->id)));
        GL_ASSERT(glBindBuffer(GL_ARRAY_BUFFER, buffer->id));
        GL_ASSERT(glBufferData(GL_ARRAY_BUFFER, buffer->size, buffer->data, buffer->usage));
    }

    return buffer;
}

void SDL_GL_DestroyVertexBuffer(SDL_GL_VertexBuffer* buffer)
{
    GL_ASSERT(glDeleteBuffers(1, &(buffer->id)));

    free(buffer);
}

void SDL_GL_BindVertexBuffer(SDL_GL_VertexBuffer* buffer)
{
    GL_ASSERT(glBindBuffer(GL_ARRAY_BUFFER, buffer->id));
}

void SDL_GL_UnbindVertexBuffer()
{
    GL_ASSERT(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
*/
