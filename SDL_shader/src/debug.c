#include "debug.h"

#include <stdio.h>
#include <GL/glew.h>

/*
void gl_log(const char* title, const char* msg)
{
    printf("[OpenGL %s] (%s)\n", title, msg);
}
*/

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
