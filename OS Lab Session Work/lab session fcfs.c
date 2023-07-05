#include <stdio.h>

struct Process {
    int processId;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};

void calculateTimes(struct Process processes[], int n) {
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        if (currentTime < processes[i].arrivalTime)
            currentTime = processes[i].arrivalTime;

        processes[i].completionTime = currentTime + processes[i].burstTime;
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;

        currentTime = processes[i].completionTime;
    }
}

void displayResults(struct Process processes[], int n) {
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].processId,
               processes[i].arrivalTime,
               processes[i].burstTime,
               processes[i].completionTime,
               processes[i].turnaroundTime,
               processes[i].waitingTime);
    }

    double averageTurnaroundTime = 0, averageWaitingTime = 0;

    for (int i = 0; i < n; i++) {
        averageTurnaroundTime += processes[i].turnaroundTime;
        averageWaitingTime += processes[i].waitingTime;
    }

    averageTurnaroundTime /= n;
    averageWaitingTime /= n;

    printf("\nAverage Turnaround Time: %.2lf\n", averageTurnaroundTime);
    printf("Average Waiting Time: %.2lf\n", averageWaitingTime);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        processes[i].processId = i + 1;
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrivalTime);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burstTime);
    }

    calculateTimes(processes, n);
    displayResults(processes, n);

    return 0;
}
