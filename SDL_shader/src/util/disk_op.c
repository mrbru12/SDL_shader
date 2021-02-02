#include "disk_op.h"

#include <stdio.h>
#include <string.h>

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
