#include <stdio.h>
#include <stdbool.h>

struct Process {
    int pid;
    int burst_time;
    int priority;
    int arrival_time;
    int waiting_time;
    int turn_around_time;
    int remaining_burst_time;
};

void findWaitingTime(struct Process proc[], int n) {
    proc[0].waiting_time = 0;
    for (int i = 1; i < n; i++) {
        proc[i].waiting_time = proc[i - 1].waiting_time + proc[i - 1].burst_time;
    }
}

void findTurnAroundTime(struct Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turn_around_time = proc[i].burst_time + proc[i].waiting_time;
    }
}

void findAvgTime(struct Process proc[], int n) {
    int total_waiting_time = 0, total_turn_around_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += proc[i].waiting_time;
        total_turn_around_time += proc[i].turn_around_time;
    }
    printf("\nAverage waiting time: %.2f\n", (float)total_waiting_time / n);
    printf("Average turnaround time: %.2f\n", (float)total_turn_around_time / n);
}

void sortByArrivalTime(struct Process proc[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (proc[i].arrival_time > proc[j].arrival_time) {
                struct Process temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
}

void preemptivePriorityScheduling(struct Process proc[], int n) {
    int currentTime = 0;
    int completed = 0;
    bool processCompleted[n];
    for (int i = 0; i < n; i++) {
        processCompleted[i] = false;
        proc[i].remaining_burst_time = proc[i].burst_time;
    }

    int ganttChart[100], ganttIndex = 0;
    int ganttTime[100];

    while (completed < n) {
        int highestPriority = -1;
        int idx = -1;

        for (int i = 0; i < n; i++) {
            if (!processCompleted[i] && proc[i].arrival_time <= currentTime && 
                (highestPriority == -1 || proc[i].priority > proc[highestPriority].priority)) {
                highestPriority = i;
                idx = i;
            }
        }

        if (idx != -1) {
            ganttChart[ganttIndex] = proc[idx].pid;
            ganttTime[ganttIndex] = currentTime;
            currentTime++;
            proc[idx].remaining_burst_time--;

            if (proc[idx].remaining_burst_time == 0) {
                processCompleted[idx] = true;
                completed++;
            }
            ganttIndex++;
        } else {
            currentTime++;
        }
    }

    printf("\nGantt Chart: \n");
    for (int i = 0; i < ganttIndex; i++) {
        printf("| P%d ", ganttChart[i]);
    }
    printf("|\n");

    for (int i = 0; i < ganttIndex; i++) {
        printf("%d   ", ganttTime[i]);
    }
    printf("%d\n", currentTime);
}

void displayProcessInfo(struct Process proc[], int n) {
    printf("\nProcess Information:\n");
    printf("PID | Arrival Time | Burst Time | Priority | Waiting Time | Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d   | %d            | %d          | %d        | %d            | %d\n", 
            proc[i].pid, proc[i].arrival_time, proc[i].burst_time, proc[i].priority, 
            proc[i].waiting_time, proc[i].turn_around_time);
    }
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];

    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &proc[i].burst_time);
        printf("Enter priority for Process %d: ", i + 1);
        scanf("%d", &proc[i].priority);
        printf("Enter arrival time for Process %d: ", i + 1);
        scanf("%d", &proc[i].arrival_time);
    }

    sortByArrivalTime(proc, n);
    preemptivePriorityScheduling(proc, n);
    findWaitingTime(proc, n);
    findTurnAroundTime(proc, n);
    displayProcessInfo(proc, n);
    findAvgTime(proc, n);

    return 0;
}
