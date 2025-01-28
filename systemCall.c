#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <limits.h>

#ifndef NAME_MAX
#define NAME_MAX 255 // Define NAME_MAX if it's not already defined
#endif

void list_file();
void directory();
void change_dir();
void subfun(const char *s);

int main()
{
    int ch;
    do
    {
        printf("\n\t\t\tMAIN MENU\n\t\t-------------------------\n");
        printf("1. To Display List of Files\n");
        printf("2. To Create New Directory\n");
        printf("3. To Change the Working Directory\n");
        printf("4. Exit\n");
        printf("Enter the Number: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            list_file();
            break;
        case 2:
            directory();
            break;
        case 3:
            change_dir();
            break;
        case 4:
            exit(0);
        }
    } while (ch <= 4);
    return 0;
}

void list_file()
{
    int l;
    char e[NAME_MAX] = "*";
    printf("\t\tLIST FILE DETAIL\n\t--------------------------------------\n");
    printf("1. List All Files\n2. List of Extension Files\n3. List of Name Wise\n");
    scanf("%d", &l);
    switch (l)
    {
    case 1:
        printf("List of All(*) Files\n");
        subfun(e);
        break;
    case 2:
        printf("Enter the Extension: ");
        scanf("%s", e);
        subfun(e);
        break;
    case 3:
        printf("Enter the Name wise (e.g., moha*): ");
        scanf("%s", e);
        subfun(e);
        break;
    }
}

void directory()
{
    char name[NAME_MAX];
    char buffer[PATH_MAX];
    printf("Enter the Directory name: ");
    scanf("%s", name);
    if (getcwd(buffer, sizeof(buffer)) != NULL)
    {
        printf("Current directory: %s\n", buffer);
    }
    else
    {
        perror("Error getting current directory");
        return;
    }

    struct stat st;
    if (stat(name, &st) == 0 && S_ISDIR(st.st_mode))
    {
        printf("%s already exists.\n", name);
        return;
    }
    else
    {
        if (mkdir(name) == 0)
        {
            printf("%s Directory Successfully Created\n", name);
        }
        else
        {
            perror("Error creating directory");
        }
    }
}

void change_dir()
{
    char buffer[PATH_MAX];
    int d;
    if (getcwd(buffer, sizeof(buffer)) != NULL)
    {
        printf("\nCurrent Directory: %s\n", buffer);
    }
    else
    {
        perror("Error getting current directory");
        return;
    }
    printf("\t\tChange Directory\n\t\t-----------------\n");
    printf("\n1. Step by Step Backward\n2. Goto Root Directory\n3. Forward Directory\nEnter the number: ");
    scanf("%d", &d);
    switch (d)
    {
    case 1:
        chdir("..");
        break;
    case 2:
        chdir("/");
        break;
    case 3:
        printf("Please enter the Directory name: ");
        scanf("%s", buffer);
        chdir(buffer);
        break;
    }
    if (getcwd(buffer, sizeof(buffer)) != NULL)
    {
        printf("\nCurrent Directory: %s\n", buffer);
    }
    else
    {
        perror("Error getting current directory");
    }
}

void subfun(const char *s)
{
    DIR *dir;
    struct dirent *ent;
    int i = 0;
    if ((dir = opendir(".")) != NULL)
    {
        while ((ent = readdir(dir)) != NULL)
        {
            if (strstr(ent->d_name, s) != NULL)
            {
                printf("%s\n", ent->d_name);
                i++;
            }
        }
        closedir(dir);
    }
    else
    {
        perror("Could not open directory");
    }
    printf("\nTotal Files: %d\n", i);
}
