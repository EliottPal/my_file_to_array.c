/*
** EPITECH PROJECT, 2019
** my_file_to_array
** File description:
** file -> char **, by Pal
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int my_strlen(char const *str)
{
    size_t i = 0;

    for (i = 0; str[i] != '\0'; i++);
    return (i);
}

static char **fill_tab(char *file, char **tab, int lines)
{
    FILE *fd = fopen(file, "r");
    char *buffer = NULL;
    size_t len = 0;
    int line_len = 0;
    int count = 0;

    for (count = 0; count != lines; count++) {
        getline(&buffer, &len, fd);
        line_len = my_strlen(buffer) - 1;
        tab[count] = malloc(sizeof(char) * (line_len + 1));
        if (!tab[count])
            exit(84);
        memset(tab[count], 0, line_len + 1);
        for (int i = 0; i != line_len; i++)
            tab[count][i] = buffer[i];
    }
    tab[count] = NULL;
    fclose(fd);
    return (tab);
}

char **my_file_to_array(char *file)
{
    FILE *fd = fopen(file, "r");
    char *buffer = NULL;
    size_t len = 0;
    int count = 0;
    char **tab;

    for (count = 0; getline(&buffer, &len, fd) != -1; count++);
    fclose(fd);
    tab = malloc(sizeof(char *) * (count + 1));
    if (!(tab))
        exit (84);
    fill_tab(file, tab, count);
    return (tab);
}
