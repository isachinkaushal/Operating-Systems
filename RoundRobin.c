#include <stdio.h>

int z[10], b[10], n, m[50], r, q, e = 0, avg = 0, i, j;
float f;

void rr();
void average();

int main() {
    printf("\n\tJOB SCHEDULING ALGORITHM[RR]");
    printf("\n\t*******************************************************\n");

    printf("\nEnter how many jobs: ");
    scanf("%d", &n);

    printf("\nEnter burst time for corresponding job...\n");
    for (i = 1; i <= n; i++) {
        printf("\nProcess %d: ", i);
        scanf("%d", &b[i]);
        z[i] = b[i];
    }

    printf("\nENTER THE TIME SLICE VALUE: ");
    scanf("%d", &q);

    rr();
    average();

    return 0;
}

void rr() {
    int max = 0;
    max = b[1];

    for (j = 1; j <= n; j++) {
        if (max <= b[j])
            max = b[j];
    }

    if ((max % q) == 0)
        r = (max / q);
    else
        r = (max / q) + 1;

    for (i = 1; i <= r; i++) {
        printf("\nRound %d", i);
        for (j = 1; j <= n; j++) {
            if (b[j] > 0) {
                b[j] = b[j] - q;
                if (b[j] <= 0) {
                    b[j] = 0;
                    printf("\nProcess %d is completed", j);
                } else {
                    printf("\nProcess %d remaining time is %d", j, b[j]);
                }
            }
        }
    }
}

void average() {
    for (i = 1; i <= n; i++) {
        e = 0;
        for (j = 1; j <= r; j++) {
            if (z[i] != 0) {
                if (z[i] >= q) {
                    m[i + e] = q;
                    z[i] -= q;
                } else {
                    m[i + e] = z[i];
                    z[i] = 0;
                }
            } else {
                m[i + e] = 0;
            }
            e = e + n;
        }
    }

    for (i = 2; i <= n; i++) {
        for (j = 1; j <= i - 1; j++) {
            avg = avg + m[j];
        }
    }

    for (i = n + 1; i <= r * n; i++) {
        if (m[i] != 0) {
            for (j = i - (n - 1); j <= i - 1; j++) {
                avg = m[j] + avg;
            }
        }
    }

    f = (float)avg / n;

    printf("\nTOTAL WAITING TIME: %d", avg);
    printf("\n\nAVERAGE WAITING TIME: %f\n", f);

    printf("\nGantt Chart\n***************************************\n\n\t");
    for (i = 1; i <= r * n; i++) {
        if (m[i] != 0) {
            if (i % n == 0) {
                printf("P%d", (i % n) + n);
            } else {
                printf("P%d", i % n);
            }
            for (j = 1; j <= m[i]; j++) {
                printf("-");
            }
        }
    }
    printf("\n");
}