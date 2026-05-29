#include <stdio.h>

int main()
{
    int bt[20], wt[20], tat[20];

    int n;

    float wtavg = 0;
    float tatavg = 0;

    printf("Enter number of processes: ");

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("Enter Burst Time for Process %d: ", i);

        scanf("%d", &bt[i]);
    }

    wt[0] = 0;

    tat[0] = bt[0];

    for(int i = 1; i < n; i++)
    {
        wt[i] = wt[i-1] + bt[i-1];

        tat[i] = wt[i] + bt[i];
    }

    printf("\nPROCESS\tBT\tWT\tTAT\n");

    for(int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\n",
        i, bt[i], wt[i], tat[i]);

        wtavg += wt[i];

        tatavg += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f",
    wtavg / n);

    printf("\nAverage Turnaround Time = %.2f",
    tatavg / n);

    return 0;
}