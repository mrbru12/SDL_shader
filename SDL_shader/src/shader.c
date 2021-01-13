#include "shader.h"

#include "debug.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <GL/glew.h>

void compile_shader_source(unsigned int shader_id, const char* shader_source)
{
    // Settingand compiling shader's source code:
    glShaderSource(shader_id, 1, &shader_source, NULL);
    glCompileShader(shader_id);
    
    // Checking for shader compilation errors:
    int success;
    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        int info_log_len;
        glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &info_log_len);

        char* info_log = (char*)malloc(info_log_len);
        glGetShaderInfoLog(shader_id, info_log_len, NULL, info_log);

        printf("Bad shader compilation! *ERROR INFO BELOW*\n%s\n", info_log);

        free(info_log);
        
        // glDeleteShader(shader_id);
    }
}

void concatenate_file_lines(const char* path, const size_t text_buffer_size, char* text_buffer)
{
    FILE* file;

    // Check for errors at file path openning:
    if (fopen_s(&file, path, "r"))
        printf("Error while openning file: %s\n", path);

    // Check if file != NULL to please the compiler:
    if (file)
    {
        char line_buffer[512];
        while (fgets(line_buffer, sizeof(line_buffer), file))
            strncat_s(text_buffer, text_buffer_size, line_buffer, text_buffer_size - strlen(text_buffer));

        fclose(file);
    }
}

struct SDL_GL_Shader
{
    // TODO: Talvez não precise guaradar os ids da vert e da frag porque elas são deletadas depois do linking
    unsigned int vertex_id, geometry_id, fragment_id, program_id;
};

// TODO: Fazer que nem no SDL e retornar NULL caso ocorra algum erro!!!
SDL_GL_Shader* SDL_GL_ShaderFromMemory(const char* vertex_shader, const char* geometry_shader, const char* fragment_shader)
{
    SDL_GL_Shader* shader = (SDL_GL_Shader*)malloc(sizeof(SDL_GL_Shader));

    if (shader)
    {
        // Shader program will be used to bound the shaders:
        shader->program_id = glCreateProgram();

        // Vertex shader compilation:
        if (vertex_shader)
        {
            shader->vertex_id = glCreateShader(GL_VERTEX_SHADER);
            compile_shader_source(shader->vertex_id, vertex_shader);
            glAttachShader(shader->program_id, shader->vertex_id);
        }
        else
            shader->vertex_id = 0;

        // Geometry shader compilation:
        if (geometry_shader)
        {
            shader->geometry_id = glCreateShader(GL_GEOMETRY_SHADER);
            compile_shader_source(shader->geometry_id, geometry_shader);
            glAttachShader(shader->program_id, shader->geometry_id);
        }
        else
            shader->geometry_id = 0;

        // Fragment shader compilation:
        if (fragment_shader)
        {
            shader->fragment_id = glCreateShader(GL_FRAGMENT_SHADER);
            compile_shader_source(shader->fragment_id, fragment_shader);
            glAttachShader(shader->program_id, shader->fragment_id);
        }
        else
            shader->fragment_id = 0;

        // Shaders compiled code linking:
        glLinkProgram(shader->program_id);

        // Validate program, checking for problems:
        glValidateProgram(shader->program_id);

        // Checking for shader linking errors:
        int success;
        glGetProgramiv(shader->program_id, GL_LINK_STATUS, &success);
        if (!success)
        {
            int info_log_len;
            glGetProgramiv(shader->program_id, GL_INFO_LOG_LENGTH, &info_log_len);

            char* info_log = (char*)malloc(info_log_len);
            glGetProgramInfoLog(shader->program_id, info_log_len, NULL, info_log);

            printf("Bad shader linking! *ERROR INFO BELOW*\n%s\n", info_log);

            free(info_log);

            // glDeleteProgram(shader.program_id);
        }

        // We can delete compiled shader objects after linking. If id is equals to 0, it will be ignored:
        glDeleteShader(shader->vertex_id);
        glDeleteShader(shader->geometry_id);
        glDeleteShader(shader->fragment_id);

        return shader;
    }

    return NULL;
}

// TODO: Fazer que nem no SDL e retornar NULL caso ocorra algum erro!!!
SDL_GL_Shader* SDL_GL_ShaderFromFile(const char* vertex_path, const char* geometry_path, const char* fragment_path)
{
    const size_t size = 1024 * 10;

    char* vertex_shader = NULL;
    if (vertex_path)
    {
        vertex_shader = (char*)calloc(1, sizeof(char) * size);
        concatenate_file_lines(vertex_path, size, vertex_shader);
    }

    char* geometry_shader = NULL;
    if (geometry_path)
    {
        geometry_shader = (char*)calloc(1, sizeof(char) * size);
        concatenate_file_lines(geometry_path, size, geometry_shader);
    }

    char* fragment_shader = NULL;
    if (fragment_path)
    {
        fragment_shader = (char*)calloc(1, sizeof(char) * size);
        concatenate_file_lines(fragment_path, size, fragment_shader);
    }

    SDL_GL_Shader* shader = SDL_GL_ShaderFromMemory(vertex_shader, geometry_shader, fragment_shader);

    free(vertex_shader);
    free(geometry_shader);
    free(fragment_shader);

    return shader;
}

unsigned int SDL_GL_GetShaderProgramId(SDL_GL_Shader* shader)
{
    return shader->program_id;
}

void SDL_GL_BindShader(SDL_GL_Shader* shader)
{
    if (shader)
        glUseProgram(shader->program_id);
    else
        glUseProgram(0);
}

void SDL_GL_DestroyShader(SDL_GL_Shader* shader)
{
    glDeleteProgram(shader->program_id);

    free(shader);
}
