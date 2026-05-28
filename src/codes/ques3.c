#include <stdio.h>

int main()
{
    int bt[10], wt[10], tat[10], n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst times:\n");

    for(int i=0;i<n;i++){
        scanf("%d", &bt[i]);
    }

    wt[0] = 0;

    for(int i=1;i<n;i++){
        wt[i] = wt[i-1] + bt[i-1];
    }

    for(int i=0;i<n;i++){
        tat[i] = wt[i] + bt[i];
    }

    printf("\nBT\tWT\tTAT\n");

    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\n",
        bt[i], wt[i], tat[i]);
    }

    return 0;
}