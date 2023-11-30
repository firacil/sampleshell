#include "main.h"

/**
 * _puts - prints string.
 * @s: string to be printed.
 * Return: None.
 */
void _puts(char *s)
{
        while (*s != '\0')
        {
                write(1, s, 1);
                s++;
        }
}
