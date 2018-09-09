
#include <stddef.h>
#include <string.h>

int strcmp(const char *s1, const char *s2) {
    while (*s1 && *s2 && (*s1 == *s2)) {
        s1++;
        s2++;
    }

    return *s1 - *s2;
}

size_t strlen(const char *s) {
    size_t len = 0;
    while (*s) {
        s++;
        len++;
    }

    return len;
}

char *strchr(const char *s, int c) {
    while (*s && (*s != c)) {
        s++;
    }
    if (!*s)
        return NULL;
    else
        return (char *) s;
}

size_t strspn(const char *str, const char *accept) {
    size_t length = 0;
    while (*str) {
        char *a = (char *) accept;
        while (*a && *str != *a) {
            a++;
        }
        if (*a) {
            str++;
            length++;
        }
        else {
            return length;
        }
    }
    return length;
}

size_t strcspn(const char *str, const char *reject) {
    size_t length = 0;
    while (*str) {
        char *r = (char *) reject;
        while (*r && *str != *r) {
            r++;
        }
        if (*r) {
            return length;
        }
        else {
            str++;
            length++;
        }
    }
    return length;
}

char *strtok_r(char *str, const char *delim, char **saveptr) {
    if (!str) {
        if (!*saveptr)
            return NULL;
        str = *saveptr;
    }
    while (*str && strcspn(str, delim) == 0) {
        str++;
    }
    if (!*str) {
        return NULL;
    }
    char *delimiter_symbol;
    delimiter_symbol = str + strcspn(str, delim);
    if (*delimiter_symbol) {
        *delimiter_symbol = '\0';
        *saveptr = delimiter_symbol + 1;
    }
    else {
        *saveptr = delimiter_symbol;
    }
    return str;
}
