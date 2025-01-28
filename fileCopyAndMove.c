#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_FILENAME_LENGTH 100

void copy_file();
void move_file();
void print_files();

char fn2[MAX_FILENAME_LENGTH];

int main() {
    int c;

    do {
        printf("\n\t\tMain Menu\n-------------------------------\n");
        printf("1. Copy a File\n2. Move a File\n3. Exit\nEnter your choice : ");
        scanf("%d", &c);
        getchar(); // to consume the newline character left by scanf

        switch (c) {
            case 1:
                copy_file();
                break;
            case 2:
                move_file();
                break;
            case 3:
                printf("Exiting...");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (c != 3);

    return 0;
}

void copy_file() {
    FILE *f1, *f2;
    char ch;
    int a;
    char fn1[MAX_FILENAME_LENGTH];

    printf("\nDo you want to see the previous files in the directory (1/0)? ");
    scanf("%d", &a);
    getchar(); // consume newline
    if (a == 1) {
        print_files();
    }

    printf("Enter the source file name: ");
    scanf("%99s", fn1);
    printf("Enter the destination file name: ");
    scanf("%99s", fn2);

    f1 = fopen(fn1, "r");
    if (f1 == NULL) {
        printf("Can't open the source file.\n");
        return;
    }

    f2 = fopen(fn2, "w");
    if (f2 == NULL) {
        printf("Can't open the destination file.\n");
        fclose(f1);
        return;
    }

    while ((ch = fgetc(f1)) != EOF) {
        fputc(ch, f2);
    }

    printf("File copied successfully.\n");

    fclose(f1);
    fclose(f2);
}

void move_file() {
    FILE *f1, *f2;
    char ch;
    int a;
    char fn1[MAX_FILENAME_LENGTH];

    printf("\nDo you want to see the previous files in the directory (1/0)? ");
    scanf("%d", &a);
    getchar(); // consume newline
    if (a == 1) {
        print_files();
    }

    printf("Enter the source file name: ");
    scanf("%99s", fn1);
    printf("Enter the destination file name: ");
    scanf("%99s", fn2);

    f1 = fopen(fn1, "r");
    if (f1 == NULL) {
        printf("Can't open the source file.\n");
        return;
    }

    f2 = fopen(fn2, "w");
    if (f2 == NULL) {
        printf("Can't open the destination file.\n");
        fclose(f1);
        return;
    }

    while ((ch = fgetc(f1)) != EOF) {
        fputc(ch, f2);
    }

    printf("File moved successfully.\n");

    fclose(f1);
    fclose(f2);

    // Delete the source file after copying
    if (remove(fn1) == 0) {
        printf("Source file deleted successfully.\n");
    } else {
        printf("Failed to delete the source file.\n");
    }
}

void print_files() {
    struct dirent *entry;
    DIR *dp = opendir(".");

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    printf("\nFiles in the current directory:\n");
    while ((entry = readdir(dp)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dp);
}
