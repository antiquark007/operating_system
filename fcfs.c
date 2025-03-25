#include<stdio.h>
int main(){
    int wt[20],bt[20],tat[20],at[20],ct[20],i,n,temp=0;
    float wtavg,tatavg;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("\nEnter arrival and burst time for process %d: ", i);
        scanf("%d %d", &at[i], &bt[i]);
    }
    temp=bt[0];
    ct[0]=bt[0];
    wt[0]=0;
    tat[0]=bt[0]-at[0];
    wtavg=0;
    tatavg=bt[0];
    for(i=1;i<n;i++){
        temp+=bt[i];
        ct[i]=temp;
        wt[i]=ct[i-1]-at[i];
        tat[i]=ct[i]-at[i];
        wtavg+=wt[i];
        tatavg+=tat[i];
    }
    wtavg /= n;
    tatavg /= n;
    
    printf("\n\tPROCESS\tARRIVAL_T\tBURST_T\tCOMPLETE_T\tWAITING_T\tTURN_AROUND_T\n");
    printf("\t-------\t---------\t-------\t----------\t---------\t--------------\n");
    for(i=0;i<n;i++){
        printf("\tP%d\t%9d\t%7d\t%10d\t%9d\t%14d\n", i, at[i], bt[i], ct[i], wt[i], tat[i]);
    }
    
    printf("\nGantt Chart:\n");
    for(i=0;i<n;i++){
        printf("P%d\t", i);
    }
    printf("\n");
    for(i=0;i<n;i++){
        printf("%d\t", ct[i]);
    }
    printf("\n");
    
    printf("\nAverage Waiting Time: %.2f\n", wtavg);
    printf("Average Turnaround Time: %.2f\n", tatavg);
    
    return 0;
}