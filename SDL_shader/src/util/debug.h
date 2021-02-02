#pragma once

// #define LOG_LEVEL_INFO "Info"
// #define LOG_LEVEL_WARN "Warn"
// #define LOG_LEVEL_ERROR "Error"

#ifdef _DEBUG
// Polls and clears all OpenGL errors in the error queue before calling x, then
// logs all errors that happened during the call of x. If there were errors, it
// will set a breakpoint in current line and break the program. Be aware that
// __debugbreak() function may not be compatible with every compiler.
#define GL_ASSERT(x) while (glGetError()); x; if (gl_log_errors()) __debugbreak()
#else
#define GL_ASSERT(x) x
#endif

// #define SDL_ASSERT(error_code, level, ...) if (error_code == -1) printf("[SDL %s] %s\n", level, ...);

// Polls and logs all OpenGL errors in the error queue 
int gl_log_errors();
