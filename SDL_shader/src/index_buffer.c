#include "index_buffer.h"

// ======================================================================================================
// INDEX BUFFER OBJECT ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ======================================================================================================

/*
SDL_GL_IndexBuffer* SDL_GL_CreateIndexBuffer(const unsigned int* data, unsigned int size)
{
    SDL_GL_VertexBuffer* vbo = malloc(sizeof(SDL_GL_IndexBuffer));

    if (vbo)
    {
        vbo->data = data;
        vbo->size = size;
        vbo->usage = GL_STATIC_DRAW;

        GL_ASSERT(glGenBuffers(1, &(vbo->id)));
        GL_ASSERT(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo->id));
        GL_ASSERT(glBufferData(GL_ELEMENT_ARRAY_BUFFER, vbo->size, vbo->data, vbo->usage));
    }

    return vbo;
}

void SDL_GL_DestroyIndexBuffer(SDL_GL_IndexBuffer* vbo)
{
    GL_ASSERT(glDeleteBuffers(1, &(vbo->id)));

    free(vbo);
}

void SDL_GL_BindIndexBuffer(SDL_GL_IndexBuffer* vbo)
{
    GL_ASSERT(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo->id));
}

void SDL_GL_UnbindIndexBuffer()
{
    GL_ASSERT(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}
*/
