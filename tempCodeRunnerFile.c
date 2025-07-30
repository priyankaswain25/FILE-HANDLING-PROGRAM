#include <stdio.h>
#include <stdlib.h>

void writeToFile() {
    FILE *fp = fopen("file.txt", "w"); // Create/Write mode
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(fp, "This is the first line written to the file.\n");
    fclose(fp);
    printf("Data written successfully.\n");
}

void readFromFile() {
    char ch;
    FILE *fp = fopen("file.txt", "r"); // Read mode
    if (fp == NULL) {
        printf("File does not exist or can't be opened.\n");
        return;
    }
    printf("Reading file content:\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);
}

void appendToFile() {
    FILE *fp = fopen("file.txt", "a"); // Append mode
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(fp, "This is an appended line.\n");
    fclose(fp);
    printf("Data appended successfully.\n");
}

int main() {
    int choice;
    do {
        printf("\nFILE HANDLING MENU\n");
        printf("1. Write to File\n");
        printf("2. Read from File\n");
        printf("3. Append to File\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline after scanf

        switch (choice) {
            case 1: writeToFile(); break;
            case 2: readFromFile(); break;
            case 3: appendToFile(); break;
            case 4: printf("Exiting program.\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}