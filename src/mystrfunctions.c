/* src/mystrfunctions.c */
#include "../include/mystrfunctions.h"

int mystrlen(const char* s) {
    int i = 0;
    if (!s) return 0;
    while (s[i]) i++;
    return i;
}

int mystrcpy(char* dest, const char* src) {
    int i = 0;
    if (!dest || !src) return -1;
    while ((dest[i] = src[i]) != '\0') i++;
    return i; // number of chars copied (excluding null)
}

int mystrncpy(char* dest, const char* src, int n) {
    int i;
    if (!dest || !src || n <= 0) return -1;
    for (i = 0; i < n - 1 && src[i]; i++) dest[i] = src[i];
    dest[i] = '\0';
    return i;
}

int mystrcat(char* dest, const char* src) {
    int d = 0, s = 0;
    if (!dest || !src) return -1;
    while (dest[d]) d++;
    while ((dest[d++] = src[s++]) != '\0') ;
    return d - 1; // new length (excluding null)
}

