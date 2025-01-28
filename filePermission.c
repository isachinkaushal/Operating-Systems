#include <windows.h>
#include <stdio.h>

void main()
{
    char name[100];
    DWORD attrib;
    int n;

    printf("\t\t MAIN MENU OF PERMISSION \n\t-----------------------------------------------\n");
    printf("1.Only Read\n2.Only Write\n3.Exit\nEnter your choice: ");
    scanf("%d", &n);

    switch (n)
    {
    case 1:
        printf("Enter the File Name: ");
        scanf("%s", name);
        attrib = FILE_ATTRIBUTE_READONLY;
        printf("%s file read permission accepted", name);
        break;

    case 2:
        printf("\nEnter the File Name: \n");
        scanf("%s", name);
        attrib = FILE_ATTRIBUTE_NORMAL;
        printf("%s file write permission accepted name", name);
        break;

    case 3:
        exit(0);
        break;

    default:
        printf("\nInvalid Choice!");
        return;
    }

    if (SetFileAttributes(name, attrib) == 0)
    {
        perror("\nUnable to set attributes");
        return 1;
    }

    printf("\nFile attributes set successfully.\n");
    return 0;
}