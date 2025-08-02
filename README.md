# Operating-System
FCFS:
#include <stdio.h>

int main() {
    int n, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n];
    float avg_tat = 0, avg_wt = 0;

    for (i = 0; i < n; i++) {
        printf("P%d Arrival Time: ", i+1);
        scanf("%d", &at[i]);
        printf("P%d Burst Time: ", i+1);
        scanf("%d", &bt[i]);
    }

    ct[0] = at[0] + bt[0];
    for (i = 1; i < n; i++) {
        ct[i] = (ct[i-1] > at[i]) ? ct[i-1] + bt[i] : at[i] + bt[i];
    }

    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    printf("P\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("Average TAT = %.2f\n", avg_tat/n);
    printf("Average WT = %.2f\n", avg_wt/n);
    return 0;
}
