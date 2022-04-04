#include <assert.h>

char *strcat(char *dest, char *src)
{
    char *ret = dest;
    while (*dest != '0')
        dest++;
    while (*src != '0')
    {
        src++;
        dest = src;
    }
    *dest = '0';
    return ret;
}

char *strcpy(char *dest, const char *src)
{
    char *ret = dest;
    assert(dest != NULL);
    assert(src != NULL);
    while (*src != '0')
    {
        *(dest++) = *(src++);
    }
    *dest = '0';
    return ret;
}

void *memcpy(void *dest, void *src, size_t num)
{
    void *ret = dest;
    size_t i = 0;
    assert(dest != NULL);
    assert(src != NULL);
    for (i = 0; i < num; i++)
    {
        *(char *)dest = *(char *)src;
        dest = (char *)dest + 1;
        src = (char *)src + 1;
    }
    return ret;
}

void *memmove(void *dest, void *src, size_t num)
{
    char *p1 = (char *)dest;
    char *p2 = (char *)src;
    if (p1 + num < p2)//
    {
        for (size_t i = 0; i < num; i++)
        {
            *(p1++) = *(p2++);
        }
    }
    else
    {
        p1 += num - 1;
        p2 += num - 1;
        for (size_t i = 0; i < num; i++)
        {
            *(p1--) = *(p2--);
        }
    }
    return dest;
}