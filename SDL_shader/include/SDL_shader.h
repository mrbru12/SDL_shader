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
// * Dar uma leve refatorada nas fun��es de compilar e linkar shaders pra deixa mais organziado.
// * Fazer o meu pr�prio wraper do OpenGL ao inv�s de usar GLEW. Pelo que eu vi, na pr�pria lib do SDL
//   tem umas func que facilitam muito isso, como a SDL_GL_GetProcAddress() e etc...
// * Compilar vers�es x86(32-bits) e x64(64-bits), refatorando o c�digo para ele ser port�vel para
//   diferentes platafaormas e vers�es mais antigas do OpenGL (provavelmente fazer ele ser port�vel at�
//   a primeira vers�o que implementou shaders)
// * Um neg�cio que eu temb�m tenho que come�ar a fazer � usar um compilador de C ao inv�s do de C++
// * Talvez mudar o prefixo das fun��es e das structs pra n�o ficar igual as do SDL
// * Talvez retornar um SDL_GL_Shader* na hora de compilar as shaders pra depois dar free em uma fun��o
//   no estilo das do SDL, como a SDL_DestroyWindow(). Tamb�m daria pra usar as funcs de descarte do OpenGL
//   depois, dentro dessa mesma func, para limpar as shaders da forma certa. E a func de bind de shaders 
//   poderia ser SDL_GL_BindShader(SDL_GL_Shader* shader) ou algo do tipo, podendo passar NULL pra dar 
//   "unbind". Fazer que nem no SDL tamb�m e retornar NULL caso ocorra algum erro na SDL_ShaderFrom...()
// * Tamb�m faze aquele neg�cio espertinho do SDL quando retorna SDL_Window que na verdade � s� um void* 
//   (eu acho), depois � s� dar cast pra SDL_WindowInfo que aparentemente � a struct mesmo. O SDL faz isso
//   pra manter meio privadas as informa��es da SDL_WindowInfo eu acho. Daria pra eu faze um typedef void*
//   SDL_GL_Shader e um typedef struct SDL_GL_ShaderInfo com todas as informa��es mesmo, depois � s� dar
//   casts pra mudar de um para o outro.
// * Tentar entender melhor como funciona o glVertexAttribPointer() https://youtu.be/x0H--CL2tUI 
// * Talvez passar os sources das shaders como um char** pra quando eu for adicionar outras (como a geometry
//   e a tesselation) dar pra passa NULL se n�o for implementar alguma delas
// * Fazer um sistema melhor de error handlind do que os printfs que eu to usando
// * Implementar a glDebugMessageCallback() pra fazer debug ao inv�s de glGetError() porque como tu pode
//   passar o callback de uma fun��o pra ela, sempre que der algum erro no OpenGL ele vai simplesmente
//   chamar a fun��o que tu passou, deixando tudo mais simples e otimizado. OBS: lembrar que essa parte do
//   debug s� deve tar ativada quando tiver compilando em modo DEBUG!

// void SDL_InitShader(); 
// Na verdade vai ter uma fun�a tipo CreateShaderRenderer() ou algo do tipo que j� vai inicializar
// tudo e retornar um SDL_GL_ShaderRenderer pra ser usado nas fun��es de draw e tudo mais, do mesmo
// jeito que � feito com o SDL_Renderer 
