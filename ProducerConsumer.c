#include <stdio.h>
#include <stdlib.h>

void display(int c, int stack[]);

void main() {
    int ch, n, c1 = 0, c2 = 0, produce[23], consume[23];

    printf("\nEnter Stack Size: ");
    scanf("%d", &n);

    while (1) {
        printf("\n\tProducer Stack (Size: %d)\n\t~~", n);
        display(c1, produce);
        printf("\n\tConsumer Stack (Size: %d)\n\t~~", n);
        display(c2, consume);

        printf("\n\tCHOICES\n\t~\n\t1. Producer\n\t2. Consumer\n\t3. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                if (c1 == n) {
                    printf("\nProducer stack is FULL. So Producer goes to SLEEP.\n");
                } else {
                    printf("\tEnter PRODUCE item: ");
                    scanf("%d", &produce[c1]);
                    c1++;
                }
                break;

            case 2:
                if (c2 == n) {
                    printf("\nConsumer Stack is FULL. Resetting Consumer Stack...\n");
                    c2 = 0;
                } else if (c1 == 0) {
                    printf("\nProducer stack is EMPTY.\n");
                } else {
                    consume[c2] = produce[c1 - 1]; 
                    printf("\tConsumed one item: %d\n", consume[c2]);
                    c1--; 
                    c2++; 
                }
                break;

            case 3:
                exit(0);

            default:
                printf("\nInvalid choice, please enter a correct option!\n");
        }
    }
}

void display(int c, int stack[]) {
    printf("\n------------------------------------------------------\n");
    if (c == 0) {
        printf("\tStack is EMPTY (Sleeping)\n");
    } else {
        for (int i = 0; i < c; i++) {
            printf("\t%d", stack[i]);
        }
    }
    printf("\n------------------------------------------------------------------\n");
}