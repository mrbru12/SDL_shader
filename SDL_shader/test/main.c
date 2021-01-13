#define SDL_MAIN_HANDLED

#include "../include/SDL_shader.h"

#include "../src/debug.h"

#include <stdio.h>
#include <GL/glew.h>
#include <SDL.h>
#include <SDL_opengl.h>

// ==========================================================

unsigned int vao;
unsigned int buffer; // SDL_GL_VertexBuffer* buffer;
unsigned int ibo; // SDL_GL_IndexBuffer* ibo;
SDL_GL_Shader* shader;

float positions[] = {
    -0.5f, -0.5f, 
     1.0f,  0.0f, 0.0f,
     0.5f, -0.5f, 
     0.0f,  1.0f, 0.0f,
     0.5, 0.5f,
     0.0f,  0.0f, 1.0f,
    -0.5f,  0.5f,
     0.0f,  1.0f, 1.0f,
};

const unsigned int indices[] = {
    0, 1, 2,
    2, 3, 0
};

int u_color_location;

void on_create()
{
    // OBS: O vertex array guarda os vertex buffers e os index buffers que forem bindados e também 
    //      as calls de atributos como a glEnableVertexAttribArray() e glVertexAttribPointer()!!!
    GL_ASSERT(glGenVertexArrays(1, &vao));
    GL_ASSERT(glBindVertexArray(vao));
    
    GL_ASSERT(glGenBuffers(1, &buffer));
    GL_ASSERT(glBindBuffer(GL_ARRAY_BUFFER, buffer));
    GL_ASSERT(glBufferData(GL_ARRAY_BUFFER, 20 * sizeof(float), positions, GL_STATIC_DRAW));
    // buffer = SDL_GL_CreateVertexBuffer(positions, 4 * 2 * sizeof(float));

    GL_ASSERT(glEnableVertexAttribArray(0)); // position
    GL_ASSERT(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0));

    GL_ASSERT(glEnableVertexAttribArray(1)); // color
    GL_ASSERT(glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float))));

    GL_ASSERT(glGenBuffers(1, &ibo));
    GL_ASSERT(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));
    GL_ASSERT(glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW));
    // ibo = SDL_GL_CreateIndexBuffer(indices, 6 * sizeof(unsigned int));

    shader = SDL_GL_ShaderFromFile("test/res/shaders/test_shader.vert",
                                   NULL,
                                   "test/res/shaders/test_shader.frag");
    SDL_GL_BindShader(shader);
    
    u_color_location = glGetUniformLocation(SDL_GL_GetShaderProgramId(shader), "u_color");
    
    // Dando unbind em tudo pra demonstrar como funciona o Vertex Array Object (VAO)
    // GL_ASSERT(glBindVertexArray(0));
    // GL_ASSERT(glBindBuffer(GL_ARRAY_BUFFER, 0)); // SDL_GL_UnbindVertexBuffer();
    // GL_ASSERT(glDisableVertexAttribArray(0));
    // GL_ASSERT(glDisableVertexAttribArray(1));
    // GL_ASSERT(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0)); // SDL_GL_UnbindIndexBuffer();
    // GL_ASSERT(glUseProgram(0));
}

void on_update()
{
    // OBS: O vertex array guarda os vertex buffers e os index buffers que forem bindados e também 
    //      as calls de atributos como a glEnableVertexAttribArray() e glVertexAttribPointer()!!!
    // glBindVertexArray(vao);
    
    // glUseProgram(shader.program_id);
    // glUniform4f(u_color_location, 0.2f, 0.4f, 0.8f , 1.0f);
    
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL); // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
}

void on_destroy()
{
    // SDL_GL_DestroyVertexBuffer(buffer);
    // SDL_GL_DestroyIndexBuffer(ibo);
}

// ==========================================================

int main(int argc, char** argv)
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* window = SDL_GL_CreateWindow("SDL_shader Sandbox", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    
    SDL_GLContext context = SDL_GL_CreateContext(window);
    
    if (glewInit() != GLEW_OK)
        printf("ERROR: Initializing GLEW!");
    // printf("%s", glGetString(GL_VERSION));

    SDL_GL_SetSwapInterval(1);

    int w, h;
    SDL_GetWindowSize(window, &w, &h);
    glViewport(0, 0, w, h);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // =========== BOOT ============

    on_create();

    // =============================

    SDL_Event event;
    int eventBreak = 0, clientBreak = 0;

    while (!eventBreak && !clientBreak)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                eventBreak = 1;
                break;
            }
        }
        
        glClear(GL_COLOR_BUFFER_BIT);

        // ========== RENDER ===========

        on_update();

        // =============================

        SDL_GL_SwapWindow(window);
    }

    // ========== DESTROY ==========

    on_destroy();

    // =============================
    
    // SDL_GL_DestroyShader(shader);
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
