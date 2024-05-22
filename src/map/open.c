/*
** EPITECH PROJECT, 2024
** open
** File description:
** read
*/

#include "my.h"

char *open_read(const char *path)
{
    struct stat sb;
    FILE *file;
    char *buffer = NULL;
    size_t len;
    size_t res;

    if (lstat(path, &sb) == -1)
        exit(84);
    len = sb.st_size;
    buffer = malloc(sizeof(char) * len);
    if (buffer == NULL)
        exit(84);
    memset(buffer, 0, sizeof(char) * len);
    file = fopen(path, "r");
    res = fread(buffer, sizeof(char), len, file);
    if (res != len)
        exit(84);
    fclose(file);
    buffer[len - 1] = '\0';
    return buffer;
}
