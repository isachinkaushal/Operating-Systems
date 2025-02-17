#include <stdio.h>

int main() {
    int n, b[10], w[10], a[10], at[10], i, j, t, tt;
    float avg = 0;

    printf("\n\tJOB SCHEDULING ALGORITHM[SJF]");
    printf("\n\t*****************************************************\n");

    printf("\nEnter how many jobs: ");
    scanf("%d", &n);

    printf("\nEnter arrival time and burst time for corresponding job....\n");
    for (i = 1; i <= n; i++) {
        printf("\nProcess %d arrival time: ", i);
        scanf("%d", &at[i]);
        printf("Process %d burst time: ", i);
        scanf("%d", &b[i]);
        a[i] = i;
    }

    // Sorting based on arrival times first, then burst times
    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            if (at[i] > at[j] || (at[i] == at[j] && b[i] > b[j])) {
                // Swap arrival times
                t = at[i];
                at[i] = at[j];
                at[j] = t;
                // Swap burst times
                t = b[i];
                b[i] = b[j];
                b[j] = t;
                // Swap process numbers
                tt = a[i];
                a[i] = a[j];
                a[j] = tt;
            }
        }
    }

    w[1] = 0;
    printf("\nProcess %d waiting time is 0", a[1]);

    for (i = 2; i <= n; i++) {
        w[i] = b[i - 1] + w[i - 1];
        if (w[i] < at[i]) {
            w[i] = at[i] - w[i];
        }
        printf("\nProcess %d waiting time: %d", a[i], w[i]);
        avg += w[i];
    }

    printf("\nTotal waiting time: %f", avg);
    printf("\n\nThe average waiting time is: %f\n", avg / n);

    // Print Gantt Chart
    printf("\nGantt Chart\n***************************************\n\n\t");
    int currentTime = 0;
    for (i = 1; i <= n; i++) {
        printf("| P%d ", a[i]);
        for (j = 1; j <= b[i]; j++)
            printf("-");
        currentTime += b[i];
    }
    printf("|\n\t0");

    currentTime = 0;
    for (i = 1; i <= n; i++) {
        currentTime += b[i];
        printf("%*d", b[i] + 5, currentTime);
    }

    printf("\n");
    return 0;
}

