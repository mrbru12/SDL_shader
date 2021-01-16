#include "vertex_buffer.h"

// ======================================================================================================
// VERTEX BUFFER OBJECT |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ======================================================================================================

/*
SDL_GL_VertexBuffer* SDL_GL_CreateVertexBuffer(void* data, unsigned int size)
{
    SDL_GL_VertexBuffer* vbo = malloc(sizeof(SDL_GL_VertexBuffer));

    if (vbo)
    {
        vbo->data = data;
        vbo->size = size;
        vbo->usage = GL_STATIC_DRAW;

        GL_ASSERT(glGenBuffers(1, &(vbo->id)));
        GL_ASSERT(glBindBuffer(GL_ARRAY_BUFFER, vbo->id));
        GL_ASSERT(glBufferData(GL_ARRAY_BUFFER, vbo->size, vbo->data, vbo->usage));
    }

    return vbo;
}

void SDL_GL_DestroyVertexBuffer(SDL_GL_VertexBuffer* vbo)
{
    GL_ASSERT(glDeleteBuffers(1, &(vbo->id)));

    free(vbo);
}

void SDL_GL_BindVertexBuffer(SDL_GL_VertexBuffer* vbo)
{
    GL_ASSERT(glBindBuffer(GL_ARRAY_BUFFER, vbo->id));
}

void SDL_GL_UnbindVertexBuffer()
{
    GL_ASSERT(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
*/
