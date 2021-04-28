#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>

#define STB_IMAGE_IMPLEMENTATION
#include "./stb_image.h"

char *shift(int *argc, char ***argv)
{
    assert(*argc > 0);
    char *result = *argv[0];
    *argc -= 1;
    *argv += 1;
    return result;
}

void toUpper(char *str){
    while (*str != '\0')
    {
        *str = toupper(*str);
        str++;
    }
}

int main(int argc, char *argv[])
{
    shift(&argc, &argv);        // skip program name

    if (argc <= 0) {
        fprintf(stderr, "Usage: ./png2c <filepath.png>\n");
        fprintf(stderr, "ERROR: expected file path\n");
        exit(1);
    }

    char *filepath = shift(&argc, &argv);

    int x, y, n;
    uint32_t *data = (uint32_t *)stbi_load(filepath, &x, &y, &n, 4);
    toUpper(filepath);

    if (data == NULL) {
        fprintf(stderr, "Could not load file `%s`\n", filepath);
        exit(1);
    }

    // TODO: inclusion guards and the array name are not customizable
    printf("#ifndef %s_H_\n", filepath);
    printf("#define %s_H_\n", filepath);
    printf("size_t %s_WIDTH = %d;\n", filepath, x);
    printf("size_t %s_HEIGHT = %d;\n", filepath, y);
    printf("uint32_t %s[] = {", filepath);
    for (size_t i = 0; i < (size_t)(x * y); ++i) {
        printf("0x%x, ", data[i]);
    }
    printf("};\n");
    printf("#endif // %s_H_\n", filepath);

    return 0;
}
