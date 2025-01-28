#include <stdio.h>
#include <stdlib.h>

void createFile()
{
    char filename[100];
    FILE *file;

    printf("Enter the file name to create:\n");
    scanf("%s", filename);

    file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error creating the file.\n");
    }
    else
    {
        printf("File '%s' created successfully.\n", filename);
        fclose(file);
    }
}

void renameFile()
{
    char oldName[100], newName[100];

    printf("Enter the current file name to rename:\n");
    scanf("%s", oldName);
    printf("Enter the new file name:\n");
    scanf("%s", newName);

    if (rename(oldName, newName) == 0)
    {
        printf("File renamed successfully to '%s'.\n", newName);
    }
    else
    {
        printf("Error renaming the file.\n");
    }
}

void deleteFile()
{
    char filename[100];

    printf("Enter the file name to delete:\n");
    scanf("%s", filename);

    if (remove(filename) == 0)
    {
        printf("File '%s' deleted successfully.\n", filename);
    }
    else
    {
        printf("Error deleting the file.\n");
    }
}

void editFile()
{
    char filename[100], buffer[1024];
    FILE *file;

    printf("Enter the file name to edit:\n");
    scanf("%s", filename);

    file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error opening the file for editing.\n");
    }
    else
    {
        printf("Enter the content to write to the file:\n");
        getchar();                           
        fgets(buffer, sizeof(buffer), stdin);

        fprintf(file, "%s", buffer);
        printf("File '%s' edited successfully.\n", filename);
        fclose(file);
    }
}

void mainMenu()
{
    int choice;

    do
    {
        printf("\n\t\tMAIN MENU OF FILE OPERATIONS\n\t------------------------------------------------\n");
        printf("1. Create a File\n");
        printf("2. Rename a File\n");
        printf("3. Delete a File\n");
        printf("4. Edit a File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createFile();
            break;
        case 2:
            renameFile();
            break;
        case 3:
            deleteFile();
            break;
        case 4:
            editFile();
            break;
        case 5:
            printf("Exiting program.\n");
            exit(0);
            break;
        default:
            printf("Invalid choice! Please select again.\n");
        }
    } while (1);
}

int main()
{
    mainMenu();
    return 0;
}
