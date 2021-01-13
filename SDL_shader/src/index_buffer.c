#include "index_buffer.h"

// ======================================================================================================
// INDEX BUFFER OBJECT ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ======================================================================================================

/*
SDL_GL_IndexBuffer* SDL_GL_CreateIndexBuffer(const unsigned int* data, unsigned int size)
{
    SDL_GL_VertexBuffer* buffer = malloc(sizeof(SDL_GL_IndexBuffer));

    if (buffer)
    {
        buffer->data = data;
        buffer->size = size;
        buffer->usage = GL_STATIC_DRAW;

        GL_ASSERT(glGenBuffers(1, &(buffer->id)));
        GL_ASSERT(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer->id));
        GL_ASSERT(glBufferData(GL_ELEMENT_ARRAY_BUFFER, buffer->size, buffer->data, buffer->usage));
    }

    return buffer;
}

void SDL_GL_DestroyIndexBuffer(SDL_GL_IndexBuffer* buffer)
{
    GL_ASSERT(glDeleteBuffers(1, &(buffer->id)));

    free(buffer);
}

void SDL_GL_BindIndexBuffer(SDL_GL_IndexBuffer* buffer)
{
    GL_ASSERT(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer->id));
}

void SDL_GL_UnbindIndexBuffer()
{
    GL_ASSERT(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}
*/
