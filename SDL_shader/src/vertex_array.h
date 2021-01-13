#pragma once

// ======================================================================================================
// VERTEX ARRAY OBJECT ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ======================================================================================================

/*
>>> EXPLICAÇÃO DETALHADA DO glVertexAttribPointer()

float vertex_buffer[] = {
    |    Coordinates    |   Color   | Sides |
    -0.45f,  0.45f, 1.0f, 0.0f, 0.0f,  4.0f,
     0.45f,  0.45f, 0.0f, 1.0f, 0.0f,  8.0f,
     0.45f, -0.45f, 0.0f, 0.0f, 1.0f, 16.0f,
    -0.45f, -0.45f, 1.0f, 1.0f, 0.0f, 32.0f
};

// Specify layout of point data:
// > [index]: O mesmo indice que vai ser usado no "layout(position = {index})" na shader
// > [size]: A contagem de valores do tipo {type}, não em bytes e sim em quantidade
// > [type]: O tipo dos valores
// > [normalized]: Se os valores devem ou não ser transformados para um range de 0.0 a 1.0
// > [stride]: De quantos em quantos bytes o começo desse attrib aparece denovo
// > [pointer]: Em que posição do buffer, em bytes, esse attrib aparece pela primeira vez

GLint pos_attrib_location = glGetAttribLocation(shaderProgram, "pos");
glEnableVertexAttribArray(pos_attrib_location);
glVertexAttribPointer(pos_attrib_location, 2, GL_FLOAT, GL_FALSE,
                      6 * sizeof(float), (void*)0);

GLint color_attrib_location = glGetAttribLocation(shaderProgram, "color");
glEnableVertexAttribArray(color_attrib_location);
glVertexAttribPointer(color_attrib_location, 3, GL_FLOAT, GL_FALSE,
                      6 * sizeof(float), (void*)(2 * sizeof(float)));

GLint sides_attrib_location = glGetAttribLocation(shaderProgram, "sides");
glEnableVertexAttribArray(sides_attrib_location);
glVertexAttribPointer(sides_attrib_location, 1, GL_FLOAT, GL_FALSE,
                      6 * sizeof(float), (void*)(5 * sizeof(float)));
*/

/*
typedef struct
{
    unsigned int id;
    // SDL_GL_VertexBuffer* vertex_buffers;
    // unsigned int vertex_buffers_count;
    // SDL_GL_IndexBuffer* index_buffers;
    // unsigned int index_buffers_count;
} SDL_GL_VertexArray;
*/
