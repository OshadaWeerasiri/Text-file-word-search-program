#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256


int searchWordInLine(const char *line, const char *word, int lineNumber) {
    int wordFound = 0;
    char *found = strstr(line, word);

    while (found != NULL) {
        wordFound = 1;
        printf("\n'%s' found at line %d\n\n", word, lineNumber);
        found = strstr(found + 1, word);
    }

    return wordFound;
}


void searchWordInFile(FILE *file, const char *word) {
    int lineNumber = 1;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        if (searchWordInLine(line, word, lineNumber)) {

            printf("Line %d: %s\n", lineNumber, line);
        }
        lineNumber++;
    }
}

int main() {
    char filename[MAX_LINE_LENGTH];
    char searchWord[MAX_LINE_LENGTH];
    FILE *file;

    printf("Enter the filename: ");
    scanf("%s", filename);

    printf("Enter the word to search: ");
    scanf("%s", searchWord);

    file = fopen(filename, "r");                                                // if file not exist
    if (file == NULL) {
        printf("Error opening the file '%s'\n", filename);
        return 1;
    }

    printf("Searching for the word '%s' in file '%s'\n", searchWord, filename); // if file exist
    searchWordInFile(file, searchWord);                                         // go to function

    fclose(file);

    return 0;
}

