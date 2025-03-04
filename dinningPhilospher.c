#include <stdio.h>
#include <stdlib.h>

#define NUM_PHILOSOPHERS 5

// Structure to hold philosopher information
typedef struct {
    int id;
    int right_fork;
    int left_fork;
} Philosopher;

Philosopher philosophers[NUM_PHILOSOPHERS];

void initialize_philosophers() {
    printf("\nPhilos name      Right fork     Left fork\n");
    printf("-------------------------------------------------------------------\n");
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        philosophers[i].id = i;
        philosophers[i].right_fork = i;
        philosophers[i].left_fork = (i + 1) % NUM_PHILOSOPHERS;
        printf("        %d               %d               %d\n", philosophers[i].id, philosophers[i].right_fork, philosophers[i].left_fork);
    }
    printf("--------------------------------------------------------------------\n");
}

void start_dinner(int first, int second) {
    int round = 1;
    while (round <= 3) {
        printf("Round %d\n", round);
        printf("--------------------------\n");

        if (round == 1) {
            printf("Philosopherre %d is eating with rhf=%d and  lhf=%d.\n", philosophers[first].id, philosophers[first].right_fork, philosophers[first].left_fork);
            printf("Philosopherre %d is eating with rhf=%d and lhf=%d.\n", philosophers[second].id, philosophers[second].right_fork, philosophers[second].left_fork);
        } else if (round == 2) {
            int next_first = (first + 4) % NUM_PHILOSOPHERS;
            int next_second = (second + 4) % NUM_PHILOSOPHERS;
            printf("Philosopherre %d is eating with rhf=%d and  lhf=%d.\n", philosophers[next_first].id, philosophers[next_first].right_fork, philosophers[next_first].left_fork);
            printf("Philosopherre %d is eating with rhf=%d and   lhf=%d.\n", philosophers[next_second].id, philosophers[next_second].right_fork, philosophers[next_second].left_fork);
        } else if (round == 3) {
            int next_first = (first + 1) % NUM_PHILOSOPHERS;
            int next_second = (second + 1) % NUM_PHILOSOPHERS;
            printf("Philosopherre %d is eating with rhf=%d and  lhf=%d.\n", philosophers[next_first].id, philosophers[next_first].right_fork, philosophers[next_first].left_fork);
            printf("Philosopherre %d is eating with rhf=%d and   lhf=%d.\n", philosophers[next_second].id, philosophers[next_second].right_fork, philosophers[next_second].left_fork);
        }

        round++;
    }
}

int main() {
    int first_philosopher, second_philosopher;

    initialize_philosophers();

    printf("Enter the Two Eating Philosophers number:");
    scanf("%d %d", &first_philosopher, &second_philosopher);

    start_dinner(first_philosopher, second_philosopher);

    return 0;
}