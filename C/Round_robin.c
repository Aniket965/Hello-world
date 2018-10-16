#include<stdio.h>

int main() {

    int TIME_QUANTUM;
    int n, burstTime[30], arrivalTime[30], remainingTime[30];
    int remainingProcs;
    float avgTurnaround = 0.000, avgWait = 0.000;
    int i, timeElapsed, flag; // timeElapsed is an interpretation of the actual clock in cpu

    printf("Enter the number of process :");
    scanf("%d", &n);
    printf("\n");

    printf("Enter the Time Quantum(ms) :");
    scanf("%d", &TIME_QUANTUM);

    for(i=0; i<n; i++) {
        printf("\nP[%d] Burst Time: ", i+1);
        scanf("%d", &burstTime[i]);
        printf("P[%d] Arrival Time: ", i+1);
        scanf("%d", &arrivalTime[i]);

        //initialise remaining time of each process as the burst time
        remainingTime[i] = burstTime[i];
    }

    remainingProcs = n;
    i = 0;
    timeElapsed = 0;

    while(remainingProcs!=0) {
        if(remainingTime[i] <= TIME_QUANTUM && remainingTime[i] >= 0) {
            timeElapsed += remainingTime[i];
            remainingTime[i] = 0;
            flag =1;
        }
        else if(remainingTime[i] > 0) {
            remainingTime[i] -= TIME_QUANTUM;
            timeElapsed += TIME_QUANTUM;
        }
        if(remainingTime[i] == 0 && flag==1) {
            remainingProcs--;
            printf("P[%d] : Turnaround Time: %d\t Waiting Time: %d", i+1, timeElapsed-arrivalTime[i], timeElapsed-arrivalTime[i]-burstTime[i]);
            avgWait += timeElapsed - arrivalTime[i] - burstTime[i];
            avgTurnaround += timeElapsed - arrivalTime[i];
            flag = 0;
        }
        if(i==n-1)
            i = 0;
        else if(arrivalTime[i+1] <= timeElapsed)
            i++;
        else
            i = 0;
    }

    printf("\n\nAverage Waiting Time : %f\n Average Turnaround Time : %f", avgWait, avgTurnaround);
    
    return 0;
}