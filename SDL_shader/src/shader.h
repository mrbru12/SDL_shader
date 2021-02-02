#pragma once

// ======================================================================================================
// SHADER OBJECT ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ======================================================================================================

typedef struct SDL_GL_Shader SDL_GL_Shader;

// SDL_GL_MemoryLoadShader()
SDL_GL_Shader* SDL_GL_ShaderFromMemory(const char* vertex_shader, const char* geometry_shader, const char* fragment_shader);
// SDL_GL_LoadShader()
SDL_GL_Shader* SDL_GL_ShaderFromFile(const char* vertex_path, const char* geometry_path, const char* fragment_path);

int SDL_GL_GetUniformLocation(SDL_GL_Shader* shader, const char* name);

// OBS: NULL to unbind
void SDL_GL_BindShader(SDL_GL_Shader* shader);

void SDL_GL_DestroyShader(SDL_GL_Shader* shader);
