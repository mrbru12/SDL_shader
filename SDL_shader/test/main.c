#define SDL_MAIN_HANDLED

#include "../include/SDL_shader.h"

#include <GL/glew.h>
#include <SDL.h>

// TODO: Fazer uma struct rect_buffer que tenha só um void* data e um size_t size
//       pra depois ficar mais fácil de abstrair os objects do OpenGL
float rect_buffer[] = {
    -0.5f, -0.5f, 1.0f, // Position (X, Y, Z)  
     1.0f,  0.0f, 0.0f, // Color    (R, G, B)
     0.5f, -0.5f, 1.0f, // Position (X, Y, Z)
     0.0f,  1.0f, 0.0f, // Color    (R, G, B)
     0.5,   0.5f, 1.0f, // Position (X, Y, Z)
     0.0f,  0.0f, 1.0f, // Color    (R, G, B)
    -0.5f,  0.5f, 1.0f, // Position (X, Y, Z)
     0.0f,  1.0f, 1.0f, // Color    (R, G, B)
};

float triangle_buffer[] = {
    -0.25f, -0.25f, 1.0f, // Position (X, Y, Z)
     1.0f,   1.0f,  0.0f, // Color    (R, G, B)
     0.25f, -0.25f, 1.0f, // Position (X, Y, Z)
     1.0f,   0.0f,  1.0f, // Color    (R, G, B)
     0.0f,   0.25f, 1.0f, // Position (X, Y, Z)
     0.0f,   1.0f,  1.0f, // Color    (R, G, B)
};                      

int main(int argc, char** argv)
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* window = SDL_GL_CreateWindow("SDL_shader Sandbox", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    SDL_GL_Renderer* renderer = SDL_GL_CreateRenderer(window);

    SDL_GL_Shader* rect_shader = SDL_GL_ShaderFromFile("test/res/shaders/test_shader.vert",
                                                       NULL,
                                                       "test/res/shaders/test_shader_1.frag");
    
    int u_color_location = glGetUniformLocation(SDL_GL_GetShaderProgramId(rect_shader), "u_color");

    SDL_GL_Shader* triangle_shader = SDL_GL_ShaderFromFile("test/res/shaders/test_shader.vert",
                                                           NULL,
                                                           "test/res/shaders/test_shader_2.frag");

    SDL_Event event;
    int event_break = 0, client_break = 0;
    while (!event_break && !client_break)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                event_break = 1;
                break;
            }
        }

        SDL_GL_RenderClear(renderer);

        SDL_GL_BindShader(triangle_shader);
        SDL_GL_RenderFillTriangle(renderer, 18 * sizeof(float), triangle_buffer);
        
        SDL_GL_BindShader(rect_shader);
        glUniform1f(u_color_location, fabs(sin(SDL_GetTicks() * 0.0015))); // glUniform4f(u_color_location, u_color, 1.0f, u_color, 1.0f);
        SDL_GL_RenderFillRect(renderer, 24 * sizeof(float), rect_buffer);

        SDL_GL_RenderPresent(renderer);
    }

    SDL_GL_DestroyRenderer(renderer);
    SDL_GL_DestroyShader(rect_shader);
    SDL_GL_DestroyShader(triangle_shader);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
