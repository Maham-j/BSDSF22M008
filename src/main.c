// File: src/main.c
#include <stdio.h>
#include <stdlib.h>
#include "../include/mystrfunctions.h"
#include "../include/myfilefunctions.h"

int main() {
    printf("--- Testing String Functions ---\n");

    char str1[50] = "Hello";
    char str2[50] = "World";

    // Test mystrlen
    printf("Length of str1: %d\n", mystrlen(str1));

    // Test mystrcpy
    mystrcpy(str2, str1);
    printf("After mystrcpy, str2: %s\n", str2);

    // Test mystrncpy
    mystrncpy(str2, "Goodbye", 4);
    printf("After mystrncpy (4 chars): %s\n", str2);

    // Test mystrcat
    mystrcat(str1, " Everyone");
    printf("After mystrcat, str1: %s\n", str1);

    printf("\n--- Testing File Functions ---\n");

    FILE* file = fopen("test.txt", "r");
    if (!file) {
        printf("Error: Could not open test.txt\n");
        return -1;
    }

    int lines, words, chars;
    if (wordCount(file, &lines, &words, &chars) == 0) {
        printf("Lines: %d, Words: %d, Characters: %d\n", lines, words, chars);
    } else {
        printf("wordCount function failed.\n");
    }

    // Test mygrep
    char** matches;
    int match_count = mygrep(file, "Hello", &matches);
    if (match_count > 0) {
        printf("Lines containing 'Hello':\n");
        for (int i = 0; i < match_count; i++) {
            printf("%s", matches[i]);
            free(matches[i]); // free memory
        }
        free(matches);
    } else {
        printf("No matches found or mygrep failed.\n");
    }

    fclose(file);
    return 0;
}
