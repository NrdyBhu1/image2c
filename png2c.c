#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#define SUPPORT_TEXT_MANIPULATION
#include "./text.c"

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

int main(int argc, char *argv[])
{
    shift(&argc, &argv);        // skip program name

    if (argc <= 0) {
        fprintf(stderr, "Usage: ./png2c <filepath.png> <header_name>\n");
        fprintf(stderr, "ERROR: expected file path\n");
        exit(1);
    }

    char *filepath = shift(&argc, &argv);

    int x, y, n;
    uint32_t *data = (uint32_t *)stbi_load(filepath, &x, &y, &n, 4);
    char* header_name = NULL;

    if (TextFindIndex(filepath, "/") != -1) {
        int file_path_array_len = 0;
        const char* *file_path_array = TextSplit(filepath, '/', &file_path_array_len);
        filepath = (char*)file_path_array[file_path_array_len-1];
    }
    
    if (TextFindIndex(filepath, ".png") != -1) {
        header_name = TextReplace(filepath, ".png", "");
    }

    if (TextFindIndex(filepath, ".jpg") != -1) {
        header_name = TextReplace(filepath, ".jpg", "");
    }

    header_name = (char*)TextToUpper(header_name);

    if (data == NULL) {
        fprintf(stderr, "Could not load file `%s`\n", filepath);
        exit(1);
    }

    // TODO: inclusion guards and the array name are not customizable
    printf("#ifndef %s_H_\n", header_name);
    printf("#define %s_H_\n", header_name);
    printf("size_t %s_WIDTH = %d;\n", header_name, x);
    printf("size_t %s_HEIGHT = %d;\n", header_name, y);
    printf("uint32_t %s[] = {", header_name);
    for (size_t i = 0; i < (size_t)(x * y); ++i) {
        printf("0x%x, ", data[i]);
    }
    printf("};\n");
    printf("#endif // %s_H_\n", header_name);

    return 0;
}
