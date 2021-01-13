#pragma once

#ifdef _DEBUG
// Polls and clears all OpenGL errors in the error queue before calling x, then
// logs all errors that happened during the call of x. If there were errors, it
// will set a breakpoint in current line and break the program. Be aware that
// __debugbreak() function may not be compatible with every compiler.
#define GL_ASSERT(x) while (glGetError()); x; if (gl_log_errors()) __debugbreak()
#else
#define GL_ASSERT(x) x
#endif

// void gl_log(const char* msg);

// Polls and logs all OpenGL errors in the error queue 
int gl_log_errors();
