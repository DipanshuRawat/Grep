// Header Files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void grep(const char *pattern, const char *leo) {
    FILE *file = fopen(leo, "r"); // open the file
    if (file == NULL) {           // if file not found
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];  //buffer to store each line from the file
    while (fgets(line, sizeof(line), file)) {  //reads line
        if (strstr(line, pattern)) {    //check line contain pattern
            printf("%s", line);         // print match line
        }
    }

    fclose(file);           // close the file
}

// main function

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <pattern> <leo>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *pattern = argv[1];
    const char *leo = argv[2];

    grep(pattern, leo);

    return EXIT_SUCCESS;
}