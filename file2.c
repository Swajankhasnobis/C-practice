#include <stdio.h>

int main() {
    FILE *file;
    char ch;

    // Open the file in read mode
    file = fopen("number.txt", "r");

    // Check if file opened successfully
    if (file == NULL) {
        printf("Could not open the file.\n");
        return 1;
    }

    // Move file pointer to the 5th byte from the beginning of the file
    fseek(file, 5, SEEK_SET);

    // Read and print the characters from the current position to end of file
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }

    // Close the file
    fclose(file);

    return 0;
}
