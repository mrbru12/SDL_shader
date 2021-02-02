#include "texture.h"

#include <GL/glew.h>
#include <stb_image.h>

#include <stdlib.h>

struct SDL_GL_Texture2D
{
    unsigned int* textures;

    unsigned int texture_units_count;
    unsigned int used_texture_units;
};

SDL_GL_Texture2D* SDL_GL_CreateTexture2D(unsigned int texture_units_count)
{
    // TODO: Setar isso em algum inicializador global pra não ficar setando toda a vez que criar uma textura
    stbi_set_flip_vertically_on_load(1);

    SDL_GL_Texture2D* texture = malloc(sizeof(SDL_GL_Texture2D));

    if (texture)
    {
        int max_texture_units;
        glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &max_texture_units);
        texture->texture_units_count = max(1, min(texture_units_count, max_texture_units));

        texture->used_texture_units = 0;

        texture->textures = malloc(texture->texture_units_count * sizeof(unsigned int));

        return texture;
    }

    return NULL;
}

void SDL_GL_DestroyTexture2D(SDL_GL_Texture2D* texture)
{
    glDeleteTextures(texture->used_texture_units, texture->textures);

    free(texture->textures);
    free(texture);
}

void SDL_GL_LoadTexture2D(SDL_GL_Texture2D* texture, const char* path)
{
    if (texture->used_texture_units < texture->texture_units_count)
    {
        glGenTextures(1, &(texture->textures[texture->used_texture_units]));

        glBindTexture(GL_TEXTURE_2D, texture->textures[texture->used_texture_units]);

        // TODO: Criar alguma interface para o usuário poder mudar esses parametros
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); // GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        int image_width, image_height, image_channels;
        unsigned char* image_data = stbi_load(path, &image_width, &image_height, &image_channels, 0);
        
        GLenum image_format;
        switch (image_channels)
        {
        case 3:
            image_format = GL_RGB;
            break;

        case 4:
            image_format = GL_RGBA;
            break;

        default:
            image_format = GL_RGB;
            break;
        }

        if (image_data)
        {
            // TODO: Talvez de ruim salvar qualquer formato como GL_RGBA
            glTexImage2D(GL_TEXTURE_2D, 0, image_format, image_width, image_height, 0, image_format, GL_UNSIGNED_BYTE, image_data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
            printf("Error while loading texture file: %s\n", path);

        stbi_image_free(image_data);

        texture->used_texture_units++;
    }
    else
        printf("Error while loading texture: Texture reached max texture units!\n");
}

void SDL_GL_BindTexture2D(SDL_GL_Texture2D* texture)
{
    if (texture)
    {
        for (int i = 0; i < texture->used_texture_units; i++)
        {
            glActiveTexture(GL_TEXTURE0 + i);
            glBindTexture(GL_TEXTURE_2D, texture->textures[i]);
        }
    }
 
    // TODO: Unbind texture
}
