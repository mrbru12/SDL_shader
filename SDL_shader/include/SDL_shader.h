#pragma once

// #include <GL/glew.h>
// #include "../src/debug.h"
#include "../src/vertex_buffer.h"
#include "../src/index_buffer.h"
#include "../src/vertex_array.h"
#include "../src/shader.h"
#include "../src/window.h"
#include "../src/renderer.h"

// -- TODO --
// * Dar uma leve refatorada nas funções de compilar e linkar shaders pra deixa mais organziado.
// * Fazer o meu próprio wraper do OpenGL ao invés de usar GLEW. Pelo que eu vi, na própria lib do SDL
//   tem umas func que facilitam muito isso, como a SDL_GL_GetProcAddress() e etc...
// * Compilar versões x86(32-bits) e x64(64-bits), refatorando o código para ele ser portável para
//   diferentes platafaormas e versões mais antigas do OpenGL (provavelmente fazer ele ser portável até
//   a primeira versão que implementou shaders)
// * Um negócio que eu tembém tenho que começar a fazer é usar um compilador de C ao invés do de C++
// * Talvez mudar o prefixo das funções e das structs pra não ficar igual as do SDL
// * Talvez retornar um SDL_GL_Shader* na hora de compilar as shaders pra depois dar free em uma função
//   no estilo das do SDL, como a SDL_DestroyWindow(). Também daria pra usar as funcs de descarte do OpenGL
//   depois, dentro dessa mesma func, para limpar as shaders da forma certa. E a func de bind de shaders 
//   poderia ser SDL_GL_BindShader(SDL_GL_Shader* shader) ou algo do tipo, podendo passar NULL pra dar 
//   "unbind". Fazer que nem no SDL também e retornar NULL caso ocorra algum erro na SDL_ShaderFrom...()
// * Também faze aquele negócio espertinho do SDL quando retorna SDL_Window que na verdade é só um void* 
//   (eu acho), depois é só dar cast pra SDL_WindowInfo que aparentemente é a struct mesmo. O SDL faz isso
//   pra manter meio privadas as informações da SDL_WindowInfo eu acho. Daria pra eu faze um typedef void*
//   SDL_GL_Shader e um typedef struct SDL_GL_ShaderInfo com todas as informações mesmo, depois é só dar
//   casts pra mudar de um para o outro.
// * Tentar entender melhor como funciona o glVertexAttribPointer() https://youtu.be/x0H--CL2tUI 
// * Talvez passar os sources das shaders como um char** pra quando eu for adicionar outras (como a geometry
//   e a tesselation) dar pra passa NULL se não for implementar alguma delas
// * Fazer um sistema melhor de error handlind do que os printfs que eu to usando
// * Implementar a glDebugMessageCallback() pra fazer debug ao invés de glGetError() porque como tu pode
//   passar o callback de uma função pra ela, sempre que der algum erro no OpenGL ele vai simplesmente
//   chamar a função que tu passou, deixando tudo mais simples e otimizado. OBS: lembrar que essa parte do
//   debug só deve tar ativada quando tiver compilando em modo DEBUG!

// void SDL_InitShader(); 
// Na verdade vai ter uma funça tipo CreateShaderRenderer() ou algo do tipo que já vai inicializar
// tudo e retornar um SDL_GL_ShaderRenderer pra ser usado nas funções de draw e tudo mais, do mesmo
// jeito que é feito com o SDL_Renderer 
