#include <stdio.h>

int main() {
    int n, i, at[20], bt[20], wt[20] = {0}, ct[20], tat[20];
    float wtavg = 0, tatavg = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter arrival and burst time for process %d: ", i);
        scanf("%d %d", &at[i], &bt[i]);
    }

    ct[0] = bt[0];
    tat[0] = ct[0] - at[0];
    wt[0] = 0;


    for (i = 1; i < n; i++) {
        ct[i] = ct[i - 1] + bt[i];  // Completion time
        wt[i] = ct[i - 1] - at[i];  // Waiting time
        tat[i] = ct[i] - at[i];     // Turnaround time
        wtavg += wt[i];
        tatavg += tat[i];
    }

    wtavg /= n;
    tatavg = (tatavg + tat[0]) / n; 

    printf("\n\tPROCESS\tARRIVAL_T\tBURST_T\tCOMPLETE_T\tWAITING_T\tTURN_AROUND_T\n");
    for (i = 0; i < n; i++) {
        printf("\tP%d\t%9d\t%7d\t%10d\t%9d\t%14d\n", i, at[i], bt[i], ct[i], wt[i], tat[i]);
    }

    printf("\nGantt Chart:\n");
    for (i = 0; i < n; i++) printf("P%d\t", i);
    printf("\n");
    for (i = 0; i < n; i++) printf("%d\t", ct[i]);
    printf("\n");

    printf("\nAverage Waiting Time: %.2f\n", wtavg);
    printf("Average Turnaround Time: %.2f\n", tatavg);

    return 0;
}
