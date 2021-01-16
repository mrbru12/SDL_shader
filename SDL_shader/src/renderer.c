#include "../include/SDL_shader.h"

#include <stdlib.h>
#include <stdio.h>
#include <GL/glew.h>
#include <SDL.h>

struct SDL_GL_Renderer
{
    // TODO: Nesse ponto, provavelmente eu vou precisar guardar informações de vários VAOs 
    //       dentro de uma instancia do SDL_GL_Renderer pra, por exemplo, ter um VAO para
    //       triangulos, um para circulos, um para retangulos (talvez de pra botar todas 
    //       essas formas geometricas dentro de 1 só e mudar só o IBO), um para texturas, 
    //       um pra meshes, alguns pra objetos 3D como cubos e esferas, etc... Nesse caso,
    //       o ideal vai ser, provavelmente, criar algumas funções que abstraem um pouco o
    //       OpenGL vanilla pra criar e gerenciar os objetos, mas ai eu vejo na hora como
    //       vou fazer porque se eu já souber certinho o que eu vou precisar vai ficar bem
    //       mais fácil de bolar uma forma boa pra fazer as abstrações.

    SDL_Window* window;
    SDL_GLContext context;

    // unsigned int shape_2d_vao; // VAO pra desenhar formas como: triângulos, círculos, retângulos e linhas
    // unsigned int shape_2d_vbo;

    unsigned int shape_3d_vao; // OBS: talvez não precise de um pra 2D porque é só passar 1.0 no pos.z do 3D
    unsigned int shape_3d_vbo;
    unsigned int shape_3d_ibo;
};

SDL_GL_Renderer* SDL_GL_CreateRenderer(SDL_Window* window)
{
    SDL_GL_Renderer* renderer = (SDL_GL_Renderer*)malloc(sizeof(SDL_GL_Renderer));
    
    if (renderer)
    {
        renderer->window = window;
        renderer->context = SDL_GL_CreateContext(window);

        if (glewInit() != GLEW_OK) // No caso eu vo inicializar o meu próprio wrapper quando ele tiver pronto
            printf("ERROR: Initializing GLEW!");
        // printf("%s", glGetString(GL_VERSION));

        // Set VSync on to match monitor update rate:
        SDL_GL_SetSwapInterval(1);

        // Enable alpha color blending:
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        int w, h;
        SDL_GetWindowSize(window, &w, &h);
        glViewport(0, 0, w, h);

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

        glGenVertexArrays(1, &renderer->shape_3d_vao);
        glBindVertexArray(renderer->shape_3d_vao);

        glGenBuffers(1, &renderer->shape_3d_vbo);
        glBindBuffer(GL_ARRAY_BUFFER, renderer->shape_3d_vbo);

        // Position attribute: (X, Y, Z)
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);

        // Color attribute: (R, G, B)
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));

        glGenBuffers(1, &renderer->shape_3d_ibo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, renderer->shape_3d_ibo);

        return renderer;
    }

    return NULL;
}

void SDL_GL_DestroyRenderer(SDL_GL_Renderer* renderer)
{
    // TODO: Cleanup all renderer things like gl objects, etc... before deleting context!

    SDL_GL_DeleteContext(renderer->context);

    free(renderer);
}

void SDL_GL_RenderClear(SDL_GL_Renderer* renderer)
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void SDL_GL_RenderPresent(SDL_GL_Renderer* renderer)
{
    SDL_GL_SwapWindow(renderer->window);
}

// TODO: Fazer uma função tipo draw_indexed() pra não precisar ficar colando o mesmo código
//       do processo de draw do OpenGL em cada função RenderDraw... 

void SDL_GL_RenderFillTriangle(SDL_GL_Renderer* renderer, size_t size, void* data)
{
    glBindVertexArray(renderer->shape_3d_vao);

    glBindBuffer(GL_ARRAY_BUFFER, renderer->shape_3d_vbo);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    
    unsigned int indices[] = {
        0, 1, 2
    };
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, renderer->shape_3d_ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3 * sizeof(unsigned int), indices, GL_STATIC_DRAW);

    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, NULL);
}

void SDL_GL_RenderFillRect(SDL_GL_Renderer* renderer, size_t size, void* data)
{
    glBindVertexArray(renderer->shape_3d_vao);

    glBindBuffer(GL_ARRAY_BUFFER, renderer->shape_3d_vbo);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);

    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0
    };
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, renderer->shape_3d_ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
}
