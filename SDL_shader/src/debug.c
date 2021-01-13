#include "debug.h"

#include <stdio.h>
#include <GL/glew.h>

int gl_log_errors()
{
    int result = 0;
    GLenum error = glGetError();

    if (error)
        result = 1;

    while (error)
    {
        printf("[OpenGL Error] (code: %i)\n", error);

        error = glGetError();
    }

    return result;
}
