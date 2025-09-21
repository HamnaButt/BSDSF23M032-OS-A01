/* src/main.c */
#include <stdio.h>
#include <stdlib.h>
#include "../include/mystrfunctions.h"
#include "../include/myfilefunctions.h"

int main(void) {
    printf("--- Testing String Functions ---\n");
    char a[200] = "Hello";
    printf("strlen(\"%s\") = %d\n", a, mystrlen(a));
    mystrcat(a, " World");
    printf("after strcat: %s\n", a);
    char b[50];
    mystrcpy(b, "copy me");
    printf("copied: %s (len=%d)\n", b, mystrlen(b));

    printf("\n--- Testing File Functions ---\n");
    FILE* fp = fopen("sample.txt", "w+");
    if (!fp) { perror("fopen"); return 1; }
    fprintf(fp, "hello world\nthis is a test\ngrep line contains test\n");
    fflush(fp);

    int lines, words, chars;
    wordCount(fp, &lines, &words, &chars);
    printf("wordCount -> lines=%d words=%d chars=%d\n", lines, words, chars);

    char** matches = NULL;
    int m = mygrep(fp, "test", &matches);
    printf("mygrep found %d lines containing 'test'\n", m);
    for (int i = 0; i < m; i++) {
        printf("MATCH %d: %s", i+1, matches[i]);
        free(matches[i]);
    }
    free(matches);
    fclose(fp);
    return 0;
}

