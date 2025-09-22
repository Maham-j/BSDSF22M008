// File: src/myfilefunctions.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/myfilefunctions.h"

// Count the number of lines, words, and characters in the passed file
int wordCount(FILE* file, int* lines, int* words, int* chars) {
    if (file == NULL) return -1;

    *lines = *words = *chars = 0;
    char ch, prev = ' ';

    while ((ch = fgetc(file)) != EOF) {
        (*chars)++;

        if (ch == '\n') (*lines)++;

        // Count words when transitioning from space/newline to character
        if ((ch != ' ' && ch != '\n' && ch != '\t') &&
            (prev == ' ' || prev == '\n' || prev == '\t')) {
            (*words)++;
        }
        prev = ch;
    }

    rewind(file); // reset file pointer for future use
    return 0; // success
}

// Search for lines containing search_str
int mygrep(FILE* fp, const char* search_str, char*** matches) {
    if (fp == NULL || search_str == NULL) return -1;

    char line[256];
    int count = 0;

    // Temporary storage for matching lines
    char** temp = malloc(sizeof(char*) * 100); // Max 100 matches

    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, search_str) != NULL) {
            temp[count] = strdup(line);
            count++;
        }
    }

    *matches = temp;
    rewind(fp); // reset pointer
    return count; // return number of matches
}
