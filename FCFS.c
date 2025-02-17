#include <stdio.h>

int main()
{
    int n, b[10], w[10], i, j;
    float avg = 0;

    printf("\n\tJOB SCHEDULING ALGORITHM[FCFS]");
    printf("\n\t*****************************************************\n");

    printf("\nEnter how many jobs: ");
    scanf("%d", &n);

    printf("\nEnter burst time for corresponding job....\n");
    for (i = 0; i < n; i++)
    {
        printf("\nProcess %d: ", i + 1);
        scanf("%d", &b[i]);
    }

    w[0] = 0;
    printf("\nProcess 1 waiting time is 0");

    for (i = 1; i < n; i++)
    {
        w[i] = b[i - 1] + w[i - 1];
        printf("\nProcess %d waiting time: %d", i + 1, w[i]);
        avg += w[i];
    }

    printf("\nTotal waiting time: %f", avg);
    printf("\n\nThe average waiting time is: %f\n", avg / n);

    // Print Gantt Chart
    printf("\nGantt Chart\n***************************************\n\n\t");
    for (i = 0; i < n; i++)
    {
        printf("| P%d ", i + 1);
        for (j = 1; j <= b[i]; j++)
            printf("-");
    } 
    printf("|\n\t0");

    for (i = 0; i < n; i++)
    {
        printf("%*d", b[i] + 5, w[i] + b[i]);
    }

    printf("\n");
    return 0;
}